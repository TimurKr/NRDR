//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_HEADERS_H
#define W_7_HEADERS_H

#endif //W_7_HEADERS_H

#include <stdio.h>
#include <stdlib.h>

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
    double u_i[2] = {u0, u0 + h*f(u0 + (h/2)*f(u0))};
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


double adam_bash_2step(
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
    double u_i[2] = {u0, u0 + h*f(u0 + (h/2)*f(u0))};
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

double adam_bash_3step_EEM(
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
    double u_i[3];
    u_i[0] = u0;
    u_i[1] = u_i[0] + h*f(u_i[0]);
    u_i[2] = u_i[1] + h*f(u_i[1]);
    for (int i = 3; i<n; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", t0 + h*(i-3), u_i[0]);
        }
        double tmp = u_i[2] + (h/12)*(5*f(u_i[0]) - 16*f(u_i[1]) + 23*f(u_i[2]));
        u_i[0] = u_i[1];
        u_i[1] = u_i[2];
        u_i[2] = tmp;
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1-2*h, u_i[0]);
        fprintf(file, "%lf, %lf\n", t1-h, u_i[1]);
        fprintf(file, "%lf, %lf\n", t1, u_i[2]);
        fclose(file);
    }
    return u_i[1];
}


double adam_bash_4step(
        double (*f)(double), unsigned int init_method,
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

    double u_i[4];

    if (init_method == 0)
    {
        // EEM
        u_i[0] = u0;
        u_i[1] = u_i[0] + h*f(u_i[0]);
        u_i[2] = u_i[1] + h*f(u_i[1]);
        u_i[3] = u_i[2] + h*f(u_i[2]);
    }
    else if (init_method == 1)
    {
        // RK2
        u_i[0] = u0;
        u_i[1] = u_i[0] + h*f(u_i[0] + (h/2)*f(u_i[0]));
        u_i[2] = u_i[1] + h*f(u_i[1] + (h/2)*f(u_i[1]));
        u_i[3] = u_i[2] + h*f(u_i[2] + (h/2)*f(u_i[2]));
    }
    else if (init_method == 2)
    {
        // SSPRK3
        u_i[0] = u0;
        for (int i = 0; i<3; i++) {
            double y1 = u_i[i];
            double y2 = u_i[i] + h*f(y1);
            double y3 = u_i[i] + (h/4)*(f(y1) + f(y2));
            u_i[i + 1] = u_i[i] + (h/6)*(f(y1) + f(y2) + 4*f(y3));
        }
    }
    else
    {
        printf("Invalid init_method: %d\n", init_method);
        return -1;
    }

    for (int i = 4; i<n+1; i++) {
        if (print) {
            fprintf(file, "%lf, %lf\n", t0 + h*(i-4), u_i[0]);
        }
        double tmp = u_i[3] + (h/24)*(-9*f(u_i[0]) + 37*f(u_i[1]) - 59*f(u_i[2]) + 55*f(u_i[3]));
        u_i[0] = u_i[1];
        u_i[1] = u_i[2];
        u_i[2] = u_i[3];
        u_i[3] = tmp;
    }
    if (print) {
        fprintf(file, "%lf, %lf\n", t1-3*h, u_i[0]);
        fprintf(file, "%lf, %lf\n", t1-2*h, u_i[1]);
        fprintf(file, "%lf, %lf\n", t1-h, u_i[2]);
        fprintf(file, "%lf, %lf\n", t1, u_i[3]);
        fclose(file);
    }
    return u_i[3];
}

typedef struct {
    double *under;
    double *diag;
    double *above;
    double *equals;
    double *result;
    unsigned int n;
} tridiag_system;

void thomas_algorithm(tridiag_system* system) {
    for (unsigned int i = 1; i < system->n; i++) {
        double w = system->under[i]/system->diag[i-1];
        system->diag[i] -= w*system->above[i-1];
        system->equals[i] -= w*system->equals[i-1];
    }

    system->result[system->n-1] = system->equals[system->n-1]/system->diag[system->n-1];
    for (int i = system->n - 2; i >= 0; i--) {
        system->result[i] = (system->equals[i] - system->above[i]*system->result[i+1])/system->diag[i];
    }
}

