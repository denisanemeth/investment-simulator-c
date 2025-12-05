#ifndef INVESTMENT_FUNC_H
#define INVESTMENT_FUNC_H
double compound_interest(double principal,double rate,int years);
double compound_with_contributions(double initial, double monthly, double rate, int years);
double adjust_for_inflation(double amount,double inflation_rate,int years);

#endif