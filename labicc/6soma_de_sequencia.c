#include <stdio.h>

int main(void) {
    float soma = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i&1) {
            soma += 1.0/i;
        } else {
            soma -= 1.0/i;
        }
    }
    printf("%.4f\n", soma);
}