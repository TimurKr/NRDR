#include "header.h"

int main() {
    for (int n = 10; n < 200; n*=2) {
        RK2(
            f,
            0., 0., 2., n,
            "uloha3_RK2", 1);
    }
}
