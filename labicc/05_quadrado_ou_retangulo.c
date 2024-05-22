#include <stdio.h>

int main(void) 
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (!a || !b || !c || !d) {
        printf("nenhum!\n");
    } else if (a == b && b == c && c == d) {
        printf("quadrado!\n");
    } else if (a == c && b == d) {
        printf("retangulo!\n");
    } else {
        printf("nenhum!\n");
    }
} 
