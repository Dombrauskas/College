#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    lst_ptr l;
	lst_info p;
	int op;

	lst_init(&l);
	do {
		printf("\n\n\tFILA\n");
		printf("<1> Inserir\n");
		printf("<2> Remover\n");
		printf("<3> Imprimir\n");
		printf("<0> Sair\n");
		printf("Op��o: ");
		scanf("%d", &op);
		switch (op) {
			case 1:
				printf("\n\nInser��o\n");
				printf("Valor: ");
				scanf("%d", &x);
				lst_inserir(&l, x, p);
				break;
			case 2:
				printf("\n\nValor removido: %d\n", lst_inserir(&l));
				break;
			case 3:
				printf("\n\nConte�do da fila: ");
				lst_imprimir(l);
			case 0:
				break;
			default:
				printf("\nErro: op��o inv�lida!\n");
		}
	} while (op != 0);
	return 0;
}
