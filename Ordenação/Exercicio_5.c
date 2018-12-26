// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>

void naipes(int *, int);

int main()
{
    int i;
    int copas[] = {2, 3, 7, 1, 13, 6, 4, 5, 8, 14, 10, 11, 9, 12};
    int ouros[] = {7, 14, 2, 4, 6, 10, 5, 3, 9, 11, 12, 8, 1, 13};
    int espada[] = {1, 2, 4, 8, 3, 9, 12, 7, 10, 13, 14, 6, 5, 11};
    int paus[] = {14, 2, 12, 4, 10, 8, 6, 5, 7, 9, 11, 3, 13, 1};
    
	printf("\tNaipes antes da ordenacao\n\n");
    printf("+---------+---------+---------+---------+\n");
    printf("|  Copas  |  Ouros  |  Espada |   Paus  |\n");
    printf("+---------+---------+---------+---------+\n");
    printf("|  C | I  |  C | I  |  C | I  |  C | I  |\n");
    printf("+---------+---------+---------+---------+\n");
    for (i = 0; i < 14; i++) {
        printf("| %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d |\n",
            copas[i], i+1, ouros[i], i+1, espada[i], i+1, paus[i], i+1);
    }
    printf("+---------+---------+---------+---------+\n");
    
	naipes(copas, 14);
	naipes(ouros, 14);
	naipes(espada, 14);
	naipes(paus, 14);
    
    printf("\n");
    printf("\tNaipes apos as ordenacoes\n\n");
    printf("+---------+---------+---------+---------+\n");
    printf("|  Copas  |  Ouros  |  Espada |   Paus  |\n");
    printf("+---------+---------+---------+---------+\n");
    printf("|  C | I  |  C | I  |  C | I  |  C | I  |\n");
    printf("+---------+---------+---------+---------+\n");
    for (i = 0; i < 14; i++) {
        switch(copas[i], ouros[i], espada[i], paus[i]) {
            case 1:
                copas[i] = 65;
                ouros[i] = 65;
                espada[i] = 65;
                paus[i] = 65;
                printf("| %2c | %2d | %2c | %2d | %2c | %2d | %2c | %2d |\n",
                	copas[i], i+1, ouros[i], i+1, espada[i], i+1, paus[i], i+1);
            break;
            case 12:
                copas[i] = 74;
                ouros[i] = 74;
                espada[i] = 74;
                paus[i] = 74;
                printf("| %2c | %2d | %2c | %2d | %2c | %2d | %2c | %2d |\n",
                	copas[i], i+1, ouros[i], i+1, espada[i], i+1, paus[i], i+1);
            break;
            case 13:
                copas[i] = 81;
                ouros[i] = 81;
                espada[i] = 81;
                paus[i] = 81;
                printf("| %2c | %2d | %2c | %2d | %2c | %2d | %2c | %2d |\n",
                	copas[i], i+1, ouros[i], i+1, espada[i], i+1, paus[i], i+1);
            break;
            case 14:
                copas[i] = 75;
                ouros[i] = 75;
                espada[i] = 75;
                paus[i] = 75;
                printf("| %2c | %2d | %2c | %2d | %2c | %2d | %2c | %2d |\n",
                	copas[i], i+1, ouros[i], i+1, espada[i], i+1, paus[i], i+1);
            break;
            default:
         		printf("| %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d |\n",
            		copas[i], i+1, ouros[i], i+1, espada[i], i+1, paus[i], i+1);
            break;
        }
    }
    printf("+---------+---------+---------+---------+\n");

    return 0;
}

void naipes(int *card, int size)
{
	int i, j, aux;
	for (i = 0; i < size - 1; i++) {
		for (j = (i + 1); j < size; j++) {
			if (card[j] < card[i]) {
				aux = card[i];
				card[i] = card[j];
				card[j] = aux;
			}
		}
	}
}
