#include <stdio.h>
#include "investment_func.h"


int main() {
    double result = compound_interest(1000, 0.05, 10);
    double result2=compound_with_contributions(1000,100,0.05,10);
    printf("result:%.2f,result 2:%.2f...\n",result,result2);
    return 0;
}