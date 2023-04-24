#include "header.h"

int main() {
    for (int n = 10; n < 500; n*=2) {
        adam_bash_2step(
                f1,
                0., 0., 2., n,
                "uloha2_adam_bash", 1);
    }

    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC(
                       adam_bash_2step,
                       f1,atan(32),
                       0., 0., 2., n * 2));
    }
}
