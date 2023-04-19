#include "header.h"

int main() {
    int ns[4] = {30, 50, 100, 200};
    for (int i = 0; i < 4; i++) {
        adam_bash_3step_EEM(
                f1,
                0., 0., 2., ns[i],
                "uloha3_adam_bash_EEM", 1);
    }

    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d with EEM: %lf\n", n * 2,
               (double) EOC(
                       adam_bash_3step_EEM,
                       f1,atan(32),
                       0., 0., 2., n * 2));
    }

    for (int i = 0; i < 4; i++) {
        adam_bash_3step_RK2(
                f1,
                0., 0., 2., ns[i],
                "uloha3_adam_bash_RK2", 1);
    }

    printf("\n\n");
    for (int n = 10; n<5000; n *= 2) {
        printf("EOC for n = %d with RK2: %lf\n", n * 2,
               (double) EOC(
                       adam_bash_3step_RK2,
                       f1,atan(32),
                       0., 0., 2., n * 2));
    }
}