double *finite_difference_dirichlet(
        double (*f)(double),
        double t0, double t1, double u0, double u1, int n,
        char *file_prefix, unsigned int print
        ) {
    double h = (t1 - t0)/(n+1);
    tridiag_system system;
    system.n = n;
    system.under = malloc(n*sizeof(double));
    system.diag = malloc(n*sizeof(double));
    system.above = malloc(n*sizeof(double));
    system.equals = malloc(n*sizeof(double));
    system.result = malloc(n*sizeof(double));
    double diag = -2/h/h;
    double around = 1/h/h;
    for (int i = 0; i<n; i++) {
        system.under[i] = around;
        system.diag[i] = diag;
        system.above[i] = around;
        system.equals[i] = f(t0 + (i+1)*h);
    }
    system.equals[0] = f(t0) - u0*around;
    system.equals[n-1] = f(t1) - u1*around;

    thomas_algorithm(&system);

    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        FILE *file = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return NULL;
        }
        fprintf(file, "%lf, %lf\n", t0, u0);
        for (int i = 0; i<n; i++) {
            fprintf(file, "%lf, %lf\n", t0 + (i+1)*h, system.result[i]);
        }
        fprintf(file, "%lf, %lf\n", t1, u1);
        fclose(file);
    }
    return system.result;
}

double *finite_difference_neumann_simple(
        double (*f)(double),
        double t0, double t1, double d0, double u1, int n,
        char *file_prefix, unsigned int print
) {
    // n je počet bodov v intervale, teda riešenie bude dlhé n+1
    double h = (t1 - t0) / (n + 1);
    tridiag_system system;
    system.n = n + 1;
    system.under = malloc((n+1) * sizeof(double));
    system.diag = malloc((n+1) * sizeof(double));
    system.above = malloc((n+1) * sizeof(double));
    system.equals = malloc((n+1) * sizeof(double));
    system.result = malloc((n+1) * sizeof(double));
    double diag = -2 / h / h;
    double around = 1 / h / h;
    for (int i = 1; i < n + 1; i++) {
        system.under[i] = around;
        system.diag[i] = diag;
        system.above[i] = around;
        system.equals[i] = f(t0 + i * h);
    }
    // Fix first row
    system.diag[0] = -1 / h;
    system.above[0] = 1 / h;
    system.equals[0] = d0;
    system.equals[n] -= u1 * around;

    thomas_algorithm(&system);

    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        FILE *file = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return NULL;
        }
        for (int i = 0; i <= n; i++) {
            fprintf(file, "%lf, %lf\n", t0 + i * h, system.result[i]);
        }
        fprintf(file, "%lf, %lf\n", t1, u1);
        fclose(file);
    }
    return system.result;
}

double *finite_difference_neumann_central(
        double (*f)(double),
        double t0, double t1, double d0, double u1, int n,
        char *file_prefix, unsigned int print
) {
    // n je počet bodov v intervale, teda riešenie bude dlhé n+1
    double h = (t1 - t0) / (n + 1);
    tridiag_system system;
    system.n = n + 1;
    system.under = malloc((n+1) * sizeof(double));
    system.diag = malloc((n+1) * sizeof(double));
    system.above = malloc((n+1) * sizeof(double));
    system.equals = malloc((n+1) * sizeof(double));
    system.result = malloc((n+1) * sizeof(double));
    double diag = -2 / h / h;
    double around = 1 / h / h;
    for (int i = 1; i < n + 1; i++) {
        system.under[i] = around;
        system.diag[i] = diag;
        system.above[i] = around;
        system.equals[i] = f(t0 + i * h);
    }
    // Fix first row
    system.diag[0] = -1 / h;
    system.above[0] = 1 / h;
    system.equals[0] = d0 + f(t0) * h /2;
    system.equals[n] -= u1 * around;

    thomas_algorithm(&system);

    if (print) {
        char filename[100];
        sprintf(filename, "../outputs/%s_%dn.csv", file_prefix, (int) n);
        FILE *file = fopen(filename, "w");
        if (f == NULL) {
            printf("Error opening file: %s\n", filename);
            return NULL;
        }
        for (int i = 0; i <= n; i++) {
            fprintf(file, "%lf, %lf\n", t0 + i * h, system.result[i]);
        }
        fprintf(file, "%lf, %lf\n", t1, u1);
        fclose(file);
    }
    return system.result;
}
