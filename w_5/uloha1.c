#include "headers.h"

int main() {
    printf("Výsledok pre funkciu 1: %lf\n", root_bisect(0.5, 2.5, F1, 0.1));
    printf("\n######################################\n\n");
    printf("Výsledok pre funkciu 2: %lf\n", root_bisect(-1.5, 3, F2, 0.1));
    return 0;
}
