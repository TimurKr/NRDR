//
// Created by Timur Kramar on 27/02/2023.
//

#include "functions.h"

int main() {
    //    Úloha 4

    for (int n = 10; n <= 1000; n *=10) {
        FILE *f_d_d, *f_d_d_backward;
        char filename[100];
        sprintf(filename, "../outputs/derivative-derivative-%d.csv", n);
        f_d_d = fopen(filename, "w");
        sprintf(filename, "../outputs/derivative-derivative-backward-%d.csv", n);
        f_d_d_backward = fopen(filename, "w");

        if (f_d_d == NULL) {
            printf("Error opening file!\n");
            return (1);
        }

        double a = -4;
        double b = 4;
        double h = (b - a) / n;
        for (int i = 0; i < n; i++) {
            fprintf(f_d_d, "%lf, %lf\n", i * h + a, double_derivative_f(i * h + a));

            if (i != 0) {
                fprintf(f_d_d_backward, "%lf, %lf\n", i * h + a, double_derivative_f_forwards(i * h + a, h));
            }
        }

        fclose(f_d_d);
        fclose(f_d_d_backward);

    }

}