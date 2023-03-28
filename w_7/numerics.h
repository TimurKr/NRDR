//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_HEADERS_H
#define W_7_HEADERS_H

#endif //W_7_HEADERS_H

#include <stdio.h>

double explicit_euler(
        double (*f)(double),
        double u0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print) {
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return -1;
        }
    }

    double h = (t1 - t0)/n;
    double u_i = u0;
    for (int i = 0; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", t0 + h * i, u_i);
        }
        u_i = u_i + h*f(u_i);
    }

    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}

double explicit_taylor_2(
        double (*f)(double),
        double (*d_f)(double),
        double u0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print) {
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return -1;
        }
    }

    double h = (t1 - t0)/n;
    double u_i = u0;
    for (int i = 0; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", t0 + h*i, u_i);
        }
        u_i = u_i + h*f(u_i) + h*h/2*d_f(u_i) * f(u_i);
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}