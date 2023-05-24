#include "header.h"

int main() {

    for (int n = 4; n < 300; n*=2) {
        explicit_euler(
                x, y,
                -3., -7., 0., 9., n,
                "EEM_-3_-7", 1);
    }

    for (int n = 2; n < 10000; n*=2) {
        printf("n=%d\t%lf\n", n, EOC(
                explicit_euler,
                x, y, 7.53749,-5.37403, -3., -7., 0., 9., n));
    }

}
