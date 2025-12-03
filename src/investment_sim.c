#include <stdio.h>
#include "investment_func.h"


int main() {
    double result = compound_interest(1000, 0.05, 10);

    printf("result:%.2f...\n",result);
    return 0;
}