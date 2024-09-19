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
    if (lista_cheia(lista) || item == NULL) {
        return false;
    } 

    int i;
    int* aux;
    int* new = item_get_dados(item);

    for (i = lista->inicio; i < lista->fim; i++) {
        aux = item_get_dados(lista->lista[i]);
        if (*aux > *new) break;
    }

    for (int j = lista->fim; j >= i; j--) {
        lista->lista[j+1] = lista->lista[j]; 
    }

    lista->lista[i] = item;
    lista->fim++;
    lista->tamanho++;

    return true;
}