/**
 * 
 * author Mauricio Freire
 * Enfeitando o Bolo: Um confeiteiro decorando um bolo enorme, cobrindo a 
 * superfície retangular do bolo com glacê. Para isso, ele mistura açúcar de
 * confeiteiro com suco de limão e corante alimentício, para produzir três tipos
 * de cobertura: amarelo, rosa e branco. Essas cores são identificadas pelos
 * números 0 para amarelo, 1 para rosa e 2 para branco.
 * Para obter um padrão, ele divide a superfície do bolo em N listras verticais
 * de largura A centímetros e N listras horizontais de altura B centímetros, para
 * algum inteiro positivo N. Essas listras dividem a superfície do bolo em N x N
 * retângulos. A intersecção da faixa vertical i e a faixa horizontal j tem
 * número de cor (i + j) mod 3 para todos os 1 <= i, j <= N. Para preparar o
 * glacê, o confeiteiro quer saber a superfície total em centímetros quadrados
 * que deve ser colorido em cada uma das três cores, e pede sua ajuda.
 * Decorating the Cake: the area of a cake to be decorated in three different
 * colours in an area of square centimetres.
*/
#include <stdio.h>

int main()
{
    int a, b, n, i, j, cor, y, p, w;
    // Quantidade de cores.
    // Quantity of colours.
    y = p = w = 0;
    
    // Listras tanto verticais quanto horizontais.
    // Both vertical and horizontal stripes.
    scanf("%d", &n);
    // Largura das listras.
    // Width of the stripes.
    scanf("%d", &a);
    // Altura das listras.
    // Heigth of the stripes.
    scanf("%d", &b);
    
    for (i = 0; i < n; i ++)
        for (j = 0; j < n; j++) {
            cor = (i + j) % 3;
            // Seleciona as cores: amarelo, rosa e branco.
            // Select the colours: yellow, pink and white.
            switch (cor) {
                case 0:
                    y++;
                    break;
                case 1:
                    p++;
                    break;
                case 2:
                    w++;
                    break;
            }
        }
    
    // Múltiplica a quantidade de cores pela área (altura x largura).
    // Multiplies the quantity of colours by the area (height x width).
    printf("%d %d %d\n", y * a * b, p * a * b, w * a * b);
}
