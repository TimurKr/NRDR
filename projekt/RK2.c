#include "header.h"

int main() {

    for (int n = 4; n < 300; n *= 2) {
        RK2(
            fx, fy,
            -3., -7., 0., 9., n,
            "RK2_-3_-7", 1);
    }

    for (int n = 2; n < 10000; n *= 2) {
        printf("n=%d\t%lf\n", n, EOC(
                RK2,
                fx, fy, 7.537491969,-5.374027129, 5., 5., 0., 3., n));
    }

}
