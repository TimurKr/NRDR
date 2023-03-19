#include "functions.h"

int main() {

    double x, h;
    printf("f(x) = sin(x)");
    printf("\nEnter x: ");
    scanf("%lf", &x);
    printf("Enter h: ");
    scanf("%lf", &h);
    printf("\nf'(x) = %lf", derivative_f(x));
    printf("\nf'(x) forwards = %lf", derivative_f_forwards(x, h));
    printf("\nf'(x) backwards = %lf", derivative_f_backwards(x, h));
    printf("\nf'(x) central = %lf", derivative_f_central(x, h));

    return 0;
}
