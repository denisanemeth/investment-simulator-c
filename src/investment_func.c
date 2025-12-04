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
