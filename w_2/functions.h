//
// Created by Timur Kramar on 27/02/2023.
//

#ifndef W_2_FUNCTIONS_H
#define W_2_FUNCTIONS_H

#endif //W_2_FUNCTIONS_H

#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x);
}

double derivative_f(double x) {
    return cos(x);
}

double derivative_f_forwards(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double derivative_f_backwards(double x, double h) {
    return (f(x) - f(x - h)) / h;
}

double derivative_f_central(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

double double_derivative_f(double x) {
    return -sin(x);
}

double double_derivative_f_forwards(double x, double h) {
    return (derivative_f_backwards(x+h, h)- derivative_f_backwards(x, h)) / h;
}