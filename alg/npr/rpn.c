#include "Pilha.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>


float rpn(char *sequencia) {
    PILHA* pilha = pilha_criar();
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if ('0' <= sequencia[i] && '9' >= sequencia[i]) {
            float* aa = malloc(sizeof(float));
            *aa = (float) (sequencia[i] - '0');
            ITEM* a = item_criar(0, aa);
            pilha_empilhar(pilha, a);
        } else {
            ITEM* b = pilha_desempilhar(pilha);
            ITEM* a = pilha_desempilhar(pilha);
            float* resp = malloc(sizeof(float));
            float* aa = item_get_dados(a);
            float* bb = item_get_dados(b);
            switch (sequencia[i]) {
                case '+': *resp = (*aa) + (*bb); break;
                case '-': *resp = (*aa) - (*bb); break;
                case '/': *resp = (*aa) / (*bb); break;
                case '*': *resp = (*aa) * (*bb); break;
            }
            ITEM* respIt = item_criar(0, resp);
            pilha_empilhar(pilha, respIt);
            item_apagar(&a);
            item_apagar(&b);
        }
    }
    ITEM* resp = pilha_desempilhar(pilha);
    float ret = *((float*)item_get_dados(resp));
    item_apagar(&resp);
    pilha_apagar(&pilha);
    return ret;
}