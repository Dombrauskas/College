/**
 *
 * autor Maurício Freire
 * Programa que constroi uma pilha com funções simples: inserir e verificar se 
 * a pilha está cheia; e inicialização.
*/

#include <stdio.h>
#include <stdbool.h>
#define STACK_MAX 10

typedef int stack_info; // Tipo de dado da pilha.
typedef struct {
    stack_info itens[STACK_MAX];
    int topo;
} pilha;

bool push_and_test(pilha *, stack_info);
bool stack_isfull(pilha);
void stack_init(pilha *);

/*Verifica se a pilha está cheia*/
bool stack_isfull(pilha p)
{
    return (p.topo == STACK_MAX-1);
}

int main()
{
    int op, n;
    bool e;
    pilha p;

    stack_init(&p);

    do {
        printf("O que deseja fazer?\n");
        printf("\n1- Incluir na Pilha\n2- Verificar Pilha Cheia\n\n");
        scanf("%d", &op);
        switch(op) {
            case 1:
                printf("Informe um inteiro: ");
                scanf("%d", &n);
                push_and_test(&p, n);
                break;
            case 2:
                e = stack_isfull(p);
                printf("Elementos na Pilha %d\n", p.topo + 1);
                break;
            default:
                printf("Saindo do Programa\n");
        }
    } while (op == 1 || op == 2);
    return 0;
}

/*Função que insere e verifica o estado da pilha.
Evitando o encerramento prematuro.*/
bool push_and_test(pilha *p, stack_info x)
{
    if (!stack_isfull(*p)) {
        p->itens[++(p->topo)] = x;
        return true;
    } else {
        fprintf(stderr, "\nImpossivel fazer inclusao!\nPilha Cheia\n");
        return false;
    }
}

/*Inicializa a pilha definindo um valor para topo.
Como os vetores começam em 0 topo terá valor inicaial de -1.*/
void stack_init(pilha * p)
{
    p->topo = -1;
}
