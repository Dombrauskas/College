/**
 * https://towardsdatascience.com/how-to-use-and-create-a-z-table-standard-normal-table-240e21f36e53
*/
#include <stdio.h>
#include <math.h>
#define LIN 10
#define COL 10
double TabelaNormal[LIN][COL];

double func(double, double, double);
double tb(double);
void FGM();

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
    
    FGM();
    
    int lin = s * 10;
    int col = s * 100 - lin * 10;
    
    printf("Cruzamento na matriz: %.4lf\n", TabelaNormal[lin][col]);
    return 0;
}

double func(double x, double y, double z) 
{
    z = (x - y) / z;
    return z;
}

/*
double tb(double x)
{
    double constant = 1 / sqrt(2 * 3.14);
    return (constant * 2.718281 * ((-x * -x) / 2)*(-x * -x) / 2);
}
*/

void FGM()
{
    int i, j;
    TabelaNormal[0][0] = 0.5000;

    for (i = 1; i < LIN; i++)
        TabelaNormal[i][0] = TabelaNormal[i-1][0] + 0.0397;

    for (i = 0; i < LIN; i++) {
        for (j = 1; j < COL; j ++) {
            TabelaNormal[i][j] = TabelaNormal[i][j-1] + 0.0040;
        }
    }

    for (i = 0; i < LIN; i++) {
        printf("%02d  ", i);
        for (j = 0; j < COL; j++)
            printf("%.4lf ", TabelaNormal[i][j]);
        printf("\n");
    }
}
