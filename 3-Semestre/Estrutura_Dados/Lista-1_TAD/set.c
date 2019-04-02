#include "set.h"
#include <stdio.h>

/*
* Trabalho 1 - Estruturas de Dados I
*
* Sobre: Conjunto set
*
* Integrantes (Ciência da Conputação):
*
* Rodrigo Suarez Moreira
* Daniel Bou de Souza
* Maurício da Silva Freire
*
* Data: 01/04/2019
*/

void set_init(set * s)
{
    s->n = 0;
}

bool set_isempty(set s)
{
    return s.n == 0;
}

bool set_isfull(set s)
{
    return s.n == SET_MAX;
}

bool set_member(set s, set_info x)
{
    int i;
    for (i = 0; i < s.n; i++) {
        if (s.itens[i] == x) {
            return true;
        }
    }
    return false;
}

bool set_insert(set * s, set_info x)
{
    if (!set_isfull(*s) && !set_member(*s, x)) {
       s->itens[s->n++] = x;
       return true;
    }
    return false;
}

bool set_remove(set * s, set_info x)
{
    if (set_member(*s, x)) {
        int i;
        for (i = 0; i < s->n; i++) {
            if (s->itens[i] == x) {
               for (; i < s->n-1; i++) {
                    s->itens[i] = s->itens[i + 1];
               }
               s->n--;
               return true;
            }
        }
    }
    return false;
}

bool set_union(set s1, set s2, set * s3)
{
    int k=0,i,j;

    for (i=0; i < s1.n; i++) {
        if (set_member(s2, s1.itens[i])) {
            k+=1;
        }
    }
    if ((s1.n + s2.n)-k <= SET_MAX) {
       set_init(s3);
       for (i = 0; i < s1.n; i++) {
            set_insert(&*s3, s1.itens[i]);
       }
       for (j = 0; j < s2.n; j++) {
            if (!set_member(*s3, s2.itens[j])) {
                set_insert(&*s3, s2.itens[j]);
            }
       }
       return true;
    }
    return false;
}

void set_intersection(set s1, set s2, set * s3) {

    int i;
    set_init(&*s3);
    for (i=0; i < s1.n; i++) {
        if (set_member(s2,s1.itens[i])) {
            set_insert(&*s3, s1.itens[i]);
        }
    }

}

bool set_difference(set s1, set s2, set * s3) {

    int k=0,i;
    set_init(&*s3);
    for (i=0; i < s1.n; i++) {
        if (!set_member(s2,s1.itens[i])) {
            k+=1;
        }
    }
    for (i=0; i < s2.n; i++) {
        if (!set_member(s1,s2.itens[i])) {
            k+=1;
        }
    }
    if (k <= SET_MAX) {
        for (i=0; i < s1.n; i++) {
            if (!set_member(s2,s1.itens[i])) {
                set_insert(&*s3, s1.itens[i]);
            }
        }
        for (i=0; i < s2.n; i++) {
            if (!set_member(s1,s2.itens[i])) {
                set_insert(&*s3, s2.itens[i]);
            }
        }
        return true;
    } else {
        return false;
    }

}

void set_print(set s1) {

    int i;
    printf("[ ");
    for (i=0; i < s1.n; i++) {
        printf("%d,", s1.itens[i]);
    }
    printf("\b ]\n");
}
