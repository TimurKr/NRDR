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

long double EOC_w_method(
        double (*method)(double (*f) (double),
                         unsigned int init_method, double u0,
                         double t0, double t1,
                         int n,
                         char *file_prefix,
                         unsigned int print),
        double(*f) (double),
        double correct,
        double u0, unsigned int init_method,
        double t0, double t1,
        int n) {
    return log2l(
            fabs(correct - method(f, init_method, u0, t0, t1, (int) (n / 2. + 0.5), "", 0)) /
            fabs(correct - method(f, init_method, u0, t0, t1, n, "", 0)));
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
    return log2l(
            fabs(correct - method(f, df, u0, t0, t1, (int) (n / 2. + 0.5), "", 0)) /
            fabs(correct - method(f, df, u0, t0, t1, n, "", 0)));
}

long double EOC_w_ddf(
        double (*method)(double (*f) (double),
                         double (*df) (double),
                         double (*ddf) (double),
                         double u0,
                         double t0, double t1,
                         int n,
                         char *file_prefix,
                         unsigned int print),
        double(*f) (double),
        double(*df) (double),
        double(*ddf) (double),
        double correct,
        double u0,
        double t0, double t1,
        int n) {
    return log2l(
            fabs(correct - method(f, df, ddf, u0, t0, t1, (int) (n / 2. + 0.5), "", 0)) /
            fabs(correct - method(f, df, ddf, u0, t0, t1, n, "", 0)));
}

double EOC_f_d(
        double* (*method)(double (*f)(double),
                         double t0, double t1,
                         double u0, double u1,
                         int n,
                         char *file_prefix, unsigned int print),
        double(*f) (double),
        double(*f_result) (double),
        double t0, double t1,
        double u0, double u1,
        int n, int p) {
    double h = (t1 - t0) / (n+1);

    double *results = method(f, t0, t1, u0, u1, n, "", 0);

    double E_size = 0;

    for (int i = 0; i < n; ++i) {
        E_size += h * pow(fabs(f_result(t0 + (i+1) * h) - results[i]), p);
    }
    E_size = pow(E_size, 1. / p);

    n *= 2;
    h = (t1 - t0) / (n + 1);

    results = method(f, t0, t1, u0, u1, n, "", 0);
    double E_size_2 = 0;

    for (int i = 0; i < n; ++i) {
        E_size_2 += h * pow(fabs(f_result(t0 + (i+1) * h) - results[i]), p);
    }
    E_size_2 = pow(E_size_2, 1. / p);

    return log2l(E_size / E_size_2);
}

double EOC_f_d_neumann(
        double* (*method)(double (*f)(double),
                          double t0, double t1,
                          double d0, double u1,
                          int n,
                          char *file_prefix, unsigned int print),
        double(*f) (double),
        double(*f_result) (double),
        double t0, double t1,
        double d0, double u1,
        int n, int p) {
    double h = (t1 - t0) / (n);

    double *results = method(f, t0, t1, d0, u1, n, "", 0);

    double E_size = 0;

    for (int i = 0; i <= n; ++i) {
        E_size += h * pow(fabs(f_result(t0 + (i+1) * h) - results[i]), p);
    }
    E_size = pow(E_size, 1. / p);

    n *= 2;
    h = (t1 - t0) / (n + 1);

    results = method(f, t0, t1, d0, u1, n, "", 0);
    double E_size_2 = 0;

    for (int i = 0; i <= n; ++i) {
        E_size_2 += h * pow(fabs(f_result(t0 + (i+1) * h) - results[i]), p);
    }
    E_size_2 = pow(E_size_2, 1. / p);

    return log2l(E_size / E_size_2);
}
