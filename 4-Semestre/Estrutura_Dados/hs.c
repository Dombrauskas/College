#include <stdio.h>
#include <math.h>
#define M 7

int adh(char *);
int sdh(char *);

int main()
{
	int i;
	char * nomes[] = { "Ciro", "Fernando", "Piva", "Ronaldo", "Marquinhos", "Joao", "Serafim", "Julio", "Claudio", "Thiago", "Guerreiro" };

	printf("ADH\n");
	for (i = 0; i < 11; i++) {
		printf("%s (%d)\n", chaves[i], adh(nomes);
	}

	printf("SDH\n");
	for (i = 0; i < 11; i++) {
		printf("%s (%d)\n", chaves[i], adh(nomes);
	}
	return 0;
}

int adh(char * chv)
{
	int i, soma = 0;
	for (i = 0; chv[i] != '\0'; i++) {
		soma += chv[i] << (i % 8);
	}
	return (soma % M);
}

int sdh(char * chv)
{
	int i, soma = 0;
	for (i = 0; chv[i] != '\0'; i++) {
		soma += chv[i];
	}
	return (soma % M);

}
