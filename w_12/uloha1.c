#include "header.h"

int main() {

//    for (int n = 1; n < 50; n*=2) {
//        finite_difference_dirichlet(
//                f,
//                0., M_PI, 1., 1., n,
//                "uloha1_finite_difference", 1);
//    }


    for (int n = 2; n < 10000; n*=2) {
        printf("n=%d\tp=1\t%lf\t\t", n, EOC_f_d(
                finite_difference_dirichlet,
                f, f_result, 0., M_PI, 1., 1., n, 1));

        printf("n=%d\tp=2\t%lf\n", n, EOC_f_d(
                finite_difference_dirichlet,
                f, f_result, 0., M_PI, 1., 1., n, 2));
    }

}
