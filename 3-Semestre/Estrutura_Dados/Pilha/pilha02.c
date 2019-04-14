#include <stdio.h>
#include <stdbool.h>
#define STACK_MAX 10

typedef int stack_info;
typedef struct {
    stack_info itens[STACK_MAX];
    int topo;
} pilha;

bool push_and_test(pilha *, stack_info);
bool stack_isfull(pilha);
void stack_init(pilha *);
stack_info pop(pilha *);

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
        printf("\n1- Incluir na Pilha\n2- Verificar Pilha Cheia\n");
        printf("\n3- Remover da pilha\n\n");
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
            case 3:
                pop(&p);
                break;
            case 0:
            default:
                printf("Saindo do Programa\n");
        }
    } while (op >= 0 && op < 4);
    return 0;
}

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

void stack_init(pilha * p)
{
    p->topo = -1;
}

//Remove o elemento do topo da pilha
stack_info pop(pilha *p)
{
    if (!stack_isempty(*p))
        return p->itens[p->topo--];
    else {
        fprintf(stderr, "A pilha esta' vazia\n");
        exit(1);
    }
}
