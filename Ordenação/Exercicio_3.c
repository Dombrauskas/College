// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <time.h>
#include <stdio.h>
#define TAM 100

void decrescente(int *);

int main()
{
	int n, i, j, vet[TAM], x, min;
	time_t t;
	srand((unsigned) time(&t));
    
    printf("Vetor Aleatorio\n");
	for (i = 0; i < TAM; i++) {
		vet[i] = rand() % 999;
		printf("vet[%2d]: %3d\n", i, vet[i]);
	}
    
    decrescente(vet);
    
	printf("\nVetor Decrescente\n");
	for (i = 0; i < TAM; i++) {
		printf("vet[%2d]: %3d\n", i, vet[i]);
	}
	return 0;
}

void decrescente(int *vet)
{
	int i, j, temp;

	for (i = 0; i < TAM - 1; i++){
        for (j = (i+1); j < TAM; j++) {
            if (vet[j] > vet[i]) {
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}
