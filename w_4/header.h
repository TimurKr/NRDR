//
// Created by Timur Kramar on 06/03/2023.
//

#ifndef W_4_HEADER_H
#define W_4_HEADER_H

#endif //W_4_HEADER_H

#include <stdio.h>
#include <math.h>

double f1(double x) {
    return 10*x;
}

double f2(double x) {
    return 1/ (2*x);
}

double f3(double x, double t) {
    return t * x;
}


double approximate_a(int n, int print) {
    char filename[100];
    FILE *f;
    if (print) {
        sprintf(filename, "../outputs/uloha1/a_%dn.csv", (int) n);
        f = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return -1;
        }
    }

    double t0 = 0;
    double t1 = 1;
    double h = (t1 - t0) / n;
    double u_i = 1;
    for (int i = 0; i < n; i++) {
        if (print) {
            fprintf(f, "%f, %f\n", t0 + i * h, u_i);
        }
        u_i = u_i + h * f1(u_i);
    }
    if (print) {

        fprintf(f, "%f, %f\n", t1, u_i);
        fclose(f);
    }
    return u_i;
}

double approximate_b(int n, int print) {
    char filename[100];
    FILE *f;
    if (print) {

        sprintf(filename, "../outputs/uloha1/b_%dn.csv", (int) n);
        f = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return -1;
        }
    }

    double t0 = 0.0001;
    double t1 = 1.0001;
    double h = (t1 - t0) / n;
    double u_i = 0.01;
    for (int i = 0; i < n; i++) {
        if (print) {
            fprintf(f, "%f, %f\n", t0 + i * h, u_i);
        }
        u_i = u_i + h * f2(u_i);
    }
    if (print) {
        fprintf(f, "%f, %f\n", t1, u_i);
        fclose(f);
    }
    return u_i;
}

double approximate_c(int n, int print) {
    char filename[100];
    FILE *f;
    if (print) {
        sprintf(filename, "../outputs/uloha1/c_%dn.csv", (int) n);
        f = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return -1;
        }
    }

    double t0 = 1;
    double t1 = 2;
    double h = (t1 - t0) / n;
    double u_i = 1;
    for (int i = 0; i < n; i++) {
        if (print) {
            fprintf(f, "%f, %f\n", t0 + i * h, u_i);
        }
        u_i = u_i + h * f3(u_i, t0 + i * h);
    }
    if (print) {
        fprintf(f, "%f, %f\n", t1, u_i);
        fclose(f);
    }
    return u_i;
}
