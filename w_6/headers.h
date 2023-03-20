//
// Created by Timur Kramar on 20/03/2023.
//

#ifndef W_6_HEADERS_H
#define W_6_HEADERS_H

#endif //W_6_HEADERS_H

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x + 1;
}

double d_f(double x) {
    return 2 * x;
}

double f2(double x) {
    return -100 * x;
}

double d_f2(double x) {
    return -100;
}

double explicit_euler(double (*f)(double), double u0, double t0, double t1, int n, char *file_prefix) {
    char filename[100];
    FILE *file;
    sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
    file = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    double h = (t1 - t0)/n;
    double u_i = u0;
    for (int i = 0; i<n; i++) {
        fprintf(file, "%lf, %lf\n", t0 + h*i, u_i);
        u_i = u_i + h*f(u_i);
    }
    fclose(file);
}


double implicit_euler_newton(double x0, double ui, double (*F)(double), double (*d_F)(double), double h, double eps, int i) {

    printf("x_i=%.5lf\t\tF(x_i)=%.5lf\n", x0, x0 - h*F(x0) - ui);

    if (i > 100) return x0;

    double f_i = x0 - h*F(x0) - ui;
    double d_f_i = 1 - h*d_F(x0);

    if (fabs(f_i) < eps) return x0;

    if (fabs(d_f_i) < 0.000000001) return x0;

    return implicit_euler_newton(x0 - (f_i)/d_f_i, ui, F, d_F, h, eps, i+1);
}

double implicit_euler(double (*f)(double), double(*d_f)(double), double u0, double t0, double t1, int n, char *file_prefix) {
    char filename[100];
    FILE *file;
    sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
    file = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    double h = (t1 - t0)/n;
    double u_i = u0;
    for (int i = 0; i<n; i++) {
        fprintf(file, "%lf, %lf\n", t0 + h*i, u_i);
        u_i = implicit_euler_newton(u_i, u_i, f, d_f, h, 0.000001, 1);
    }
    fclose(file);
    return u_i;
}


double trapezoid_euler_newton(double x0, double ui, double (*F)(double), double (*d_F)(double), double h, double eps, int i) {

    //printf("x_i=%.5lf\t\tF(x_i)=%.5lf\n", x0, x0 - h*F(x0) - ui);

    if (i > 100) return x0;

    double f_i = x0 - h*F(x0)/2 - ui - h*F(ui)/2;
    double d_f_i = 1 - h*d_F(x0)/2;

    if (fabs(f_i) < eps) return x0;

    if (fabs(d_f_i) < 0.000000001) return x0;

    return trapezoid_euler_newton(x0 - (f_i)/d_f_i, ui, F, d_F, h, eps, i+1);
}

double trapezoid_euler(double (*f)(double), double(*d_f)(double), double u0, double t0, double t1, int n, char *file_prefix) {
    char filename[100];
    FILE *file;
    sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
    file = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    double h = (t1 - t0)/n;
    double u_i = u0;
    for (int i = 0; i<n; i++) {
        fprintf(file, "%lf, %lf\n", t0 + h*i, u_i);
        u_i = trapezoid_euler_newton(u_i, u_i, f, d_f, h, 0.000001, 1);
    }
    fclose(file);
    return u_i;
}