// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>
#include <time.h>
#define ARQ "vetor.bin"
#define SIB "SortInsertion.bin"
#define TXT "timeInsert.txt"
#define TAM 100000

void insertSort(int *, int);

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
	insertSort(vet, TAM);
	
	ft = fopen(TXT,"w");
	fprintf(ft, "%lf %s", (double)(clock() - start_t) / CLOCKS_PER_SEC, "segundos");

	fq = fopen(SIB,"wb");
	fwrite(vet, TAM, sizeof(int), fq);
	
	printf("Foram gravados os arquivos %s e %s!\n", SIB, TXT);
	fclose(fp);
	fclose(ft);
	fclose(fq);
	
	return 0;
}

void insertSort(int *vet, int size)
{
	int aux, i, j;

    for (i = 1; i < size; i++) {
		aux = vet[i];
		j = i - 1;
		while ((j >= 0) && (vet[j] > aux)) {
			vet[j + 1] = vet[j];
			j--;
		}
		vet[j + 1] = aux;
	}
}
