//
// Created by Timur Kramar on 27/02/2023.
//

#include "functions.h"


int main(){
    for (int n = 10; n <= 1000; n *= 10) {

        FILE *f_d, *f_d_forward, *f_d_backward, *f_d_central;
        char filename[100];
        sprintf(filename, "../outputs/derivative-%d.csv", n);
        f_d = fopen(filename, "w");
        sprintf(filename, "../outputs/forward-%d.csv", n);
        f_d_forward = fopen(filename, "w");
        sprintf(filename, "../outputs/backward-%d.csv", n);
        f_d_backward = fopen(filename, "w");
        sprintf(filename, "../outputs/central-%d.csv", n);
        f_d_central = fopen(filename, "w");

        if (f_d_forward == NULL || f_d_backward == NULL || f_d_central == NULL || f_d == NULL) {
            printf("Error opening file!\n");
            return (1);
        }

        double a = -4;
        double b = 4;
        double h = (b - a) / n;
        for (int i = 0; i <= n; i++) {
            fprintf(f_d, "%lf, %lf\n", i * h + a, derivative_f(i * h + a));

            if (i != 0 && i != n) {
                fprintf(f_d_central, "%lf, %lf\n", i * h + a, derivative_f_central(i * h + a, h));
                fprintf(f_d_forward, "%lf, %lf\n", i * h + a, derivative_f_forwards(i * h + a, h));
                fprintf(f_d_backward, "%lf, %lf\n", i * h + a, derivative_f_backwards(i * h + a, h));
            }
            if (i == 0) {
                fprintf(f_d_forward, "%lf, %lf\n", i * h + a, derivative_f_forwards(i * h + a, h));
            }
            if (i == n) {
                fprintf(f_d_backward, "%lf, %lf\n", i * h + a, derivative_f_backwards(i * h + a, h));
            }
        }

        fclose(f_d);
        fclose(f_d_forward);
        fclose(f_d_backward);
        fclose(f_d_central);
    }
}