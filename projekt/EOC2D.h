//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_EOC_H
#define W_7_EOC_H

#endif //W_7_EOC_H

#include <stdio.h>
#include <math.h>


double EOC(
        double* (*method)(
                double (*x)(double, double),
                double (*y)(double, double),
                double x0, double y0,
                double t0, double t1,
                int n,
                char *file_prefix, unsigned int print),
        double(*x) (double, double),
        double(*y) (double, double),
        double correct_x, double correct_y,
        double x0, double y0,
        double t0, double t1,
        int n) {
    double* results_1 = method(x, y, x0, y0, t0, t1, n, "", 0);
    double* results_2 = method(x, y, x0, y0, t0, t1, 2*n, "", 0);

    return log2l(
            (fabs(correct_x - results_1[0]) + fabs(correct_y - results_1[1])) /
            (fabs(correct_x - results_2[0]) + fabs(correct_y - results_2[1]))
            );

}
