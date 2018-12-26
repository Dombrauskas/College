// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>
#define QUICK "timeQuick.txt"
#define SELECT "timeSelection.txt"
#define BUBBLE "timeBubble.txt"
#define INSERT "timeInsert.txt"

int main()
{
	FILE *fq, *fs, *fb, *fi;
	char sec1[20], sec2[20], sec3[20], sec4[20];

	if ((fq = fopen(QUICK,"r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo %s!\n", QUICK);
		return;
	}
	
	do {
		fgets(sec1, 20, fq);
	} while (!feof(fq));
	
	fclose(fq);
	
	if ((fs = fopen(SELECT,"r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo %s!\n", SELECT);
		return;
	}
	
	do {
		fgets(sec2, 20, fs);
	} while (!feof(fs));
	
	fclose(fs);
	
	if ((fb = fopen(BUBBLE,"r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo %s!\n", BUBBLE);
		return;
	}
	
	do {
		fgets(sec3, 20, fb);
	} while (!feof(fb));
	
	fclose(fb);
	
	if ((fi = fopen(INSERT,"r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo %s!\n", INSERT);
		return;
	}
	
	do {
		fgets(sec4, 20, fi);
	} while (!feof(fi));
	
	fclose(fi);
	
	printf("+-----------------------------------+\n");
	printf("| COMPARACAO DE TEMPOS DE ORDENACAO |\n");
	printf("+-----------------------------------+\n");
	printf("| QuickSort     | %s|\n", sec1);
	printf("| SelectionSort | %s|\n", sec2);
	printf("| BubbleSort    | %s|\n", sec3);
	printf("| InsertionSort | %s|\n", sec4);
	printf("+-----------------------------------+\n");

	return 0;
}
