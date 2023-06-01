//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_HEADERS_H
#define W_7_HEADERS_H

#endif //W_7_HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* EEM(
        double (*x)(double, double),
        double (*y)(double, double),
        double x0, double y0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print
        ) {
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file: %s\n", filename);
            return 0;
        }
    }

    double h = (t1 - t0)/n;
    double x_i = x0;
    double y_i = y0;
    for (int i = 0; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", x_i, y_i);
        }
        double temp_x_i = x_i;
        x_i = x_i + h*x(temp_x_i, y_i);
        y_i = y_i + h*y(temp_x_i, y_i);
    }

    if (print) {
        fprintf(file, "%lf, %lf\n", x_i, y_i);
        fclose(file);
    }
    double *result = malloc(2*sizeof(double));
    result[0] = x_i;
    result[1] = y_i;
    return result;
}

double* RK2(
        double (*x)(double, double),
        double (*y)(double, double),
        double x0, double y0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print) {
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file: %s\n", filename);
            return 0;
        }
    }

    double h = (t1 - t0)/n;
    double x_i = x0;
    double y_i = y0;
    for (int i = 0; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", x_i, y_i);
        }
        double temp_x_i = x_i;
        x_i = x_i + h*x(temp_x_i + (h/2)*x(temp_x_i, y_i), y_i + (h/2)*y(temp_x_i, y_i));
        y_i = y_i + h*y(temp_x_i + (h/2)*x(temp_x_i, y_i), y_i + (h/2)*y(temp_x_i, y_i));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", x_i, y_i);
        fclose(file);
    }
    double *result = malloc(2*sizeof(double));
    result[0] = x_i;
    result[1] = y_i;
    return result;
}

double* RK3(
        double (*x)(double, double),
        double (*y)(double, double),
        double x0, double y0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print) {
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file: %s\n", filename);
            return 0;
        }
    }

    double h = (t1 - t0)/n;
    double x_i = x0;
    double y_i = y0;
    for (int i = 0; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", x_i, y_i);
        }
        double t1_x, t1_y, t2_x, t2_y, t3_x, t3_y;
        t1_x = h*x(x_i,y_i);
        t1_y = h*y(x_i,y_i);
        t2_x = h*x(x_i + t1_x/2, y_i + t1_y/2);
        t2_y = h*y(x_i + t1_x/2, y_i + t1_y/2);
        t3_x = h*x(x_i - t1_x + 2*t2_x, y_i - t1_y + 2*t2_y);
        t3_y = h*y(x_i - t1_x + 2*t2_x, y_i - t1_y + 2*t2_y);
        x_i = x_i + 1./6 * (t1_x + 4*t2_x + t3_x);
        y_i = y_i + 1./6 * (t1_y + 4*t2_y + t3_y);
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", x_i, y_i);
        fclose(file);
    }
    double *result = malloc(2*sizeof(double));
    result[0] = x_i;
    result[1] = y_i;
    return result;
}

double* RK4(
        double (*x)(double, double),
        double (*y)(double, double),
        double x0, double y0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print) {
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file: %s\n", filename);
            return 0;
        }
    }

    double h = (t1 - t0)/n;
    double x_i = x0;
    double y_i = y0;
    for (int i = 0; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", x_i, y_i);
        }
        double t1_x = x_i;
        double t1_y = y_i;
        double t2_x = t1_x + h/2 * x(t1_x, t1_y);
        double t2_y = t1_y + h/2 * y(t1_x, t1_y);
        double t3_x = t1_x + h/2 * x(t2_x, t2_y);
        double t3_y = t1_y + h/2 * y(t2_x, t2_y);
        double t4_x = t1_x + h * x(t3_x, t3_y);
        double t4_y = t1_y + h * y(t3_x, t3_y);
        x_i = x_i + h/6 * (x(t1_x, t1_y) + 2*x(t2_x, t2_y) + 2*x(t3_x, t3_y) + x(t4_x, t4_y));
        y_i = y_i + h/6 * (y(t1_x, t1_y) + 2*y(t2_x, t2_y) + 2*y(t3_x, t3_y) + y(t4_x, t4_y));
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", x_i, y_i);
        fclose(file);
    }
    double *result = malloc(2*sizeof(double));
    result[0] = x_i;
    result[1] = y_i;
    return result;
}

