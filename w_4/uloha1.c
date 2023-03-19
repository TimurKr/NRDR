#include "header.h"

void a() {
    int n[] = {11, 101, 1001};

    for (int n_i = 0; n_i < 3; n_i++) {
        approximate_a(n[n_i], 1);
    }
}

void b() {
    int n[] = {11, 101, 1001};

    for (int n_i = 0; n_i < 3; n_i++) {
        approximate_b(n[n_i], 1);
    }
}

void c() {
    int n[] = {11, 101, 1001};

    for (int n_i = 0; n_i < 3; n_i++) {
        approximate_c(n[n_i], 1);
    }
}

int main() {
    a();
    b();
    c();
    return 0;
}
