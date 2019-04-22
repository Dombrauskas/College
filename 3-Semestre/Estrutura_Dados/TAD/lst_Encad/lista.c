#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lista.h"

void lst_init(lst_ptr * l)
{
    *l = NULL;
}

bool lst_acessar(lst_ptr l, int x, lst_info * val)
{
    if (x >= 0 && x < lst_tamanho(l)) {
        int i;
        for (i = 0; i < x; i++)
            l = l->prox;

        *val = l->dado;
        return true;
    }
    return false;
}

bool lst_alterar(lst_ptr l, int x, lst_info val)
{
    if (x >= 0 && x < lst_tamanho(l)) {
        int i;
        for (i = 0; i < x; i++)
            l = l->prox;

        l->dado = val;
        return true;
    }
    return false;
}

bool lst_inserir(lst_ptr * l, int x, lst_info val)
{
    if (x >= 0 && x < lst_tamanho(*l)) {
        lst_ptr n;
        if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL)
            return false;
        if (x == 0) {
            n->prox = l;
            *l = n;
        } else {
            int i;
            for (i = l->n - 1; i >= x; i--)
                p = p->prox;

            n->prox = p->prox;
            p-prox = n;
        }
        return true;
    }
    return false;
}

bool lst_remover(lst_ptr * l, int x, lst_info * val)
{
    if (x >= 0 && x < lst_tamanho(l)) {
        if (x == 0) {
            n = *l;
            *l = n->prox;
        } else {
            int i;
            lst_ptr p = *l;

            for (i = 0; i < x - 1; i++)
                p = p->prox;

            n = l->prox;
            p->prox = n->prox;
        }
        *val = n->dado;
        free(n);
        return true;
    }
    return false;
}

int lst_tamanho(lst_ptr l)
{
    int n = 0;
    while (l != NULL) { //NULL será o último nó da lista.
        n++;
        l = l->prox; //Faz o l apontar para o nó seguinte.
    }
    return n;
}

lst_ptr lst_procurar(lst_ptr l, lst_info x)
{
    while (l != NULL) {
        if (l->dado == x)
            return l;
        l = l->prox;
    }
    return NULL;
}

void lst_imprimir(lst_ptr l)
{
    printf("[ ");
	while (l != NULL) {
		printf("%d,", l->dado);
		l = l->prox;
	}
	printf("\b ]\n");
}