double *AM3Step(
        double (*x)(double, double),
        double (*y)(double, double),
        double x0, double y0,
        double t0, double t1,
        int n,
        char *file_prefix, unsigned int print) {
    // Works only for specific functions
    FILE *file;
    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file: %s\n", filename);
            return 0;
        }
    }

    double h = (t1 - t0)/n;

    double x_i[3] = {x0, 0, 0};
    double y_i[3] = {y0, 0, 0};

    // Pokus o štart s menej-krokovými Adams-Moultonovými metódami. Nefungovalo.
    x_i[1] = -((8*x_i[0] + 4*h*x_i[0] + h*h*x_i[0] - 4*h*y_i[0])/(-8 - 4*h + h*h));
    y_i[1] = -((-8*h*x_i[0] + 8*y_i[0] - 4*h*y_i[0] + h*h*y_i[0])/(-8 - 4*h + h*h));
    x_i[2] = -((-5*h*h*x_i[0] + 288*x_i[1] + 120*h*x_i[1] + 40*h*h*x_i[1] + 12*h*y_i[0] - 156*h*y_i[1])/(-288 - 120*h + 25*h*h));
    y_i[2] = -((24*h*x_i[0] - 312*h*x_i[1] + 24*h*y_i[0] - 5*h*h*y_i[0] + 288*y_i[1] - 192*h*y_i[1] + 40*h*h*y_i[1])/(-288 - 120*h + 25*h*h));

    // Pokus o štart s RK4. Fungovalo.
    double t1_x, t1_y, t2_x, t2_y, t3_x, t3_y, t4_x, t4_y;
    // Prvý krok
    t1_x = x_i[0];
    t1_y = y_i[0];
    t2_x = t1_x + h/2 * x(t1_x, t1_y);
    t2_y = t1_y + h/2 * y(t1_x, t1_y);
    t3_x = t1_x + h/2 * x(t2_x, t2_y);
    t3_y = t1_y + h/2 * y(t2_x, t2_y);
    t4_x = t1_x + h * x(t3_x, t3_y);
    t4_y = t1_y + h * y(t3_x, t3_y);
    x_i[1] = x_i[0] + h/6 * (x(t1_x, t1_y) + 2*x(t2_x, t2_y) + 2*x(t3_x, t3_y) + x(t4_x, t4_y));
    y_i[1] = y_i[0] + h/6 * (y(t1_x, t1_y) + 2*y(t2_x, t2_y) + 2*y(t3_x, t3_y) + y(t4_x, t4_y));
    // Druhý krok
    t1_x = x_i[1];
    t1_y = y_i[1];
    t2_x = t1_x + h/2 * x(t1_x, t1_y);
    t2_y = t1_y + h/2 * y(t1_x, t1_y);
    t3_x = t1_x + h/2 * x(t2_x, t2_y);
    t3_y = t1_y + h/2 * y(t2_x, t2_y);
    t4_x = t1_x + h * x(t3_x, t3_y);
    t4_y = t1_y + h * y(t3_x, t3_y);
    x_i[2] = x_i[1] + h/6 * (x(t1_x, t1_y) + 2*x(t2_x, t2_y) + 2*x(t3_x, t3_y) + x(t4_x, t4_y));
    y_i[2] = y_i[1] + h/6 * (y(t1_x, t1_y) + 2*y(t2_x, t2_y) + 2*y(t3_x, t3_y) + y(t4_x, t4_y));


    for (int i = 2; i<n; i++) {

        if (print) {
            fprintf(file, "%lf, %lf\n", x_i[0], y_i[0]);
        }

        double x_tmp = -((3*h*h*x_i[0] - 15*h*h*x_i[1] + 384*x_i[2] + 144*h*x_i[2] + 57*h*h*x_i[2] - 8*h*y_i[0] + 40*h*y_i[1] - 224*h*y_i[2])/(3*(-128 - 48*h + 9*h*h)));
        double y_tmp = -((-16*h*x_i[0] + 80*h*x_i[1] - 448*h*x_i[2] - 16*h*y_i[0] + 3*h*h*y_i[0] + 80*h*y_i[1] - 15*h*h*y_i[1] + 384*y_i[2] - 304*h*y_i[2] + 57*h*h*y_i[2])/(3*(-128 - 48*h + 9*h*h)));

        x_i[0] = x_i[1];
        x_i[1] = x_i[2];
        x_i[2] = x_tmp;
        y_i[0] = y_i[1];
        y_i[1] = y_i[2];
        y_i[2] = y_tmp;

    }
    if (print) {
        fprintf(file, "%lf, %lf\n", x_i[0], y_i[0]);
        fprintf(file, "%lf, %lf\n", x_i[1], y_i[1]);
        fprintf(file, "%lf, %lf\n", x_i[2], y_i[2]);
        fclose(file);
    }

    double *result = malloc(2*sizeof(double));
    result[0] = x_i[2];
    result[1] = y_i[2];
    return result;
}
