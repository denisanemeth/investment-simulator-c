#include "investment_func.h"
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double compound_interest(double principal,double rate,int years){
    return principal*pow(1+rate,years);
}
double compound_with_contributions(double initial, double monthly, double rate, int years) {
    double amount = initial;
    int months = years * 12;
    double monthly_rate = pow(1 + rate, 1.0/12) - 1;

    for (int i = 0; i < months; i++) {
        amount = amount * (1 + monthly_rate) + monthly;
    }
    return amount;
}
double adjust_for_inflation(double amount,double inflaton_rate,int years){
    return amount/pow(1+inflaton_rate,years);
}
double compute_roi(double invested,double final){
    return (final-invested)/invested;
}
int find_breakeven_years(double initial,double monthly,double rate){
    double amount=initial;
    double invested=initial;
    double monthly_rate=pow(1+rate,1.0/12)-1;
    for(int i=1;i<=50;i++){
        for(int m=0;m<12;m++){
            invested+=monthly;
            amount=amount*(1+monthly_rate)+monthly;

        }
        if(amount>=invested){
            return i;
        }
    }
    return -1;
}
void simulate_scenario(simconfig*cfg,scenario*sc,year_data result[]){
    printf("\n===Simulare scenariu:%s===\n",sc->name);
    printf("Parametrii:Investitie=%.2f,Lunar=%.2f, Dobanda=%.2f%%, Inflatie=%.2f%%\n",cfg->initial,cfg->monthly,
    sc->rate*100,sc->inflation*100);
    printf("----------------\n");
    printf("AN   |VALOARE NOMINALA   |VALOARE REALA   |DOBANDA\n");
    printf("-----------------\n");
    double crr_val=cfg->initial;
    double total_invested=cfg->initial;
    for(int yr=0;yr<=cfg->years;yr++){
        result[yr].year=yr;
        result[yr].value=crr_val;
        result[yr].realValue=crr_val/pow(1+sc->inflation,(double)yr);
        result[yr].interest_earned=crr_val-total_invested;
        printf("%2d  │  %15.2f RON │  %13.2f RON │  +%.2f RON\n",yr,result[yr].value,result[yr].realValue,
        result[yr].interest_earned);
        if(yr<cfg->years){
            crr_val+=cfg->monthly*12.0;
            total_invested+=cfg->monthly*12.0;
            crr_val*=(1.0+sc->rate);
        }
    }
    printf("----------------");
}
void compare_rates(simconfig*cfg,double rates[],int numRates){
    printf("\n--- Comparatie Rate de Dobanda ---\n");
    printf("Investitie initiala: %.2f RON\n", cfg->initial);
    printf("Contributii lunare: %.2f RON\n", cfg->monthly);
    printf("Perioada: %d ani\n", cfg->years);
    printf("---------------------------\n");
    double total_invested=cfg->initial+(cfg->monthly*12*cfg->years);
    printf("RATA   |VALOARE FINALA   |PROFIT NET   |ROI\n");
    printf("---------------------------\n");
    for(int i=0;i<numRates;i++){
        double finalVal=compound_with_contributions(cfg->initial,cfg->monthly,
        rates[i],cfg->years);
        double profit=finalVal-total_invested;
        double roi=compute_roi(total_invested,finalVal);
        printf("%.2f%% │  %13.2f RON │  %10.2f RON │  %6.2f\n",rates[i]*100,finalVal,profit,roi);

    }
    printf("---------------------\n");

}
void draw_chart(year_data results[],int years){
    double max_value=0;
    for(int i=0;i<=years;i++){
        if(results[i].value>max_value){
            max_value=results[i].value;
        }
    }
    if(max_value<=0){
        printf("Nu exista date valide pentru grafic\n");
        return;
    }
    int max_width=50;
    double scale=(double)max_width/max_value;
    printf("\n===grafic investitie===\n");
    for(int i=0;i<=years;i++){
       
      
        int bars=(int)(results[i].value*scale);
          if(bars<1)bars=1;
        printf("Anul %2d: ",results[i].year);
        for(int j=0;j<bars;j++){
            printf("#");
        }
        printf("\n");
    }

}
int export_to_csv(const char*filename,year_data results[],int years){
   FILE *f=fopen(filename,"w");
   if(!f){
    printf("Eroare la deschiderea fisierului!\n");
    return -1;
   } 
   fprintf(f,"An,Valoare Nominala,Valoare reala,Dobanda castigata\n");
   for(int i=0;i<=years;i++){
    fprintf(f,"%d,%.2f,%.2f,%.2f\n",results[i].year,results[i].value,results[i].realValue,results[i].interest_earned);
   
   }
 
    fclose(f);
    printf("Datele au fost exportate cu succes in %s\n",filename);
    return 0;
   

}