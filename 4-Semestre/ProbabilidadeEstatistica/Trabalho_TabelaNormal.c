/**
 * 
 * Considerações sobre compilar o código fonte pelo terminal do Linux:
 * algumas funções matemáticas não são reconhecidas pelo gcc, por isso
 * sugerimos usar o g++ para compilar o arquivo.c
 * No CodeBlocks, Windows, nenhum cuidado extra se mostrou necessário.
 * 
 * Trabalho de Probabilidade e Estatística II
 * Professor José Fontebasso Neto
 * Felipe Ferreira - Ciência da Computação 7223057
 * Maurício Freire - Ciência da Computação 2671844
 * 
 * Código fonte estará disponível em github.com/Dombrauskas após a data final de entrega.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Matriz que armazenará a Tabela Normal
double TabelaNormal[60][10]; 

double calculoIntervalo(double);
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
void graph1();
void graph2();
void graph3();

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
                printf("1 - Abaixo da Media"); graph1();
                printf("2 - Acima da Media "); graph2();
                printf("3 - Meio da curva? "); graph3();
                
                // Evita que digitação de letras sejam válidas.
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
                    printf("z = %.2lf\n", z);
                    printf("Interseccao na Tabela: ");
                    intersec(z, tipo_tabela);
                break;
                case 2:
                    z = Acima();
                    if (!isValid(z)) {
                        printf("\nValor obtido excede os limites da tabela!\n\n");
                        break;
                    }
                    printf("z = %.2lf\n", z);
                    printf("Interseccao na Tabela: ");
                    intersec(z, tipo_tabela);
                break;
                case 3:
                    z = 0;
                    double media[2], soma = 0;
                    int m;
                    bool flag = true;
                    Meio(media);

                    for (m = 0; m < 2; m++) {
                        if (!isValid(media[m])) {
                            printf("\nValor obtido excede os limites da tabela!\n\n");
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        printf("Media[1] = %.2lf\nMedia[2] = %.2lf\n", media[0], media[1]);
                        for (m = 0; m < 2; m++)
                            soma += intersecMedio(media[m], tipo_tabela);

                        printf("Soma dois intervalos: %.10lf\n", (1 - soma) < 0 ? (1 - soma) * - 1 : soma);
                    }
                break;
            }
        } else if (calc == 'N') {
            printf("Digite \'S\' para sair ou \'N\' para gerar outra tabela _");
            scanf(" %c", &calc);
            calc = toupper(calc);
            
            if (calc == 'S') finalizar = true;
            else if (calc == 'N') {
                /* 
                 * Automaticamente gera uma nova tabela diferente da anterior,
                 * se a primeira tabela escolhido foi a Acumulada, então será
                 * gerada uma Tabela Normal e vice-versa.
                */
                if (tipo_tabela == 'A') tipo_tabela = 'N';
                else tipo_tabela = 'A';
                
                /*
                 * Como a FGM() cria uma tabela baseada na normal 0.0000000000
                 * não é preciso chamá-la de novo, apenas exibir a TabelaNormal
                 * como ela é ou somar 0.5000000000 aos valores no printf já
                 * é o suficiente.
                */
                pp(tipo_tabela);
            }
        }
    }
    //bateu();
    return 0;
}

/*
 * Função Geradora da Matriz.
 * Salva os valores na tabela após serem calculados os intervalos com base na
 * tabela de normal (iniciada em 0.0000000000).
*/
void FGM()
{
    int i, j;
    double x;
    for (i = 0; i < 60; i++) {
        for (j = 0; j < 10; j++) {
            x = (i / 10.0) + (j / 100.0);
            TabelaNormal[i][j] = Simpson(x);
        }
    }
}

// Teste de precisão inicial - Não mais usada.
void bateu()
{
    if (TabelaNormal[0][1] == 0.0039893563)
        printf("\n\nBateu!!\n");
    else printf("\n\nAinda falta %.10lf\n", TabelaNormal[0][1] - 0.0039893563);
}

// Exibe a Tabela de Distribuição Normal.
void pp(char tt)
{
    int i, j;
    char espaco[] = {"    "};

    // Numeração colunas parte superior da tabela.
    printf("%s", espaco);
    for (i = 0; i < 10; i++)
        printf("      %d      ", i);
    printf("\n");

    // Imprime na tela a Tabela Acumulada (Iniciada em 0.5000000000).
    if (tt == 'A') {
        // Imprime o conteúdo da tabela.
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
        // Imprime o conteúdo da tabela.
        for (i = 0; i < 60; i++) {
            printf("%.1f ", i / 10.0);
            for (j = 0; j < 10; j++) {
                printf("%.10lf ", TabelaNormal[i][j]);
            }
            printf("\n");
        }
    }

    // Numeração colunas parte inferior da tabela.
    printf("%s", espaco);
    for (i = 0; i < 10; i++)
        printf("      %d      ", i);

    printf("\n");
}

// Regra de Simpson para aproximação da curva.
double Simpson(double x)
{
    int i;
    double valor_tabela = 0.0;
    double a = 0, b = x;
    double h = (b - a) / 1000; // 1000 é mínimo necessário para de iterações para chegar aos valores corretos.

    valor_tabela += calculoIntervalo(a) + calculoIntervalo(b);

    for (i = 1; i <= (1000 / 2); i++)
        valor_tabela += calculoIntervalo(a + h * (2 * i - 1)) * 4;
    
    for (i = 1; i <= (1000 / 2) - 1; i++)
        valor_tabela += calculoIntervalo(a + h * (2 * i)) * 2;

    return valor_tabela * ((b - a) / 3000);
}


