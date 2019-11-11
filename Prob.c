/**
 * https://towardsdatascience.com/how-to-use-and-create-a-z-table-standard-normal-table-240e21f36e53
*/

#include <stdio.h>
#include <math.h>

double func(double, double, double);

int main()
{
    int n;
    double x, y, z;
    printf("Digite três números: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    x = func(x, y, z);
    printf("%lf\n", x);
}

double func(double x, double y, double z) 
{
    z = (x - y) / z;
    return z;
}

