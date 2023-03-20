#include "headers.h"

int main() {
    printf("Výsledok pre n=%d: %lf\n",10, trapezoid_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 10, "uloha_1"));
    printf("Výsledok pre n=%d: %lf\n",100, trapezoid_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 100, "uloha_1"));
    printf("Výsledok pre n=%d: %lf\n",1000, trapezoid_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 1000, "uloha_1"));
    return 0;
}

