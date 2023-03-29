#include "header.h"

int main() {
    for (int n = 10; n < 200; n*=2) {
        explicit_taylor_3(
            f, df, ddf,
            0., 0., 2., n,
            "uloha2_tay", 1);
    }
    for (int n = 10; n< 10000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC_w_ddf(
                       explicit_taylor_3,
                       f, df, ddf,
                       atan(32), 0., 0., 2., n * 2));
    }

}
