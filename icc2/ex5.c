// Inserir nova célula em uma lista ordenada

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* addNode(int data) {
    Node* aux = malloc(sizeof(Node));
    if (aux == NULL) exit(1);
    aux->data = data;
    aux->next = NULL;
    return aux;
}

void insertNode(int x, Node** ini) {
    Node* aux = addNode(x);

    if (*ini == NULL || (*ini)->data >= x) {
        aux->next = *ini;
        *ini = aux;
        return;
    }

    Node* cur = *ini;
    while (cur->next != NULL && cur->next->data < x) cur = cur->next;
    
    aux->next = cur->next;
    cur->next = aux;
}