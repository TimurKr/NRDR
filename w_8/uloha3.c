#include "header.h"

int main() {
    for (int n = 5; n < 20; n*=2) {
        explicit_euler(f2, 1., 0., 5., n, "uloha3_eul", 1);
        heun(
                f2,
                1., 0., 5., n,
                "uloha3_heu", 1);
    }
}
