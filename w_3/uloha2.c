//
// Created by Timur Kramar on 01/03/2023.
//

#include "header.h"

int main() {

    FILE *fp;
    fp = fopen("../outputs/uloha2.csv", "w");

    if (fp == NULL) {
        printf("Error opening file: ");
        printf("%s\n", "../outputs/uloha2.csv");
        return 1;
    }

    int n = 30;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%f, %f, %f\n",
                - M_PI + i * 2 * M_PI / n,
                f2_derivative_forward(- M_PI + i * 2 * M_PI / n, 2 * M_PI / n),
                f2_derivative_central(- M_PI + i * 2 * M_PI / n, 2 * M_PI / n));
    }

    fclose(fp);

    return 0;
}