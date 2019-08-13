#include <stdio.h>
#include <string.h>

void Nova_Anotacao(void);
void Alterar_Anotacao(const char *);
void Ler_Anotacao(void);
char conferir(const char, char);

int main(/*const char * pp*/)
{
	int op;
	do {
		printf("1 - Criar Nova Anotacao\n2 - Alterar Anotacao Anterior\n");
		printf("3 - Ler Anotacao\n9 - Sair\n\nOpcao ");
		scanf("%d", &op);
		switch (op) {
			case 1:
				Nova_Anotacao();
				break;
			case 3:
				Ler_Anotacao();
				break;
			case 9:
				return 0;
			default:
				printf("Opcao Invalida!\n");
				system("pause");
				system("cls");
				break;
		}
	} while (op != 9);
}
//Escreve uma anotação

/* Incluir uma verificação de nomes de arquivos para evitar
que o salve duas anotações com o mesmo nome */
void Nova_Anotacao(void)
{
	system("cls");
	FILE *na;
	char note[21], conteudo[500], ct = 'x';
	fflush(stdin);
	
	//do {
		printf("Nomeie a Anotacao: ");
		scanf("%20[^\n]", note);
		fflush(stdin);
	
	//	conferir(note, ct);
	//} while (ct == 'y');
	strcat(note,".txt");
	//char *nn;
	na = fopen(note,"w");

	system("cls");
	printf("Anotacao %s\n", note);
	printf("__________________________________________________\n");
	scanf("%499[^\n]", conteudo);
	fwrite(conteudo, sizeof(char), strlen(conteudo), na);

	fclose(na);
	system("cls");
	
	//nn = note;
	//main(nn);
}
/*
void Alterar_Anotacao(const char * ne)
{
	system("cls");
	//FILE *arq
	//char conteudo[500];
	//arq = fopen(arquivo,"r");
	//fgets(conteudo, 499, arq);
	printf("Juliana Topissima\n");
	printf("%s", &ne);
	system("pause");
	system("cls");
}
*/

void Ler_Anotacao()
{
	system("cls");
	FILE *la;
	int i, x = 0, j;
	char est[21], leitura[50], tex[] = "                                                  ";
	fflush(stdin);
	printf("Qual Anotacao deseja ver?\n");
	scanf("%20[^\n]", est);
	fflush(stdin);
	
	strcat(est,".txt");
	la = fopen(est,"r");

	system("cls");

	if (la == NULL){
		printf("Arquivo %s nao encontrado!\n", est);
		system("pause");
		system("cls");
		fflush(stdin);
		main();
	}

	fflush(stdin);
	printf("%s\n__________________________________________________\n\n", est);
//Exibe o conteudo do arquivo em várias linhas	
	do {
		fgets(leitura, 49, la);
		x = 48 - strlen(leitura);
		if (x == 0) {
			printf("| %s |\n", leitura);
		} else {
			//for (j = strlen(leitura) + 1; j <= 48; j++){
			//	tex[j] = 64;
				//printf("%c", tex[j]);
			//}/
			strncat(leitura,tex,x);
			printf("| %s |\n", leitura);
		}
	} while (!feof(la));
	printf("\n");
	fclose(la);
	
	system("pause");
	system("cls");
}
/*
char conferir(const char cn, char ch)
{
	char lista[100][21];
	int i;
	printf("AAAAAAAAAAAAAAA\n");

	for (i = 0; i < 100; i++){
		lista[i][0] = cn;
	}

	for (i = 0; i < 100; i++) {
		if (lista[i] == cn) {
			printf("Nome ja utilizado\n");
			ch = 'y';
			break;
		}
	}
	return ch;
}*/