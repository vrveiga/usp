#include <stdlib.h>
#include "Deque.h"
#include "item.h"

struct deque_ {
    ITEM* items[MAX_TAMANHO];
    int ini;
    int fim;
    int cnt;
};

DEQUE* deque_criar() {
    DEQUE* deque = malloc(sizeof(DEQUE)); 
    if (deque != NULL) {
        deque->ini = 0;
        deque->fim = 0;
        deque->cnt = 0;
    }
    return deque;
}

void deque_apagar(DEQUE** deque) {
    if (*deque == NULL) return;
    while (!deque_vazia(*deque)) {
        ITEM* it = deque_remover_fim(*deque);
        item_apagar(&it);
    }
    free(*deque);
    *deque = NULL;
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item) {
    if (deque != NULL && !deque_cheia(deque)) {
        deque->ini = (deque->ini - 1 + MAX_TAMANHO) % MAX_TAMANHO;
        deque->items[deque->ini] = item;
        deque->cnt++;
        return true;
    }
    return false;
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item) {
    if (deque != NULL && !deque_cheia(deque)) {
        deque->items[deque->fim] = item;
        deque->fim = (deque->fim + 1) % MAX_TAMANHO;
        deque->cnt++;
        return true;
    }
    return false;
}

ITEM* deque_remover_inicio(DEQUE* deque) {
    if (deque != NULL && !deque_vazia(deque)) {
        ITEM* it = deque->items[deque->ini];
        deque->ini = (deque->ini + 1) % MAX_TAMANHO;
        deque->cnt--;
        return(it);
    }
    return NULL;
}

ITEM* deque_remover_fim(DEQUE* deque) {
    if (deque != NULL && !deque_vazia(deque)) {
        deque->fim = (deque->fim - 1 + MAX_TAMANHO) % MAX_TAMANHO;
        ITEM* it = deque->items[deque->fim];
        deque->cnt--;
        return(it);
    }
    return NULL;
}

ITEM* deque_primeiro(DEQUE* deque) {
    if (deque != NULL && !deque_vazia(deque)) {
        return deque->items[deque->ini];
    }
    return NULL;
}

ITEM* deque_ultimo(DEQUE* deque) {
    if (deque != NULL && !deque_vazia(deque)) {
        return deque->items[deque->fim];
    }
    return NULL;
}

int deque_contar(DEQUE* deque) {
    if (deque != NULL) {
        return deque->cnt;
    }
    return -1;
}

bool deque_vazia(DEQUE* deque) {
    if (deque == NULL || deque->cnt != 0) {
        return false;
    }
    return true;
}
bool deque_cheia(DEQUE* deque) {
    if (deque == NULL || deque->cnt != MAX_TAMANHO) {
        return false;
    }
    return true;
}