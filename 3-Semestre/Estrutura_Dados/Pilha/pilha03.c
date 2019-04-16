/**
 * 
 * autor Maurício Freire
 * Representação de uma pilha com as funções de incluir, remover e consultar
 * o elemento do topo. Além de verificar o estado da pilha: cheia ou vazia.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef int stack_info; //Tipo de dado da pilha.
//Estrutura que representa a pilha.
typedef struct {
    stack_info itens[MAX]; //Vetor que armazena os dados da pilha.
    int topo; //Índice do topo da pilha.
} pilha;

void stack_init(pilha *);
void push(pilha *, int);
void pop(pilha *);
bool stack_isfull(pilha);
bool stack_isempty(pilha);
stack_info top(pilha);

int main()
{
    pilha p;
    int op, n;

    stack_init(&p);
    do {
        printf("\nEscolhe:\n");
        printf("1- Inserir\n2- Remover\n3- Ver topo\n\n");
        scanf("%d", &op);
        switch(op) {
            case 1:
                printf("Numero: ");
                scanf("%d", &n);
                push(&p, n);
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                printf("Topo da pilha %d\n", top(p));
                break;
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("Errou...");
        }
    } while (op != 0);
    return 0;
}

//Inicia a pilha definido o valor de topo.
void stack_init(pilha * p)
{
    p->topo = -1;
}

//Inclui um elemento no topo da pilha, se a pilha não estiver cheia.
void push(pilha * p, int x)
{
    if (!stack_isfull(*p))
        p->itens[++(p->topo)] = x;
    else {
        fprintf(stderr, "Pilha Cheia\nImpossivel fazer nova inclusao!\n\n");
        return;
    }
}

//Remove o elemento do topo da pilha, se a pilha não estiver vazia.
void pop(pilha * p)
{
    if (!stack_isempty(*p))
        p->topo--;
    else {
        fprintf(stderr, "Pilha vazia\nNada a remover!\n\n");
        return;
    }
}

//Verifica se a pilha está cheia.
bool stack_isfull(pilha p)
{
    return (p.topo == MAX-1);
}

//Verifica se a pilha está vazia.
bool stack_isempty(pilha p)
{
    return (p.topo == -1);
}

//Mostra o valor do topo da pilha, se a pilha não estiver vazia.
stack_info top(pilha p)
{
    if (!stack_isempty(p))
        return p.itens[p.topo];
    else {
        fprintf(stderr, "Pilha Vazia\nNada a mostrar!\n\n");
        return -1;
    }
}
