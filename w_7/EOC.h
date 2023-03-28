//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_EOC_H
#define W_7_EOC_H

#endif //W_7_EOC_H

#include <stdio.h>
#include <math.h>

long double EOC(
        double (*method)(double (*f) (double),
                                  double u0,
                                  double t0, double t1,
                                  int n,
                                  char *file_prefix,
                                  unsigned int print),
        double(*f) (double),
        double correct,
        double u0,
        double t0, double t1,
        int n) {
    return log2l(
            fabs(correct - method(f, u0, t0, t1, (int) (n / 2. + 0.5), "", 0)) /
            fabs(correct - method(f, u0, t0, t1, n, "", 0)));
}

long double EOC_w_df(
        double (*method)(double (*f) (double),
                         double (*df) (double),
                         double u0,
                         double t0, double t1,
                         int n,
                         char *file_prefix,
                         unsigned int print),
        double(*f) (double),
        double(*df) (double),
        double correct,
        double u0,
        double t0, double t1,
        int n) {
    double calculated = method(f, df, u0, t0, t1, n, "", 0);
    double calculated_before = method(f, df, u0, t0, t1, (int) (n / 2. + 0.5), "", 0);
    double error = fabs(correct - calculated);
    double error_before = fabs(correct - calculated_before);
    double EOC = log2(error_before / error);
    double all_in_one = log2(fabs(correct - method(f, df, u0, t0, t1, (int) (n / 2. + 0.5), "", 0)) / fabs(correct - method(f, df, u0, t0, t1, n, "", 0)));
    return log2l(
            fabs(correct - method(f, df, u0, t0, t1, (int) (n / 2. + 0.5), "", 0)) /
            fabs(correct - method(f, df, u0, t0, t1, n, "", 0)));
}
