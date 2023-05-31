#include "header.h"

int main() {

    for (int n = 4; n < 300; n *= 2) {
        EEM(
                fx, fy,
                5., 5., 0., 3., n,
                "EEM_5_5", 1);
    }

    for (int n = 2; n < 10000; n *= 2) {
        printf("n=%d\t%lf\n", n, EOC(
                EEM,
                fx, fy, 7.53749, -5.37403, -3., -7., 0., 9., n));
    }

}
