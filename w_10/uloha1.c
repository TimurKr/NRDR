#include "header.h"

int main() {
    for (int n = 10; n < 500; n*=2) {
        nystrom(
                f1,
                0., 0., 2., n,
                "uloha1_a_nystrom", 1);
    }

    printf("A: ");
    for (int n = 10; n<100000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC(
                       nystrom,
                       f1,atan(32),
                       0., 0., 2., n * 2));
    }

    for (int n = 10; n < 500; n*=2) {
        nystrom(
                f2,
                1., 0., 1., n,
                "uloha1_b_nystrom", 1);
    }

    printf("\n\nB: ");
    for (int n = 10; n<100000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC(
                       nystrom,
                       f2, exp(-10*1),
                       1., 0., 1., n * 2));
    }
}
