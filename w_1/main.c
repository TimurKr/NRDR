#include <stdio.h>

double f(double x)
{
    return x * x;
}

int main()
{
    double start = -1, end = 1, n = 10;
    double step = (end - start) / n;

    FILE *output;
    output = fopen("output.csv", "w");
    if (output == NULL)
    {
        printf("Error opening file!\n");
        return(1);
    }

    double i;
    for (i = start; i <= end; i += step)
    {
        fprintf(output, "%lf,%lf\n", i, f(i));
    }
}