#include "Pilha.h"

bool balanceada(char *sequencia) {
    PILHA* pilha = pilha_criar();
    int ret = true;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        char ch = sequencia[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            if (pilha_cheia(pilha)) {
                ret = false;
                break;
            }
            ITEM *it = item_criar(ch);
            pilha_empilhar(pilha, it);
        } else {
            if (pilha_vazia(pilha)){
                ret = false;
                break;
            }
            ITEM *topo = pilha_topo(pilha);

            if (item_get_chave(topo) + 1 == ch || 
                item_get_chave(topo) + 2 == ch) {
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