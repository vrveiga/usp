// Inverter pilha

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prox;
} Node;

void inverter(Node **no){	
    if ((*no) == NULL || (*no)->prox == NULL) {
        return;
    }
    
    Node *n = (*no)->prox;
    inverter(&n);

    (*no)->prox->prox = (*no);
    (*no)->prox = NULL;
    (*no) = n;
}



