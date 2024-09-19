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

    int i;
    int* aux;
    int* novo = item_get_dados(item);

    for (i = lista->inicio; i < lista->fim; i++) {
        aux = item_get_dados(lista->lista[i]);
        if (*aux > *novo) break;
    }

    for (int j = lista->fim; j >= i; j--) {
        lista->lista[j+1] = lista->lista[j]; 
    }

    lista->lista[i] = item;
    lista->fim++;
    lista->tamanho++;

    return true;
}