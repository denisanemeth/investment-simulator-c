#ifndef INVESTMENT_FUNC_H
#define INVESTMENT_FUNC_H
typedef struct{
    double initial;
    double rate;
    double monthly,inflation;
    int years,show_chart,export_csv;
    char csv_file[256];
}simconfig;
typedef struct{
    char name[50]; //pt diferite scenarii optimist,pesimist,realist.
    double rate,inflation;
}scenario;
typedef struct{
    int year; //sa pastram valorile salvate
    double value,realValue;
    double interest_earned;
}year_data;
double compound_interest(double principal,double rate,int years);
double compound_with_contributions(double initial, double monthly, double rate, int years);
double adjust_for_inflation(double amount,double inflation_rate,int years);
double compute_roi(double invested,double final);
int find_breakeven_years(double initial,double monthly,double rate);
void simulate_scenario(simconfig *cfg, scenario *sc, year_data results[]);
void compare_rates(simconfig *cfg, double rates[], int num_rates);
double monte_carlo_simulation(simconfig *cfg, int num_sim, double min_rate, double max_rate);


#endif