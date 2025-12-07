#include <stdio.h>
#include "investment_func.h"


int main() {
    double result = compound_interest(1000, 0.05, 10);
    double result2=compound_with_contributions(1000,100,0.05,10);
    double ajustare=adjust_for_inflation(2000,0.02,5);
    double roi=compute_roi(1500,2500);
    int breakeven=find_breakeven_years(1000,100,0.05);
    printf("result:%.2f,result 2:%.2f...\n,ajustare inflatie:%.2f/ncompute roi:%.2f /nfind breakeven y:%d",result,result2,ajustare,roi,breakeven);
    return 0;
    
}