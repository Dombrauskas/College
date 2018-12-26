// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>
#include <time.h>
#define ARQ "vetor.bin"
#define SSB "SortSelection.bin"
#define TXT "timeSelection.txt"
#define TAM 100000

void selectSort(int *, int);

int main()
{
    FILE *fp, *ft, *fq;
    int i, vet[TAM];
    clock_t start_t;

	if ((fp = fopen(ARQ,"rb")) == NULL) {
		printf("Nao foi possivel abrir o arquivo %s!\n", ARQ);
		return;
	}
	
	while (fread(vet, TAM, sizeof(int), fp) > 0) {
//		printf("%d\n", vet[i]);
	}
	printf("Ordenando o vetor de %d posicoes!\nAguarde...\n\n", TAM);

	start_t = clock();
	selectSort(vet, TAM-1);
	
	ft = fopen(TXT,"w");
	fprintf(ft, "%lf %s", (double)(clock() - start_t) / CLOCKS_PER_SEC, "segundos");

	fq = fopen(SSB,"wb");
	fwrite(vet, TAM, sizeof(int), fq);

	printf("Foram gravados os arquivos %s e %s!\n", SSB, TXT);
	fclose(fp);
	fclose(ft);
	fclose(fq);
	
	return 0;
}

void selectSort(int *vet, int size)
{
	int i, j, x, z;
	for (i = 0; i < size - 1; i++) {
		z = i;
		for (j = i + 1; j < size; j++) {
			if(vet[j] < vet[z])
				z = j;
		}
		if (vet[i] != vet[z]) {
			x = vet[i];
			vet[i] = vet[z];
			vet[z] = x;
		}
	}
}
