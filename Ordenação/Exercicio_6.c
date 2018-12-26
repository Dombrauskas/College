// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>
#include <time.h>
#define ARQ "vetor.bin"
#define TAM 100000

int main()
{
    FILE *fp;
    int i, vet[TAM];
	srand(time(NULL));
	
	for (i = 0; i < TAM; i++) {
		vet[i] = rand() % TAM;
//		printf("vet[%d]: %d\n", i, vet[i]);
	}
	
	if ((fp = fopen(ARQ,"wb")) == NULL) {
		printf("Nao foi possivel criar o arquivo %s!\n", ARQ);
		return;
	} 
	
	fwrite(vet, TAM, sizeof(int), fp);
	printf("Arquivo %s criado com sucesso!\n", ARQ);
	fclose(fp);
	
	return 0;
}
