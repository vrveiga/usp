#include <stdio.h>

void hanoi(int n, char from, char spr, char to) {
    if (n == 1) {
        printf("Move disco 1 da pilha %c para a pilha %c\n", from, to);
        return;
    }
    hanoi(n-1, from, to, spr);
    printf("Move disco %d da pilha %c para a pilha %c\n", n, from, to);
    hanoi(n-1, spr, from, to);
}

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}