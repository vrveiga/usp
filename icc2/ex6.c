// Remove a primeira ocorrencia de y na lista

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *nxt;
}node;

void buscaRemove(int y, node **ini) {
    node *p = *ini;

    if (p == NULL) return;
    if ( p->data == y) {
        node *aux = p->nxt;
        free(p);
        p = aux;
        *ini = p;
        return;
    }

    while (p->nxt != NULL && p->nxt->data != y) {
        p = p->nxt;
    }

    if (p->nxt != NULL) {
        node *aux = p->nxt->nxt;
        free(p->nxt);
        p->nxt = aux;
    }
}
