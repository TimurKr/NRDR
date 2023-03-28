#include "headers.h"

int main() {
    printf("Výsledok pre n=%d: %lf\n", 10, trapezoid_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 10, "uloha1", 1));
    printf("Výsledok pre n=%d: %lf\n", 100, trapezoid_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 100, "uloha1", 1));
    printf("Výsledok pre n=%d: %lf\n", 1000, trapezoid_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 1000, "uloha1", 1));
    for (int n = 10; n<=1000; n*=2) {
        printf("EOC pre n=%d: %lf\n", n,
               (double) EOC_w_df(trapezoid_euler,
                                 f,
                                 d_f,
                                 tan(M_PI / 4),
                                 tan(0.01),
                                 0.01, M_PI / 4,
                                 n));
    }
    return 0;
}

