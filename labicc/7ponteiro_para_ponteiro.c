#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    printf("Valor inicial da variavel: %d\n", n);
    int *p = &n;
    printf("Valor do ponteiro antes do incremento: %d\n", *p);
    *p += 10;
    printf("Valor do ponteiro depois do incremento: %d\n", *p);
    int **p2 = &p;
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **p2);
    **p2 += 10;
    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **p2);
    printf("Valor final da variavel: %d\n", n);
}