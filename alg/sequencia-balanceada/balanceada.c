#include "Pilha.h"
#include <stdio.h>

bool balanceada(char *sequencia) {
    PILHA* pilha = pilha_criar();
    bool ret = true;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        char ch = sequencia[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            if (pilha_cheia(pilha)) {
                ret = false;
                break;
            }
            ITEM *it = item_criar(1, sequencia + i);
            pilha_empilhar(pilha, it);
        } else {
            if (pilha_vazia(pilha)){
                ret = false;
                break;
            }
            ITEM *topo = pilha_topo(pilha);
            char *dado = item_get_dados(topo);
            if ((*dado) + 1 == ch || 
                (*dado) + 2 == ch) {
                pilha_desempilhar(pilha);
                item_apagar(&topo);
            } else {
                ret = false;
                break;
            }
        }
    }

    if (!pilha_vazia(pilha)) ret = false;
    
    pilha_apagar(&pilha);
    return ret;
}