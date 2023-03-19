//
// Created by Timur Kramar on 06/03/2023.
//

#include "header.h"

int main(){
    double correct = 22026.5;
    double calculated;
    double E = 1;
    double last_E;
    double E_ratio;
    double EOC;
    for (int n=1; n<=100000; n *= 2) {
        calculated = approximate_a(n, 0);
        last_E = E;
        E = fabs(correct - calculated);
        E_ratio = last_E / E;
        EOC = log2f(E_ratio);
        printf("\nn=%d\ncorrect = %f\ncalculated = %f\nlast_E = %f\nE = %f\nEOC = %f\n",
               n,
               correct,
               calculated,
               last_E,
               E,
               EOC);
        //printf("n=%d, EOC=%f\n", n, EOC);
    }
}