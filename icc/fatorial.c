#include <stdio.h>

int main(void) {
    int n, cont = 0, k = 5;
    scanf("%d", &n);

    while (k <= n) {
        cont += n/k;
        k *= 5;
    }

    printf("%d\n", cont);
}