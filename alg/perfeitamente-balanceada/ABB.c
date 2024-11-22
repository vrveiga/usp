#include "ABB.h"
#include "item.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct No NO;
struct No {
    ITEM* item;
    NO* esq;
    NO* dir;
    int nos;
};

struct abb {
    NO* raiz;
};

ABB *abb_criar (void) {
    ABB* buffer = malloc(sizeof(ABB));
    if (buffer != NULL) {
        buffer->raiz = NULL;
    }
    return buffer;
}

NO* abb_criar_no(ITEM* item) {
    NO* buffer = malloc(sizeof(NO));
    if (buffer != NULL) {
        buffer->item = item;
        buffer->esq = NULL;
        buffer->dir = NULL;
        buffer->nos = 1;
    }
    return buffer;
}

NO *abb_inserir_no(NO *raiz, NO *novo) {
    if (raiz == NULL)
        raiz = novo;
    else if (item_get_chave(novo->item) < item_get_chave(raiz->item)) {
        raiz->esq = abb_inserir_no(raiz->esq, novo);
        raiz->nos++;
    }
    else if (item_get_chave(novo->item) > item_get_chave(raiz->item)) {
        raiz->dir = abb_inserir_no(raiz->dir, novo);
        raiz->nos++;
    }
    return raiz;
}

bool abb_inserir (ABB *T, ITEM *item) {
    NO *novo;
    if (T == NULL)
        return false;

    novo = abb_criar_no(item);
    if (novo != NULL) {
        T->raiz = abb_inserir_no(T->raiz, novo);
        return true;
    }
    return false;
}

void imprimir(NO* raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esq);
        printf("%d(%d) ", item_get_chave(raiz->item), raiz->nos);
        imprimir(raiz->dir);
    }
}

void abb_imprimir (ABB *T) {
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

void abb_apagar (ABB **T) {
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

void troca_max_esq(NO *troca, NO *raiz, NO *ant) {
    if (troca->dir != NULL) {
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }

    if (raiz == ant)
        ant->esq = troca->esq;
    else
        ant->dir = troca->esq;

    raiz->item = troca->item;
    free(troca); troca = NULL;
}

bool abb_remover_aux(NO **raiz, int chave) {
    NO *p;
    if (*raiz == NULL)
        return false;
    
    if (chave == item_get_chave((*raiz)->item)) {
        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL) {
            p = *raiz;
            if ((*raiz)->esq == NULL)
                *raiz = (*raiz)->dir;
            else
                *raiz = (*raiz)->esq;
            free(p);
            p = NULL;
        } else {
            troca_max_esq((*raiz)->esq, (*raiz), (*raiz));
        }
        return true;
    } else {
        if (chave < item_get_chave((*raiz)->item))
            return abb_remover_aux(&(*raiz)->esq, chave);
        else
            return abb_remover_aux(&(*raiz)->dir, chave);
    }
}

bool abb_remover(ABB *T, int chave) {
    if (T != NULL)
        return abb_remover_aux(&(T->raiz), chave);
    return false;
}

ITEM *abb_busca_rec(NO *raiz, int chave) {
    if (raiz == NULL)
        return NULL;
    if (chave == item_get_chave(raiz->item))
        return raiz->item;

    if (chave < item_get_chave(raiz->item))
        return abb_busca_rec(raiz->esq, chave);
    else
        return abb_busca_rec(raiz->dir, chave);

    return NULL;
}

ITEM *abb_busca(ABB *T, int chave) {
    if (T != NULL)
        return abb_busca_rec(T->raiz, chave);
    return NULL;
}

bool abb_vazia(ABB *T) {
    if (T == NULL)
        return false;
    return (T->raiz == NULL);
}

int percorre(NO* raiz) {
    if (raiz != NULL) {
        int fesq = 0, fdir = 0;
        if (raiz->esq != NULL)
            fesq = raiz->esq->nos;
        if (raiz->dir != NULL)
            fdir = raiz->dir->nos;
        return percorre(raiz->esq) + percorre(raiz->dir) + (abs(fdir - fesq) > 1);
    }
    return 0;
}

bool abb_perfeitamente_balanceada(ABB *T) {
    if (T != NULL) {
        return percorre(T->raiz);
    }
    return false;
}