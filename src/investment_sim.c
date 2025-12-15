#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "investment_func.h"


int main(int argc,char*argv[]) {
    simconfig cfg = {
    .initial = 10000.0,      
    .monthly = 0.0,          
    .rate = 0.07,            
    .inflation = 0.03,       
    .years = 10,             
    .show_chart = 0,         
    .export_csv = 0       
};
strcpy(cfg.csv_file, "results.csv");
    int show_chart=0;
    int export_csv=0;
    int compare_mode=0;
    int monte_carlo=0;
    int num_scenarios=1000;
    double min_rate=0.04,max_rate=0.08;
    double compare_ratess[10];
    int num_compare_rates=0;
    //parsare argumente linie comanda
    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"--initial")==0&&i+1<argc){
            cfg.initial=atof(argv[++i]);
        }
        else if(strcmp(argv[i],"--monthly")==0&&i+1<argc){
            cfg.monthly=atof(argv[++i]);
        }
        else if(strcmp(argv[i],"--rate")==0&&i+1<argc){
            cfg.rate=atof(argv[++i]);
        }
        else if(strcmp(argv[i],"--inflation")==0&&i+1<argc){
            cfg.inflation=atof(argv[++i]);
        }
        else if(strcmp(argv[i],"--years")==0&&i+1<argc){
            cfg.years=atof(argv[++i]);
        }
        else if(strcmp(argv[i],"--chart")==0&&i+1<argc){
            show_chart=1;

        }
        else if(strcmp(argv[i],"--export")==0&&i+1<argc){
           export_csv=1;
           strcpy(cfg.csv_file,argv[++i]);
        }
        else if(strcmp(argv[i],"--compare")==0&&i+1<argc){
            compare_mode=1;
            i++;
            char*token=strtok(argv[i],",");
            while(token!=NULL&&num_compare_rates<10){
                compare_ratess[num_compare_rates++]=atof(token);
                token=strtok(NULL,",");
            }
        }
        else if(strcmp(argv[i],"--scenarios")==0&&i+1<argc){
            monte_carlo=1;
            num_scenarios=atoi(argv[++i]);
        }
        else if(strcmp(argv[i],"--rate_range")==0&&i+1<argc){
            i++;
            sscanf(argv[i],"%lf-%lf",&min_rate,&max_rate);
        }
       
        }
        //executie simulare in functie de argumente
        if(compare_mode){
            compare_rates(&cfg,compare_ratess,num_compare_rates);
            return 0;
        }
        if(monte_carlo){
            printf("\n=== Simulare Monte Carlo ===\n");
            printf("Numar simulari: %d\n", num_scenarios);
            printf("Interval rate: %.2f%% - %.2f%%\n", min_rate*100, max_rate*100);
            double avg = monte_carlo_simulation(&cfg, num_scenarios, min_rate, max_rate);
            printf("Valoare finala medie: %.2f RON\n", avg);
             return 0;

    }
    printf("\n=== Simulare Investitie ===\n");
    printf("Suma initiala: %.2f RON\n", cfg.initial);
    printf("Contributie lunara: %.2f RON\n", cfg.monthly);
    printf("Rata dobanda: %.2f%%\n", cfg.rate * 100);
    printf("Inflatie: %.2f%%\n", cfg.inflation * 100);
    printf("Perioada: %d ani\n\n", cfg.years);
   //alocare rezultate
   year_data*results=malloc(sizeof(year_data)*(cfg.years+1));
   if(!results){
    printf("Eroare alocare memorie pt rezultate\n");
    return 1;
   }
   scenario optimist = {"Optimist", cfg.rate + 0.03,
     cfg.inflation - 0.01};
   scenario realist = {"Realist", cfg.rate, 
    cfg.inflation};
   scenario pesimist = {"Pesimist", cfg.rate - 0.03, 
    cfg.inflation + 0.01};
    simulate_scenario(&cfg, &realist, results);//scenariu realist
    double total_invested=cfg.initial+cfg.monthly*12*cfg.years;
    double final_value=results[cfg.years].value;
    double roi=compute_roi(total_invested,final_value);
    int breakeven_years=find_breakeven_years(cfg.initial,cfg.monthly,cfg.rate);
    printf("\nRezultate finale:\n");
    printf("total investit: %.2f RON\n", total_invested);
    printf("valoare finala: %.2f RON\n", final_value);
    printf("ROI: %.2f%%\n", roi * 100);
    if(breakeven_years!=-1){
        printf("breakeven atins in: %d ani\n", breakeven_years);
    }
    if(show_chart){
        draw_chart(results,cfg.years);
    }
    if(export_csv){
        export_to_csv(cfg.csv_file,results,cfg.years);
    }
    //celalalte scenarii
    printf("Scenarii alternative------\n");
    year_data*temp=malloc(sizeof(year_data)*(cfg.years+1));
   simulate_scenario(&cfg,&optimist,temp);
   printf("scenariu optimist final: %.2f RON\n",temp[cfg.years].value);
    simulate_scenario(&cfg,&pesimist,temp);
    printf("scenariu pesimist final: %.2f RON\n",temp[cfg.years].value);
    free(temp);
    free(results);
    return 0;



}
    
