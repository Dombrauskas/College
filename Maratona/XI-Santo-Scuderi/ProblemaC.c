/**
 * Author Maurício
 * Criptografia DRF: A criptografia DRF é um novo tipo de criptografia. Dada
 * uma string criptografada (que chamaremos de mensagem DRF), o processo de
 * descriptografia envolve três etapas: Dividir, Rotacionar e Fundir. Este processo é descrrito no seguinte exemplo com a mensagem DRF
 * "EWPGAJRB":
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
    char ch = 'A', dfr[10], m1[5], m2[5];
    
    do {
        for (i = 0; i < 10; i++) {
            scanf("%c", &dfr[i]);
            if (dfr[i] == '\n') break;
        }
    } while (i % 2 != 0);
    
    for (j = 0, k = i / 2; j < i / 2, k < i; ++j, ++k) {
        m1[j] = dfr[j];
        m2[j] = dfr[k];
    }
    
    for (j = 0; j < i / 2; j++) {
        m1[j] = toupper(m1[j]);
        printf("%c", m1[j]);
    }
    printf("\n");
    for (j = 0; j < i / 2; j++) {
        m2[j] = toupper(m2[j]);
        printf("%c", m2[j]);
    }
    
    j = rotaciona(m1, i);
    k = rotaciona(m2, i);
    
    fundir(m1, j, i);
    fundir(m2, k, i);
    return 0;
}

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
    
    printf("%d\n", r);
    return r;
}

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
