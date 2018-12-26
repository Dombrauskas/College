// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>
#define MAX 5

typedef struct {
    char nome[51];
    int sequencia;
    int nota;
} infos;

void insertion(infos[]);

int main()
{
	int i = 0;
	infos aluno[MAX];

    for (i=0; i<MAX; i++) {
        printf("Nome do aluno %d: ", i+1);
        scanf("%50[^\n]", aluno[i].nome);
        fflush(stdin);
        printf("Sequencia: ");
        scanf("%d", &aluno[i].sequencia);
        fflush(stdin);
        printf("Nota: ");
        scanf("%d", &aluno[i].nota);
        fflush(stdin);
        printf("-----------------------------\n");
    }
    printf("---------------------------------------\n");
    printf("\n\n\tNotas em ordem decrescente:\n");
    printf("---------------------------------------\n");

    insertion(aluno);

    for (i=0; i < MAX; i++) {
        printf("Nota: %d\t\tNome: %s\t\tSequencia:%d\n", aluno[i].nota, aluno[i].nome, aluno[i].sequencia);
    }

    return 0;
}

void insertion(infos alunos[])
{

    int i,j;
    infos aux;

    for (i=1; i < MAX; i++) {
        aux = alunos[i];
        j = i - 1;
        while ((j >= 0) && (aux.nota > alunos[j].nota)) {
            alunos[j+1] = alunos[j];
            j--;
        }
        alunos[j+1] = aux;
    }
}
