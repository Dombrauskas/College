#include <stdio.h>

int main()
{
    int n, s = 0, i;
    scanf("%d", &n);
    int nuvens[n];
    for (i = 0; i < n; i++)
        scanf("%d", &nuvens[i]);


    for (i = 0; i < n; i++) {
        if (nuvens[i] == 0)
            s++;
            if (nuvens[i-1] == 0 && i > 0)
                continue;
    }
    printf("%d\n", s);
    return 0;
}
