// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>
#include <time.h>
#define ARQ "vetor.bin"
#define QST "QuickSort.bin"
#define TXT "timeQuick.txt"
#define TAM 100000

void quickSort(int *, int, int);

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
	quickSort(vet, 0, TAM-1);
	
	
	ft = fopen(TXT,"w");
	fprintf(ft, "%lf %s", (double)(clock() - start_t) / CLOCKS_PER_SEC, "segundos");

	fq = fopen(QST,"wb");
	fwrite(vet, TAM, sizeof(int), fq);

	printf("Foram gravados os arquivos %s e %s!\n", QST, TXT);
	fclose(fp);
	fclose(ft);
	fclose(fq);
	
	return 0;
}

void quickSort(int *vet, int esq, int dir)
{
	int pivo = esq, i, ch, j;
    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (vet[j] < vet[pivo]) {
            ch = vet[j];
            while (j > pivo) {
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }

    if (pivo -1 >= esq) {
        quickSort(vet, esq, pivo-1);
    }
    if (pivo +1 <= dir) {
        quickSort(vet, pivo+1, dir);
    }
}
