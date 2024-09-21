#include "item.h"
#include "lista.h"
#include "stdlib.h"

#ifndef STRUCTS_

#define STRUCTS_

struct lista_{ 

    ITEM *lista[TAM_MAX];

    int inicio; // pos do primeiro item

    int fim; // pos do próximo espaço vazio

    int tamanho;

};

#endif

bool lista_inserir(LISTA *lista, ITEM *item) {
    if (lista == NULL || lista->tamanho == TAM_MAX || item == NULL) {
        return false;
    }

    int l = lista->inicio, r = lista->fim-1;
    int idx = lista->fim;

    while (l <= r) {
        int m = (l+r)/2;
        if (item_get_chave(item) < item_get_chave(lista->lista[m])) {
            r = m-1;
            idx = m;
        } else {
            l = m+1;
        }
    }

    for (int j = lista->fim-1; j >= idx; j--) {
        lista->lista[j+1] = lista->lista[j];
    }

    lista->lista[idx] = item;
    lista->fim++;
    lista->tamanho++;

    return true;
}