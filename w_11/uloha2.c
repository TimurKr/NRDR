#include "header.h"

int main() {
    for (int n = 1; n < 50; n*=2) {
        finite_difference(
                f3,
                0., M_PI, 1., 1., n,
                "uloha2_finite_difference", 1);
    }
}
