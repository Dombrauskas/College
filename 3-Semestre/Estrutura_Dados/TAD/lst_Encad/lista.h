#ifdef _LISTA_H
#define _LISTA_H
#include <stdbool.h>

typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

//Fun��o que inicializa o primeiro n� da lista.
void lst_init(lst_ptr *);

bool lst_acessar(lst_ptr, int, lst_info *);

bool lst_alterar(lst_ptr, int, lst_info *);

bool lst_inserir(lst_ptr *, int, lst_info);

bool lst_remover(lst_ptr *, int, lst_info *);

// Fun��o que retorna quantos n�s h� na lista.
int lst_tamanho(lst_ptr);

lst_ptr lst_procurar(lst_ptr, lst_info);

void lst_imprimir(lst_ptr);

#endif // _LISTA_H
