//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_FUNCTIONS_H
#define W_7_FUNCTIONS_H

#endif //W_7_FUNCTIONS_H

#include "math.h"

double f(double x) {
    return -sin(x);
}

double f_result(double x) {
    return 1 + sin(x);
}

double f2(double x) {
    return 12 * x * x + 2;
}

double f2_result(double x) {
    return 1 + x + x * x + pow(x, 4);
}
