// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 10000

void ordVet(int *, int, int);

int main(void)
{
    int a, i, n, vet[TAM], x = -1;
    clock_t tt, ct, et;
    srand(time(NULL));
    
    do {
		printf("\nQual numero deseja encontrar?\n-1 para sair\n\n");
		scanf("%d", &n);

		if (n == -1)
			return;
			
		tt = clock();
		for(i = 0 ; i < TAM ; i++) {
		    vet[i] = rand() % TAM;
		    printf("%d\t", vet[i]);
		    if (vet[i] == n) {
		    	et = clock();
		    	x = i;
			} else if ((i >= TAM-1) && (x == -1)) {
				printf("\n\nNao foi possivel encontrar o numero %d\n\n", n);
				et = clock();
			}
		}

		system("pause");
		ordVet(vet, 0, TAM-1);
		ct = clock();

		for (a = 0; a < TAM; a++) {
			if (vet[a] == n) {
				system("cls");
				printf("Numero Alvo: %d\n", n);
				printf("\nBUSCA NAO ORDENADA\n");
				printf("\nPosicao: #%d", x+1);
				printf("\nTotal de Iteracoes: %d", x);
				printf("\nTempo de Execucao: %lf", (double) (et - tt) / CLOCKS_PER_SEC);
				printf("\n\nBusca ORDENADA\n");
				printf("\nPosicao: #%d", a+1);
				printf("\nTotal de Iteracoes: %d", a);
				printf("\nTempo de Execucao: %lf\n\n", (double) (clock() - ct) / CLOCKS_PER_SEC);
			}
		}
		system("pause");
		system("cls");
	} while (n != -1);
	return 0;
}

void ordVet(int *vet, int esq, int dir)
{
	int pivo = esq, i, ch, j;         
    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (vet[j] < vet[pivo]) {
            ch = vet[j];
            while(j > pivo) {
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }
    if (pivo -1 >= esq) {
        ordVet(vet, esq, pivo-1);
    }
    if (pivo +1 <= dir) {
        ordVet(vet, pivo+1, dir);
    }
}
