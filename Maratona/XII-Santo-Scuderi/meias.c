#include <stdio.h>

int main()
{

    int n, i, k=0, j;
    int vet[100];

    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&vet[i]);
    }

    for(i=0; i<n; i++)
    {
        for(j=(i+1); j<n; j++)
        {
            if(vet[i]==vet[j] && vet[i]!=0 && vet[j]!=0){
            vet[i]=0;
            vet[j]=0;
            k++;
            break;
            }
        }
    }
    printf("%d\n",k);
}
