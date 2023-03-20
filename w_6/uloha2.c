#include "headers.h"

int main() {
    for (int n = 25; n <= 100; n+=25) {
        explicit_euler(f2, 1., 0., 1., n, "uloha2_exp");
        implicit_euler(f2, d_f2, 1., 0., 1., n, "uloha2_imp");
        trapezoid_euler(f2, d_f2, 1., 0., 1., n, "uloha2_tra");
    }
    return 0;
}

