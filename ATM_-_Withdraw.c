#include <stdio.h>

static int cels[] = {2, 5, 10, 20, 50, 100};

int main()
{
	int wd, c1, c2, i, M, m, qM = 0, qm = 0;
	do {
		printf("Quanto deseja sacar?\nMinimo de R$ 7,00\n");
		scanf("%d", &wd);
		system("cls");
	} while (wd < 7);
	
	system("cls");
	
	printf("Valor do Saque R$ %d,00\nQuais notas deseja: R$ 2, R$ 5, R$ 10, R$ 20, R$ 50, R$ 100\n", wd);
	//Selecao e verificacao da primeira cedula
	do {
		do {
			printf("Selecione a primeira cedula: ");
			scanf("%d", &c1);
			if (c1 >= wd){
				printf("Cedula maior ou igual ao valor de saque!\n");
			}
		} while (c1 >= wd);
		
		for (i = 0; i < 6; i++) {
			if (cels[i] == c1) {
				break;
			}
		}
		if (cels[i] != c1) {
			printf("Apenas notas de R$ 2, R$ 5, R$ 10, R$ 20, R$ 50, R$ 100\n");
		}
	} while (cels[i] != c1);
	//Selecao e verificacao da segunda cedula
	do{
		do {
			printf("Selecione a segunda cedula: ");
			scanf("%d", &c2);
			if (c2 >= wd){
				printf("Cedula maior ou igual ao valor de saque!\n");
			}
		} while (c2 >= wd);
		
		for (i = 0; i < 6; i++) {
			if (cels[i] == c2) {
				break;
			}
		}
		
		if (cels[i] != c2) {
			printf("Apenas notas de R$ 2, R$ 5, R$ 10, R$ 20, R$ 50, R$ 100\n");
		}
		if (c2 == c1){
			printf("Nota ja selecionada. Escolha outra\n");
			c2 = 0;
		}
	} while (cels[i] != c2);
	//Ordana as cedulas da maior para a menor
	if (c1 > c2) {
		M = c1;
		m = c2;
	} else {
		M = c2;
		m = c1;
	}
	//Conta a quantidade de cedulas necessarias do maior valor
	do {
		wd -= M;
		qM += 1;
	} while (wd > M);
	//Conta a quantidade de cedulas necessarias do menor valor e decresce a qM se preciso
	do {
		i = wd % m;
		if (i == 0){
			wd -= m;
			qm += 1;
		} else {
			wd += M;
			qM--;
		}
		if (qM == 0) {
			break;
		}
	} while (wd != 0);
	
	system("cls");
	wd = (qM * M) + (qm * m);
	
	if (qM == 0 || qm == 0){
		printf("Nao e possivel fazer saque com estas cedulas\n");
	} else {
		printf("Valor do Saque R$ %d,00\n%d Notas de R$ %d\n%d Notas de R$ %d\n", wd, qM, M, qm, m);	
	}
	
	system("pause");
	system("cls");
	
	printf("Deseja fazer outro saque?\n1 - Sim\n0 - Nao\n");
	do {
        	scanf("%d", &i);
        	switch(i) {
            		case 1:
                		system("cls");
                		main();
                		break;
            		case 0:
                		return 0;
                		break;
            		default:
                		printf("Opcao invalida!\n");
        	}
	} while (i != 1 || i != 0);
	//printf("%d\n", wd);
}
