#include "headers.h"


int main() {
    printf("Výsledok pre n=%d: %lf",10, implicit_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 10));
    printf("Výsledok pre n=%d: %lf",100, implicit_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 100));
    printf("Výsledok pre n=%d: %lf",1000, implicit_euler(f, d_f, tan(0.01), 0.01, M_PI / 4, 1000));

    //printf("%lf", tan(0));
    return 0;
}
