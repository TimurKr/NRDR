//
// Created by Timur Kramar on 13/03/2023.
//

#ifndef W_5_HEADERS_H
#define W_5_HEADERS_H

#endif //W_5_HEADERS_H

#include <stdio.h>
#include <math.h>

double F1(double x) {
    return pow(x, 4)/4+ pow(x,2) - 3;
}

double d_F1(double x) {
    return pow(x,3) + 2*x;
}

double F2(double x) {
    return (x+1) * exp(-x-1);
}

double d_F2(double x) {
    return -x*exp(-x-1);
}

double f(double x) {
    return x*x + 1;
}

double d_f(double x) {
    return 2*x;
}

double root_bisect(double a, double b, double (*F)(double), double eps) {
    double c = (a+b)/2;

    printf("a = %.4lf   \tc=%.4lf   \tb=%.4lf   \n", a,c,b);
    printf("F(a) = %.4lf\tF(c)=%.4lf\tf(b)=%.4lf\n\n", F(a),F(c), F(b));

    if (fabs(F(c)) < eps) return c;

    if ((F(a) * F(c)) < 0) return root_bisect(a, c, F, eps);

    if (F(b) * F(c) < 0) return root_bisect(b, c, F, eps);

}

double root_newton(double x0, double (*F)(double), double (*d_F)(double), double eps) {

    printf("x_i=%.5lf\t\tF(x_i)=%.5lf\n", x0, F(x0));

    if (fabs(F(x0)) < eps) return x0;

    if (fabs(d_F(x0)) < 0.000000001) return x0;

    return root_newton(x0 - F(x0)/d_F(x0), F, d_F, eps);
}

double implicit_euler_newton(double x0, double ui, double (*F)(double), double (*d_F)(double), double h, double eps) {

    printf("x_i=%.5lf\t\tF(x_i)=%.5lf\n", x0, x0 - h*F(x0) - ui);

    double f_i = x0 - h*F(x0) - ui;
    double d_f_i = 1 - h*d_F(x0);

    if (fabs(f_i) < eps) return x0;

    if (fabs(d_f_i) < 0.000000001) return x0;

    return implicit_euler_newton(x0 - (f_i)/d_f_i, ui, F, d_F, h, eps);
}

double implicit_euler(double (*f)(double), double(*d_f)(double), double u0, double t0, double t1, int n) {
    char filename[100];
    FILE *file;
    sprintf(filename, "../outputs/uloha3_%dn.csv", (int) n);
    file = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    double h = (t1 - t0)/n;
    double u_i = u0;
    for (int i = 0; i<n; i++) {
        fprintf(file, "%lf, %lf\n", t0 + h*i, u_i);
        u_i = implicit_euler_newton(u_i, u_i, f, d_f, h, 0.000001);
    }
    fclose(file);
    return u_i;
}