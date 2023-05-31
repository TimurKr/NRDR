#include "header.h"

int main() {

    for (int n = 2; n < 300; n *= 2) {
        RK4(
            fx, fy,
            5., 5., 0., 3., n,
            "RK4_-3_-7", 1);
    }

    for (int n = 2; n < 10000; n *= 2) {
        printf("n=%d\t%lf\n", n, EOC(
                RK4,
                fx, fy, 7.537491968651447,-5.374027128839188, 5., 5., 0., 3., n));
    }

}
