#include "headers.h"

int main() {
    for (int n = 10; n < 1000; n*=2) {
        explicit_euler(f, 0., 0., 2., n, "uloha1_eul", 1);
        explicit_taylor_2(f, df, 0., 0., 2., n, "uloha1_tay", 1);
    }
    for (int n = 10; n< 10000; n *= 2) {
        printf("EOC for n = %d: %lf\n", n * 2,
               (double) EOC_w_df(
                       explicit_taylor_2,
                       f, df,
                       atan(32), 0., 0., 2., n * 2));
    }
    printf("Explicit_taylor for n = %d: %lf\n", 10, explicit_taylor_2(f, df, 0., 0., 2., 10, "", 0));

}
