/**
 * 
 * autores:
 * Daniel Bou
 * Maurício Freire
 * Victor Gabriel
 * Problema C
*/

#include <stdio.h>

int main()
{
    int n, s = 0, i;
    scanf("%d", &n);
    int nuvens[n];
    for (i = 0; i < n; i++)
        scanf("%d", &nuvens[i]);

    for (i = 1; i < n; i++) {
        if (nuvens[i] == 0) {
            if (nuvens[i+1] == 0) {
                i++;
                s++;
            } else { s++; i++;}
        } else s++;
    }
    printf("%d\n", s);
    return 0;
}
