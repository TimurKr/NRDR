#include "header.h"

int main() {

    //EEM
    for (int n = 10; n < 500; n*=2) {
        adam_bash_4step(
                f1, 0,
                0., 0., 2., n,
                "uloha1_adam_bash_4_w_EEM", 1);
    }

    printf("\n\n Štart s EEM\n");
    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC_w_method(
                       adam_bash_4step,
                       f1,atan(32),
                       0., 0, 0., 2., n * 2));
    }

    //RK2
    for (int n = 10; n < 500; n*=2) {
        adam_bash_4step(
                f1, 1,
                0., 0., 2., n,
                "uloha1_adam_bash_4_w_RK2", 1);
    }

    printf("\n\n Štart s RK2\n");
    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC_w_method(
                       adam_bash_4step,
                       f1,atan(32),
                       0., 1, 0., 2., n * 2));
    }

    //SSPRK3
    for (int n = 10; n < 500; n*=2) {
        adam_bash_4step(
                f1, 2,
                0., 0., 2., n,
                "uloha1_adam_bash_4_w_SSPRK3", 1);
    }

    printf("\n\n Štart s SSPRK3\n");
    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC_w_method(
                       adam_bash_4step,
                       f1,atan(32),
                       0., 2, 0., 2., n * 2));
    }

    //Druhá rovnica s SSPRK2
    for (int n = 5; n < 500; n*=2) {
        adam_bash_4step(
                f2, 2,
                1., 0., 5., n,

                "uloha1_adam_bash_4_w_SSPRK3_2", 1);
    }

    printf("\n\n Štart s SSPRK3\n");
    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC_w_method(
                       adam_bash_4step,
                       f2, sqrt(-1+2*exp(5)),
                       1., 2, 0., 5., n * 2));
    }


}
