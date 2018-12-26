// Autores:
// Daniel Bou C.C.
// Mauricio Freire C.C.

#include <stdio.h>

void ordenaStruct(int);

typedef struct {
 	char nome[31];
 	int cod;
 	float nota;
} tstudent;

tstudent std[5];

int main()
{
	int i;
	
	for (i = 0; i < 5; i++) {
	    printf("Nome: ");
	    scanf(" %30[^\n]", std[i].nome);
	    printf("Code: ");
	    scanf("%d", &std[i].cod);
	    printf("Nota: ");
	    scanf("%f", &std[i].nota);
	}
	ordenaStruct(5);
	
	for (i = 0; i < 5; i++) {
	    printf("\nNota: %.2f", std[i].nota);
	}
	
	return 0;
}

void ordenaStruct(int tamanho)
{
    int i, j;
    float aux;
    
    for(i = 1; i < tamanho; i++ ) {
        for(j = i; j > 0; j--) {
            printf("std[j]: %.2lf < std[j-1]: %.2lf\n",
                std[j].nota, std[j-1].nota);
            if (std[j].nota < std[j-1].nota) {
                aux = std[j].nota;
                std[j].nota = std[j-1].nota;
                std[j-1].nota = aux;
                printf("\naux: %.2f, std[j]: %.2f, std[j-1]: %.2f",
                    aux, std[j].nota, std[j-1].nota);
            }
//            if( strcoll(jPlayers[j].sNome, jPlayers[j-1].sNome) < 0) {
//              strcpy(sNomeAux,jPlayers[j].sNome);
//              strcpy(jPlayers[j].sNome,jPlayers[j-1].sNome);
//              strcpy(jPlayers[j-1].sNome,sNomeAux);}
            }
        }
}
