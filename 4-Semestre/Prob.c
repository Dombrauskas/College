#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

double TabelaNormal[60][10];

double df(double);
double DF(double);
double Simpson(double);
void pp(char);
void bateu();
void intersec(double, char);
double Abaixo();
double Acima();
void Meio(double *);
void FGM();
bool isValid(double);
double intersecMedio(double, char);

int main()
{
    int it = 0, i, j;
    double x;

    char tipo_tabela, calc = 'q';
    bool pass = true, finalizar = false;
    double z;


    while (pass) {
        do {
            printf("Qual formato de tabela quer gerar, Acumulativa (A) ou Normal (N)? ");
            scanf(" %c", &tipo_tabela);
            tipo_tabela = toupper(tipo_tabela);
            if (tipo_tabela == 'N' || tipo_tabela == 'A')
                pass = true;
            else
                pass = false;
        } while (!pass);
        pass = !pass;
    }

    FGM();
    pp(tipo_tabela);

    while (!finalizar) {
        printf("\nDeseja calcular? S/N\t");
        scanf(" %c", &calc);
        calc = toupper(calc);
        if (calc == 'S') {
            int tipo_calculo = 0, x = 1;
            char lixo[100];
            while (tipo_calculo < 1 || tipo_calculo > 3) {
                printf("Qual tipo de calculo quer fazer?\n");
                printf("1 - Abaixo da Media\n2 - Acima da Media\n3 - Meio da curva?\n\n");
                // Evita digita��o de letras.
                scanf(" %99s[^\n]", lixo);
                sscanf(lixo, "%d", &tipo_calculo);
            }
            switch (tipo_calculo) {
                case 1:
                    z = Abaixo();
                    if (!isValid(z)) {
                        printf("\nValor obtido excede os limites da tabela!\n\n");
                        break;
                    }
                    printf("%.2lf\n", z);
                    printf("Interseccao na Tabela: ");
                    intersec(z, tipo_tabela);
                break;
                case 2:
                    z = Acima();
                    if (!isValid(z)) {
                        printf("\nValor obtido excede os limites da tabela!\n\n");
                        break;
                    }
                    printf("%.2lf\n", z);
                    printf("Interseccao na Tabela: ");
                    intersec(z, tipo_tabela);
                break;
                case 3:
                    z = 0;
                    double media[2], soma = 0;
                    int m;
                    bool flag = true;
                    Meio(media);

                    for (m = 0; m < 2; m++)
                        if (!isValid(media[m])) {
                            printf("\nValor obtido excede os limites da tabela!\n\n");
                            flag = false;
                            break;
                        }

                    if (flag) {
                        printf("Media[1] = %.2lf\nMedia[2] = %.2lf\n", media[0], media[1]);
                        for (m = 0; m < 2; m++)
                            soma += intersecMedio(media[m], tipo_tabela);
                            //intersec(media[m], tipo_tabela);

                        printf("Soma dois intervalos: %.10lf\n", (1 - soma) < 0 ? (1 - soma) * - 1 : soma);
                        // printf("Interseccao na Tabela: ");
                        // intersec(z, tipo_tabela);
                    }
                break;
            }
        } else if (calc == 'N') {
            printf("Digite \'S\' para sair ou \'N\' para gerar outra tabela _");
            scanf(" %c", &calc);
            calc = toupper(calc);
            if (calc == 'S') finalizar = true;
            else if (calc == 'N') {
                if (tipo_tabela == 'A') tipo_tabela = 'N';
                else tipo_tabela = 'A';
                pp(tipo_tabela);
            }
        }
    }
    //bateu();
    return 0;
}

/*
 * Fun��o Geradora da Matriz.
 * Salva os valores na tabela ap�s serem calculados os intervalos com base na
 * tabela de normal (iniciada em 0.0000000000).
*/
void FGM()
{
    int i, j;
    double x;
    for (i = 0; i < 60; i++) {
        for (j = 0; j < 10; j++) {
            x = (i / 10.0) + (j / 100.0);
            TabelaNormal[i][j] = DF(x);
        }
    }
}

// Teste
void bateu()
{
    if (TabelaNormal[0][1] == 0.0039893563)
        printf("\n\nBateu!!\n");
    else printf("\n\nAinda falta %.10Lf\n", TabelaNormal[0][1] - 0.0039893563);
}

// Exibe a Tabela de Distribui��o Normal.
void pp(char tt)
{
    int i, j;
    char espaco[] = {"    "};

    // Imprime na tela a Tabela Acumulada (Iniciada em 0.5000000000).
    if (tt == 'A') {
        // Numera��o colunas parte superior da tabela.
        printf("%s", espaco);
        for (i = 0; i < 10; i++)
            printf("      %d      ", i);
        printf("\n");

        for (i = 0; i < 60; i++) {
            printf("%.1f ", i / 10.0);
            for (j = 0; j < 10; j++) {
                printf("%.10lf ", TabelaNormal[i][j] + 0.5);
            }
            printf("\n");
        }
    }
    // Imprime na tela a Tabela Normal (Iniciada em 0.0000000000).
    else {
        printf("%s", espaco);
        for (i = 0; i < 10; i++)
            printf("      %d      ", i);
        for (i = 0; i < 60; i++) {
            printf("%.1f ", i / 10.0);
            for (j = 0; j < 10; j++) {
                printf("%.10lf ", TabelaNormal[i][j]);
            }
            printf("\n");
        }
    }

    // Numera��o colunas parte inferior da tabela.
    printf("%s", espaco);
    for (i = 0; i < 10; i++)
        printf("      %d      ", i);

    printf("\n");
}

