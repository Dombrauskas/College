#include <stdio.h>

int main(){

    int m,n,a,b,j,f,k1=0, k2=0, i;


    scanf("%d %d",&i,&f);
    scanf("%d %d",&a, &b);
    scanf("%d %d",&m, &n);

    int dm[m], dl[n];

    for(j=0; j<m; j++)
    {
        scanf("%d",&dm[j]);
        dm[j]+=a;
        if(dm[j]>=i && dm[j]<=f)
        {
            k1++;
        }
    }

    for(j=0; j<n; j++)
    {
        scanf("%d",&dl[j]);
        dl[j]+=b;
        if(dl[j]>=i && dl[j]<=f)
        {
            k2++;
        }
    }
    printf("%d\n",k1);
    printf("%d\n",k2);

    return 0;

}
