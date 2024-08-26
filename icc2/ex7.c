// Remove x primeiros elementos da lista

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *nxt;
}node;

node* removeX (int x, node **ini) {
    if (x<= 0 || *ini == NULL) return *ini;
    node *p = *ini;
    node *aux;

    for (int i =0; i<x; i++) {
        aux = p->nxt;
        free(p);
        p = aux;
        
        if (p==NULL) break;
    }
    *ini = p;
    return p;
}