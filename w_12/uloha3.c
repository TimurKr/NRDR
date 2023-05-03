#include "header.h"

int main() {
    for (int n = 1; n < 50; n*=2) {
        finite_difference_neumann_central(
                f2,
                0., 1., 1., 4., n,
                "uloha2_finite_difference_neumman_central", 1);
    }

    for (int n = 2; n < 10000; n*=2) {
        printf("n=%d\tp=1\t%lf\t\t", n, EOC_f_d_neumann(
                finite_difference_neumann_central,
                f2, f2_result, 0., 1., 1., 4., n, 1));

        printf("n=%d\tp=2\t%lf\n", n, EOC_f_d_neumann(
                finite_difference_neumann_central,
                f2, f2_result, 0., 1., 1., 4., n, 2));
    }
}
