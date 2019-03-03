/**
 * Author Maurício
 * Criptografia DRF: A criptografia DRF é um novo tipo de criptografia. Dada
 * uma string criptografada (que chamaremos de mensagem DRF), o processo de
 * descriptografia envolve três etapas: Dividir, Rotacionar e Fundir. Este
 * processo é descrrito no seguinte exemplo com a mensagem DRF "EWPGAJRB":
 * Dividir - Primeiro, divida a mensagem pela metade para "EWPG" e "AJRB".
 * Rotacionar - Para cada metade, calcule seu valor de rotação somando os
 * valores de cada caractere (A = 0, B = 1, ..., Z = 25). Os valores de
 * rotação de "EWPG" é 4 + 22 + 15 + 6 = 47. Rotacione cada caractere em "EWPG
 * 47 posições para frente (o caractere seguinte a Z é o A) para obter a nova
 * string "ZRKB". Seguindo o mesmo processo em "AJRB" resulta em "BKSC".
 * Fundir - O último passo é combinar essas novas strings ("ZRKB" e "BKSC")
 * rotacionando cada caractere na primeira string pelo valor do caractere
 * correspondente na segunda string. Para a primeira posição, girar 'Z' por
 * 'B' significa movê-lo para frente 1 caractere, o que o torna o 'A'.
 * Continuando esse processo para cada caractere resulta na mensagem final
 * descriptografada, "ABCD".
 */

//                                      AINDA NÂO FINALIZADO
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int rotaciona(char [], int);
void fundir(char[], int, int);

int main()
{
    int i, j, k;
    char ch = 'A', drf[15000], m1[7500], m2[7500], *pm1, *pm2;
    
    do {
        i = 0;
        for (i = 0; i < 15000; i++) {
            scanf("%c", &drf[i]);
            if (drf[i] == ' ') i--;
            if (drf[i] == '\n') break;
        }
        if (drf[i] == '\n' && i % 2 == 0)
            i--;
    } while (i % 2 != 0);
    
    // Divide a mensagem em duas partes iguais.
    // split the message in two equal shares.
    for (j = 0, k = i / 2; j < i / 2, k < i; ++j, ++k) {
        m1[j] = drf[j];
        m2[j] = drf[k];
    }
    
    // Exibe a primeira metade.
    // Shows the first half.
    for (j = 0; j < i / 2; j++) {
        m1[j] = toupper(m1[j]);
        printf("%c", m1[j]);
    }
    
    printf("\n");
    // Exibe a segunda metade.
    // Shows the second half.
    for (j = 0; j < i / 2; j++) {
        m2[j] = toupper
        (m2[j]);
        printf("%c", m2[j]);
    }
    
    j = rotaciona(m1, i);
    k = rotaciona(m2, i);
    
    // Ponteiros das metades da mensagem.
    // Pointer of the message halves.
    pm1 = m1;
    pm2 = m2;
    
    fundir(m1, j, i);
    fundir(m2, k, i);
    
    printf("\nMensagem descriptografada: ");
    // Descriptografa a mensagem.
    // Decrypts the message.
    for (k = 0; pm1[k]; k++) {
        int x, y;
        x = (int) pm1[k] - 65;
        y = (int) pm2[k] - 65;
        if (x + y == 26)
            printf("%c", pm1[k] - x);
        else if (x + y > 26)
            printf("%c", pm1[k] + y - 26);
        else
            printf("%c", pm1[k] + y);
    }
    return 0;
}

// Determina quantas posições cada caractere deve ser avançado para frente.
// Determine how many positions each character must move forwards.
int rotaciona(char t1[], int a)
{
    int i, j, v[26], s = 0, r = 0;
    
    printf("\n");
    for (i = 0; i < 26; i++) 
        v[i] = (int) ('A' + i) - 65;
    
    for (i = 0; i < 26; i++)
        for (j = 0; j < a / 2; j++) 
            if (v[i] == (int) t1[j] - 65) {
                r += v[i];
                break;
            }
    
    return r;
}

// Soma as posições necessárias para formar uma nova string.
// Sum up the positions in order to create a new string.
void fundir(char s1[], int r, int a)
{
    int i, j, v[26];
    
    r %= 26;
    r = 26 - r;
    
    for (i = 0; i < a / 2; i++) {
        if ((int) s1[i] - 65 < r) {
            s1[i] = s1[i] + (26 - r);
        } else {
            s1[i] = s1[i] - r;
        }
    }
        
    for (i = 0; i < a / 2; i++)
        printf("%c", s1[i]);
    
    printf("\n");
}
