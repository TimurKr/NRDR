#include "headers.h"

int main() {
    printf("Výsledok pre F1 s x0=%lf: %.5lf\n", 1.5, root_newton(1.5, F1, d_F1, 0.01));
    printf("\n######################################\n\n");
    printf("Výsledok pre F1 s x0=%lf: %.5lf\n", 0.5, root_newton(0.5, F1, d_F1, 0.01));

    printf("\n######################################\n");
    printf("######################################\n");
    printf("######################################\n\n");

    printf("Výsledok pre F2 s x0=%lf: %.5lf\n", -1., root_newton(-1., F2, d_F2, 0.01));
    printf("\n######################################\n\n");
    printf("Výsledok pre F2 s x0=%lf: %.5lf\n", 2., root_newton(0., F2, d_F2, 0.01));
    printf("\n######################################\n\n");
    printf("Výsledok pre F2 s x0=%lf: %.5lf\n", -1.5, root_newton(1.5, F2, d_F2, 0.01));
    return 0;
}
