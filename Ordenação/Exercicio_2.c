// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void insercao(int *);
void ordenacao(int *);

int main()
{
	int n, i, j, vet[TAM+1], x, min;
	srand(time(NULL));
    
    printf("Primeiro Vetor\n");
	for (i = 0; i < TAM; i++) {
		vet[i] = rand() % 999;
		printf("vet[%d]: %3d\n", i, vet[i]);
	}
	ordenacao(vet);
	printf("\nordenacao\n");
    for (i = 0; i < TAM; i++) {
		printf("vet[%d]: %3d\n", i, vet[i]);
	}
	
	insercao(vet);    
	printf("\nVetor Final\n");
	for (i = 0; i <= TAM; i++) {
		printf("vet[%d]: %3d\n", i, vet[i]);
	}
	return 0;
}

void insercao(int v[TAM+1])
{
	int i, j, min, x, n;
	printf("\nInclua um numero: ");
	scanf("%d", &n);
	v[TAM] = n;
	
	printf("Numero incluido\n");
	for (i = 0; i < TAM+1; i++) {
		printf("vet[%d]: %d\n", i, v[i]);
	}
	
    for (i = 0; i <= TAM-1; i++) {
        min = i;
    	for (j = i+1; j <= TAM; j++){
            if (v[j] < v[min])
            min = j;
    	}
    	x = v[min];
    	v[min] = v[i];
    	v[i] = x;
    }
}

void ordenacao(int *vet)
{
    int aux, i, j;
    for (i = 1; i < TAM; i++) {
		aux = vet[i];
		j = i - 1;
		while ((j >= 0) && (vet[j] > aux)) {
			vet[j + 1] = vet[j];
			j--;
		}
		vet[j + 1] = aux;
	}
}
