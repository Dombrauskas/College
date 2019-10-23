// gcc -o nome_arquivo nome_arquivo.c (-lm)
// ./nome_arquivo

#include <stdio.h>
#include <math.h>
#define NB 16

int mq(int, int);

int main()
{
	int k, m;
	printf("Informe a chave: ");
	scanf("%d", &k);
	while (k != -1) {
		printf("Informe o numero de encaixes da tabela hashing: ");
		scanf("%d", &m);
		printf("mq(%d, %d) = %d\n", k, m, mq(k,m));

		printf("\nInforme a chave: ");
		scanf("%d", &k);
	}
}

int mq(int k, int m)
{
	int x, dslq, bits;
	k = k * k;
	x = (int) (log10(m) / log10(2));
	dslq = NB / 2 - (x - x / 2);
	k = k >> dslq;
	bits = (int) pow(2, x) - 1;
	return (k & bits);
}

