#include "investment_func.h"
#include <math.h>
double compound_interest(double principal,double rate,int years){
    return principal*pow(1+rate,years);
}