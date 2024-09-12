#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef _STRUCTS_

#define _STRUCTS_

typedef struct no_ {

ITEM* item;

struct no_* proximo;

}noObj;

typedef noObj NO;

typedef struct fila_ {

NO* inicio;

NO* fim;

int tamanho;

}filaObj;

typedef filaObj FILA;

#endif

void fila_apagar(FILA **fila) {
    if (*fila == NULL || fila_vazia(*fila)) {
        return;
    }
    
    if ((*fila)->inicio != NULL) {
        item_apagar(&(*fila)->inicio->item);
    }
    fila_remover(*fila);

    fila_apagar(fila);

    if (fila_vazia(*fila)) {
        free(*fila);
        *fila = NULL;
    }
}