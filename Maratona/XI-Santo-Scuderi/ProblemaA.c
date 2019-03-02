/**
 * 
 * author Mauricio Freire
 * Zero Perdido: Você está escrevendo os inteiros positivos em crescente a partir
 * de 1. Mas você nunca aprendeu o dígito zero e, portanto, omite qualquer
 * número que contém o dígito zero em qualquer posição. Os primeiros dez inteiros
 * que você escreve são: 1, 2, 3, 4, 5, 6, 7, 8, 9, 11.
 * Você acaba de escrever um inteiro N (que garantidamente não possui um zero).
 * Qual será o próximo inteiro que você escreverá?
 * Zero Lost: Every number must have no zeros.
*/
#include <stdio.h>

int zeros(int);

int main()
{
    int n, soma;
    // Garante que o número escolhido seja positivo.
    // Ensure the chosen number to be positive.
    do {
        scanf("%d", &n);
    } while (n < 1 || n > 999999);
    
    // Antes de passar o número para a função é somado 1 para evitar retorno de
    // múltiplos de 10.
    // Before being passed as an argurment to the function it is added 1 in order
    // to avoid multiples of 10.
    soma = zeros(++n);
    printf("%d\n", soma);
    return 0;
}

int zeros(int x)
{
    int a, i, s = 10;
    // Estabelece qual o tamanho ideal para o vetor que receberá o número escolhido.
    // Define which is the ideal length to the array that shall receive the
    // chosen number.
    if (x < 10) 
        a = 1;
    else if (x > 9 && x <= 99) 
        a = 2;
    else if (x > 99 && x <= 999)
        a = 3;
    else if (x > 999 && x <= 9999) 
        a = 4;
    else if (x > 9999 && x <= 99999)
        a = 5;
    else if (x > 99999 && x <= 999999)
        a = 6;
    int zero[a];
    
    // Separa o número em parte: unidade, dezena, centena...
    // Split the number apart: unity, tens, hundreds... 
    for (i = a - 1; i >= 0; i--) {
        zero[i] = x % 10;
        x /= 10;
    }
    
    // Elimina os zeros (se houver).
    // Erases the zeros (if it has).
    for (i = 0; i < a; i++)
        if (zero[i] == 0) 
            zero[i] += 1;
    
    // Desfaz o vetor em um inteiro.
    // Turns the array back into an integer.
    x = zero[a-1];
    for (i = a - 2; i >= 0; i--) {
        x += (zero[i] * s);
        s *= 10;
    }
    return x;
}
