//
// Created by Timur Kramar on 27/03/2023.
//

#ifndef W_7_FUNCTIONS_H
#define W_7_FUNCTIONS_H

#endif //W_7_FUNCTIONS_H

#include "math.h"

double f(double x) {
    return 16 * pow(cos(x), 2);
}

double df(double x) {
    return -16 * sin(2*x);
}

double ddf(double x) {
    return -32 * (2*x);
}