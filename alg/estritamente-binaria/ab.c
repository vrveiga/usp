#include "ab.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct No NO;
struct No {
    ITEM* item;
    NO* esq;
    NO* dir;
    int filhos;
};

struct arv_bin {
    NO* raiz;
};

AB *ab_criar(void) {
    AB* buffer = malloc(sizeof(AB));
    if (buffer != NULL) {
        buffer->raiz = NULL;
    }
    return buffer;
}

NO* ab_criar_no(ITEM* item) {
    NO* buffer = malloc(sizeof(NO));
    if (buffer != NULL) {
        buffer->item = item;
        buffer->esq = NULL;
        buffer->dir = NULL;
        buffer->filhos = 0;
    }
    return buffer;
}

void ab_inserir_no(NO* raiz, NO* no, int lado, int chave) {
    if (raiz != NULL) {
        ab_inserir_no(raiz->esq, no, lado, chave);
        ab_inserir_no(raiz->dir, no, lado, chave);
        if (item_get_chave(raiz->item) == chave) {
            raiz->filhos++;
            if (lado == 0) {
                raiz->esq = no;
            } else {
                raiz->dir = no;
            }
        }
    }
}

bool ab_inserir(AB *T, ITEM *item, int lado, int chave) {
    NO* no = ab_criar_no(item);
    if (no == NULL) return false;

    if (T->raiz == NULL) {
        T->raiz = no;
    } else {
        ab_inserir_no(T->raiz, no, lado, chave);
    }
    return true;
}

void imprimir(NO* raiz) {
    if (raiz != NULL) {
        printf("%d ", item_get_chave(raiz->item));
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
}

void ab_imprimir (AB *T) {
    if (T->raiz != NULL) {
        imprimir(T->raiz);
        printf("\n");
    }
}

void apagar_arvore(NO **raiz) {
    if (*raiz != NULL) {
        apagar_arvore(&(*raiz)->esq);
        apagar_arvore(&(*raiz)->dir);
        item_apagar(&(*raiz)->item);
        free(*raiz);
        *raiz = NULL;
    }
}

void ab_apagar_arvore(AB **T) {
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

int percorre(NO* raiz) {
    if (raiz != NULL) {
        return percorre(raiz->esq) + percorre(raiz->dir) + (raiz->filhos == 1);
    }
    return 0;
}

int ab_estritamente_binaria (AB *T) {
    return percorre(T->raiz);
}