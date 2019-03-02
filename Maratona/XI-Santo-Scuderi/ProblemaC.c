/**
 *                                                  PROGRAMA AINDA NÃO FINALIZADO!!
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int rotaciona(char [], int);
//int rotaciona();

int main()
{
    int i, j, k;
    char ch = 'A', dfr[10], m1[5], m2[5];
    
    /*    
    for (i = 0; i < 26; i++) 
        printf("%c\t%d\n", (char) v[i] + 65, v[i]);
    */
    do {
        for (i = 0; i < 10; i++) {
            scanf("%c", &dfr[i]);
            if (dfr[i] == '\n') break;
        }
    } while (i % 2 != 1);
    
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
    return 0;
}

int rotaciona(char t1[], int a)
{
    int i, v[26], s = 0, r = 0;
    
    printf("\n");
    for (i = 0; i < 26; i++)
        v[i] = (int) ('A' + i) - 65;
    
    do {
        for (i = 0; i < 26; i++)
            if (v[i] == (int) t1[i]) {
                r += v[i];
                break;
            }
        s++;
    } while (s < a / 2);
    
    printf("%d\n", r);
    return 0;
}
