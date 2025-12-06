#include "investment_func.h"
#include <math.h>
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