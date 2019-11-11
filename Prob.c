/**
 * https://towardsdatascience.com/how-to-use-and-create-a-z-table-standard-normal-table-240e21f36e53
*/

#include <stdio.h>
#include <math.h>

double func(double, double, double);
double tb(double);

int main()
{
    int n;
    double x, y, z, r;
    printf("Digite três números: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    r = func(x, y, z);
    printf("Na tabela: %lf\n", r);
    r = tb(x);
    printf("\nTestando: %lf\n", r);
}

double func(double x, double y, double z) 
{
    z = (x - y) / z;
    return z;
}

double tb(double x)
{
    double constant = 1 / sqrt(2 * 3.14);
    return (constant * 2.718281 * ((-x * -x) / 2)*(-x * -x) / 2);
}

