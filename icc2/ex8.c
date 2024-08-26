// Inverte a lista encadeada

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void reverseList(Node** ini) {
    Node* prev = NULL;
    Node* cur = *ini;
    Node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *ini = prev;
}