// Calcula os intervalos da tabela.
double DF(double x)
{
    long double valor_tabela = 0.0;
    double a = 0, b = x;
    double h = (b - a) / 1000;
    int i;

    valor_tabela += Simpson(a) + Simpson(b);

    for (i = 1; i <= (1000 / 2); i++)
        valor_tabela += Simpson(a + h * (2 * i - 1)) * 4;
    for (i = 1; i <= (1000 / 2) - 1; i++)
        valor_tabela += Simpson(a + h * (2 * i)) * 2;

    return valor_tabela * ((b - a) / 3000);
}

/*
double df(double x)
{
    double a = 0, b = x, tt = 0;
    long n = 1000, i;
    double h = (b - a) / n;
    tt += Simpson(a) + Simpson(b);
    for (i = 0; i <= (n / 2); i++)
        tt += Simpson(a + h * (2 * i - 1)) * 4;
    for (i = 0; i <= ((n / 2) - 1); i++)
        tt += Simpson(a + h * (2 * i)) * 2;
    tt = tt * ((b - a) / (3 * n));
    return tt;
}
*/

// Regra de Simpson.
double Simpson(double x)
{
    return exp(-pow(x / sqrt(2), 2)) / sqrt(2 * 3.14159265359);
}

// Exibe o valor correspondente na Tabela Normal para o z calculado.
void intersec(double z, char tt)
{
    if (z < 0) z *= - 1;
    int lin = z * 10;
    int col = z * 100 - lin * 10;
    if (tt == 'N')
        printf("%.10Lf\n", TabelaNormal[lin][col]);
    else printf("%.10Lf\n", TabelaNormal[lin][col] + 0.5);
}


double intersecMedio(double z, char tt)
{
    if (z < 0) z *= - 1;
    int lin = z * 10;
    int col = z * 100 - lin * 10;
    if (tt == 'N')
        return TabelaNormal[lin][col];
    else return TabelaNormal[lin][col] + 0.5;
}

/*
 * Calcula a �rea em porcentagem do gr�fico.
 * Calcula uma �rea sob a curva que esteja ap�s o ponto m�dio.
*/
double Acima()
{
    bool coerente = true;
    double desvio, media, x;
    char lixo[100], lx[10];

    while (coerente) {
        printf("Informe a media: ");
        scanf(" %9s[^\n]", lx);
        strcpy(lixo, lx);
        printf("Informe o desvio: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        printf("Informe o valor procurado: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        if ((sscanf(lixo, "%lf %lf %lf", &media, &desvio, &x)) < 3)
            printf("\nDigita��o Invalida!\n\n");
        else {
            coerente = x > media ? false : true;
            if (coerente) printf("\nO valor procurado deve ser "
                "MAIOR que a media (> %lf)!\n\n", media);
        }
    }
    return (x - media) / desvio;
}

/*
 * Calcula a �rea em porcentagem do gr�fico.
 * Calcula uma �rea sob a curva que esteja antes do ponto m�dio.
*/
double Abaixo()
{
    bool coerente = true;
    double desvio, media, x;
    char lixo[100], lx[10];

    while (coerente) {
        printf("Informe a media: ");
        scanf(" %9s[^\n]", lx);
        strcpy(lixo, lx);
        printf("Informe o desvio: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        printf("Informe o valor procurado: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        if ((sscanf(lixo, "%lf %lf %lf", &media, &desvio, &x)) < 3)
            printf("\nDigita��o Invalida!\n\n");
        else {
            coerente = x < media ? false : true;
            if (coerente) printf("\nO valor procurado deve ser "
                "MENOR que a media (< %lf)!\n\n", media);
        }
    }
    return ((x - media) / desvio) * - 1;
}

/*
 * Calcula a �rea em porcentagem do gr�fico.
 * Calcula uma �rea sob a curva que compreenda o ponto m�dio.
*/
void Meio(double * z)
{
    bool coerente = true;
    double desvio, media, x1, x2;
    char lixo[100], lx[10];

    while (coerente) {
        printf("Informe a media: ");
        scanf(" %9s[^\n]", lx);
        strcpy(lixo, lx);
        printf("Informe o desvio: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        printf("Informe dois valores\nPrimeiro valor: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        printf("Segunda valor: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " ");
        strcat(lixo, lx);
        if ((sscanf(lixo, "%lf %lf %lf %lf", &media, &desvio, &x1, &x2)) < 4)
            printf("\nDigitacao Invalida!\n\n");
        else {
            if (x1 > x2) {
                int aux = x1;
                x1 = x2;
                x2 = aux;
            }
            coerente = (x1 < media && x2 > media) ? false : true;
        }
    }

    z[0] = (x1 - media) / desvio;
    z[1] = (x2 - media) / desvio;
    //return z;
}

/*
 * Verifica se o valor de z � um intervalo v�lido
 * presente na tabela (entre 0.0 e 5.9)
*/
bool isValid(double z)
{
    if (z < 0 && z > -6.0) z *= -1;
    if (z < -5.9 ||  z > 5.9) return false;
    else return true;
}
