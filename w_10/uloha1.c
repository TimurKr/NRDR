#include "header.h"

int main() {
    for (int n = 10; n < 200; n*=2) {
        RK4(
                f1,
                0., 0., 2., n,
                "uloha1_RK4", 1);
    }

    for (int n = 10; n< 2000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC(
                       RK4,
                       f1,
                       atan(32), 0., 0., 2., n * 2));
    }
}
