#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "investment_func.h"


int main() {
    simconfig cfg;
    cfg.initial = 10000.0;
    cfg.rate = 0.07;
    cfg.monthly = 200.0;
    cfg.inflation = 0.02;
    cfg.years = 10;
    cfg.show_chart = 0;
    cfg.export_csv = 0;
    cfg.csv_file[0] = '\0';

   
    double rates[] = {0.05, 0.07, 0.10};
    compare_rates(&cfg, rates, 3);

   
    scenario sc;
    strncpy(sc.name, "Realist", sizeof(sc.name)-1);
    sc.name[sizeof(sc.name)-1] = '\0';
    sc.rate = 0.07;
    sc.inflation = 0.02;

    year_data *results = malloc(sizeof(year_data) * (cfg.years + 1));
    if (!results) {
        printf("Memory allocation failed\n");
        return 1;
    }

    simulate_scenario(&cfg, &sc, results);
    free(results);

   
    int be = find_breakeven_years(cfg.initial, cfg.monthly, cfg.rate);
    printf("\nBreak-even year: %d\n", be);

    return 0;
    
}