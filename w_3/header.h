//
// Created by Timur Kramar on 27/02/2023.
//

#ifndef W_3_HEADER_H
#define W_3_HEADER_H

#endif //W_3_HEADER_H

#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x,2);
}

double f_derivative(double x){
    return 3*pow(x,2)*cos(pow(x,3) + 1);
}

double f_derivative_central(double x, double h){
    return (f(x+h) - f(x-h))/(2*h);
}

double f_derivative_approx(double x, double h){
    return (f(x-2*h) / 12 - 2*f(x-h)/3 + 2*f(x+h)/3 - f(x+2*h)/12)/h;
}


double f2(double x) {
    return cos(x);
}

double f2_derivative_forward(double x, double h){
    return (f2(x+h) - f2(x))/h;
}

double f2_derivative_central(double x, double h){
    return (f2(x+h) - f2(x-h))/(2*h);
}


double f_integral_forward(double n, double start, double end){
    double sum = 0;
    double h = (end - start) / n;
    for (int i = 0; i < n; i++) {
        sum += f(start + i * h);
    }
    return sum * h;
}

double f_integral_central(double n, double start, double end){
    double sum = 0;
    double h = (end - start) / n;
    for (int i = 0; i < n; i++) {
        sum += f(start + i*h + h/2);
    }
    return sum * h;
}

double f_integral_trapezoid(double n, double start, double end){
    double sum = 0;
    double h = (end - start) / n;
    for (int i = 0; i < n; i++) {
        sum += (f(start + i * h) + f(start + (i+1)*h))/2;
    }
    return sum * h;
}

double f2_integral_forward(double n, double start, double end){
    double sum = 0;
    double h = (end - start) / n;
    for (int i = 0; i < n; i++) {
        sum += f2(start + i * h);
    }
    return sum * h;
}

double f2_integral_central(double n, double start, double end){
    double sum = 0;
    double h = (end - start) / n;
    for (int i = 0; i < n; i++) {
        sum += f2(start + i*h + h/2);
    }
    return sum * h;
}

double f2_integral_trapezoid(double n, double start, double end){
    double sum = 0;
    double h = (end - start) / n;
    for (int i = 0; i < n; i++) {
        sum += (f2(start + i * h) + f2(start + (i+1)*h))/2;
    }
    return sum * h;
}