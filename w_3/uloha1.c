#include <stdio.h>

#include "header.h"

int main(){
    int ns[] = {50, 100, 200, 300, 500 };

    FILE *fp[5];

    for (int i=0; i<5; i++) {
        char filename[100];
        sprintf(filename, "../outputs/uloha1_%d.csv", ns[i]);
        fp[i] = fopen(filename, "w");
        if (fp[i] == NULL) {
            printf("Error opening file: ");
            printf("%s\n", filename);
            return 1;
        }
    }

    for (int i=0; i<5; i++) {
        for (int j = 0; j < ns[i]; j++) {
            fprintf(fp[i], "%f, %f, %f, %f\n",
                    - M_PI + j * 2 * M_PI / ns[i],
                    f_derivative(- M_PI + j * 2 * M_PI / ns[i]),
                    f_derivative_central(- M_PI + j * 2 * M_PI / ns[i], 2 * M_PI / ns[i]),
                    f_derivative_approx(- M_PI + j * 2 * M_PI / ns[i], 2 * M_PI / ns[i]));
        }
    }
    for (int i=0; i<5; i++) {
        fclose(fp[i]);
    }
}
