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
        double (*f)(double),double (*df)(double),
        double u0,double t0, double t1,int n,
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
        u_i =
            u_i +
            (h)         *   (f(u_i)) +
            (h*h/2)     *   (df(u_i)*f(u_i));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}

double explicit_taylor_3(
        double (*f)(double), double (*df)(double), double (*ddf)(double),
        double u0, double t0, double t1, int n,
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
        u_i =
            u_i +
            (h)         *   (f(u_i)) +
            (h*h/2)     *   (df(u_i)*f(u_i)) +
            (h*h*h/6)   *   (ddf(u_i)*f(u_i)*f(u_i) + df(u_i)*df(u_i)*f(u_i));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}

double RK2(
        double (*f)(double),
        double u0, double t0, double t1, int n,
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
        u_i = u_i + h*f(u_i + (h/2)*f(u_i));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}

double RK4(
        double (*f)(double),
        double u0, double t0, double t1, int n,
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
        double y1 = u_i;
        double y2 = u_i + (h/2)*f(y1);
        double y3 = u_i + (h/2)*f(y2);
        double y4 = u_i + h*f(y3);
        u_i = u_i + (h/6)*(f(y1) + 2*f(y2) + 2*f(y3) + f(y4));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}

double heun(
        double (*f)(double),
        double u0, double t0, double t1, int n,
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
        u_i = u_i + (h/2)*(f(u_i) + f(u_i + h*f(u_i)));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1, u_i);
        fclose(file);
    }
    return u_i;
}

double nystrom(
        double (*f)(double),
        double u0, double t0, double t1, int n,
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
    double u_i[2] = {u0, u0 + h*f(u0)};
    for (int i = 2; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", t0 + h*(i-2), u_i[0]);
        }
        double tmp = u_i[0] + 2*h*f(u_i[1]);
        u_i[0] = u_i[1];
        u_i[1] = tmp;
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1-h, u_i[0]);
        fprintf(file, "%lf, %lf\n", t1, u_i[1]);
        fclose(file);
    }
    return u_i[1];
}


double adam_bash(
        double (*f)(double),
        double u0, double t0, double t1, int n,
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
    double u_i[2] = {u0, u0 + h*f(u0)};
    for (int i = 2; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", t0 + h*(i-2), u_i[0]);
        }
        double tmp = u_i[1] + (h/2)*(-f(u_i[0]) + 3*f(u_i[1]));
        u_i[0] = u_i[1];
        u_i[1] = tmp;
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1-h, u_i[0]);
        fprintf(file, "%lf, %lf\n", t1, u_i[1]);
        fclose(file);
    }
    return u_i[1];
}