// Calcula os intervalos da tabela pelo calculo da Distribuição Normal.
double calculoIntervalo(double x)
{
    return exp(-pow(x / sqrt(2), 2)) / sqrt(2 * 3.14159265359);
}

// Exibe o valor correspondente na Tabela Normal para o z calculado.
void intersec(double z, char tt)
{
    if (z < 0) 
        // Se o z for negativo será convertido para seu correspondente positivo.
        z *= - 1;
    
    int lin = z * 10; // Faz os 2 primeiros digitos em inteiro para achar a linha. - 1.43 = 14;
    int col = z * 100 - lin * 10; // Pega o último digito para a coluna. - 1.43 = 3;
    
    /*
     * Como a tabela gerada é baseada apenas na normal 0.0000000000, para exibir
     * o valor da intersecção da Acumulada é preciso somar 0.5000000000 ao valor
     * contido na TabelaNormal.
    */
    if (tt == 'N')
        printf("%.10lf\n", TabelaNormal[lin][col]);
    else printf("%.10lf\n", TabelaNormal[lin][col] + 0.5);
}

// Idem intersec - Não mais usada.
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
 * Calcula a área em porcentagem do gráfico.
 * Calcula uma área sob a curva que esteja após o ponto médio.
*/
double Acima()
{
    bool coerente = true;
    double desvio, media, x;
    char lixo[100], lx[10]; // Evitam que caracteres não numéricos entrem no cálculo.

    while (coerente) {
        printf("Informe a media: ");
        scanf(" %9s[^\n]", lx);
        strcpy(lixo, lx);
        printf("Informe o desvio: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " "); // Separa a digitação anterior da atual.
        strcat(lixo, lx);
        printf("Informe o valor procurado: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " "); // Separa a digitação anterior da atual.
        strcat(lixo, lx);

        /*
         * Passam-se os valores informados para os formatos corretos, caso
         * algum formato não seja atendido como o esperado todo processo 
         * será refeito.
        */
        if ((sscanf(lixo, "%lf %lf %lf", &media, &desvio, &x)) < 3)
            printf("\nDigitação Invalida!\n\n");
        else {
            coerente = x > media ? false : true;
            if (coerente) printf("\nO valor procurado deve ser "
                "MAIOR que a media (> %lf)!\n\n", media);
        }
    }
    return (x - media) / desvio;
}

/*
 * Calcula a área em porcentagem do gráfico.
 * Calcula uma área sob a curva que esteja antes do ponto médio.
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
        strcat(lixo, " "); // Separa a digitação anterior da atual
        strcat(lixo, lx);
        printf("Informe o valor procurado: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " "); // Separa a digitação anterior da atual
        strcat(lixo, lx);
        
        /*
         * Passam-se os valores informados para os formatos corretos, caso
         * algum formato não seja atendido como o esperado todo processo 
         * será refeito.
        */
        if ((sscanf(lixo, "%lf %lf %lf", &media, &desvio, &x)) < 3)
            printf("\nDigitação Invalida!\n\n");
        else {
            coerente = x < media ? false : true;
            if (coerente) printf("\nO valor procurado deve ser "
                "MENOR que a media (< %lf)!\n\n", media);
        }
    }
    return ((x - media) / desvio) * - 1;
}

/*
 * Calcula a área em porcentagem do gráfico.
 * Calcula uma área sob a curva que compreenda o ponto médio.
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
        strcat(lixo, " "); // Separa a digitação anterior da atual
        strcat(lixo, lx);
        printf("Informe dois valores\nPrimeiro valor: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " "); // Separa a digitação anterior da atual
        strcat(lixo, lx);
        printf("Segunda valor: ");
        scanf(" %9s[^\n]", lx);
        strcat(lixo, " "); // Separa a digitação anterior da atual
        strcat(lixo, lx);
        
        /*
         * Passam-se os valores informados para os formatos corretos, caso
         * algum formato não seja atendido como o esperado todo processo 
         * será refeito.
        */
        if ((sscanf(lixo, "%lf %lf %lf %lf", &media, &desvio, &x1, &x2)) < 4)
            printf("\nDigitacao Invalida!\n\n");
        else {
            // Faz com que x1 seja menor que a média e x2 seja maior.
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
 * Verifica se o valor de z é um intervalo válido
 * presente na tabela (entre 0.0 e 5.9)
*/
bool isValid(double z)
{
    if (z < 0 && z > -6.0) z *= -1;
    if (z < -5.9 ||  z > 5.9) return false;
    else return true;
}

// Decoração
void graph1()
{
    printf("  1   _________     |2    _________     |3    _________    \n");
}

// Decoração
void graph2()
{
    printf("     / ##M|e   \\    |    /   M|e## \\    |    / |#M|e#| \\   \n");
}

// Decoração
void graph3()
{
    printf("   _/__##dia____\\_  |  _/____dia##__\\_  |  _/__|#dia#|__\\_ \n\n");
}


