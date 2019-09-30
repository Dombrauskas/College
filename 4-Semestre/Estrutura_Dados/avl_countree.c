/**
* avl_countree.c
*
* Descrição: este programa conta o número de ocorrências
* das palavras em um texto utilizando uma árvore AVL
* para armazenar estas palavras e seus respectivos números
* de ocorrências.
*
* Ciro C. Trindade
* 30/Set/2019
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avl.h"

/**
 * int main()
 *
 * Descrição: função que solicita o nome do arquivo
 * sobre o qual será feita a contagem, abre este
 * arquivo e faz a leitura do mesmo, palavra por
 * palavra, inserindo-as em uma árvore AVL
 **/
int main() {
    FILE * arq; // Arquivo lógico
    avl_tree t = NULL; // Ponteiro para a raiz da árvore
    char filename[61]; // Nome do arquivo sobre o qual a contagem será realizada
    char palavra[41];
    bool h;
    int i;
    printf("Programa para contagem da ocorrencia de palavras em um texto\n\n");
    printf("Entre com o nome do arquivo: ");
    scanf("%60[^\n]", filename);
    if ((arq = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo %s\n", filename);
        return 1;
    }
    // leitura do arquivo
    while (fscanf(arq, "%s", palavra) != EOF) {
        i = strlen(palavra)-1;
        while (i > 0 && ispunct(palavra[i])) { // retira pontuação do final da palavra
            palavra[i] = '\0';
            i--;
        }
        while (ispunct(palavra[0])) { // retira pontuação do início da palavra
            for (i = 1; i <= strlen(palavra); i++) {
                palavra[i-1] = palavra[i];
            }
        }
        if (strlen(palavra) > 1) {
            avl_search(&t, palavra, &h);
        }
    }
    fclose(arq);
    print_tree(t);
    return 0;
}
