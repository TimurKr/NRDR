//
// Created by Timur Kramar on 01/03/2023.
//

#include "header.h"

int main() {
    int n = 100;
    for (int i = 10; i < n; i+=10) {
        printf("\nn = %d\n", i);
        printf("Integrál funkcie f:\nJednostranná metóda: %f\nObdĺžniková metóda: %f\nTrapezoid metóda: %f\n",
               f_integral_forward(n, - M_PI, M_PI),
               f_integral_central(n, - M_PI, M_PI),
               f_integral_trapezoid(n, - M_PI, M_PI));
        printf("Integrál funkcie f2:\nJednostranná metóda: %f\nObdĺžniková metóda: %f\nTrapezoid metóda: %f\n",
               f2_integral_forward(n, - M_PI, M_PI),
               f2_integral_central(n, - M_PI, M_PI),
               f2_integral_trapezoid(n, - M_PI, M_PI));
    }

    return 0;
}