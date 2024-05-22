#include <stdio.h>

int desaparecido(int *v, int tam) {
    int p[200000] = {};

    for (int i = 0; i < tam; i++) {
        p[v[i]] = 1;
    }

    for (int i = 1; i <= tam+1; i++) {
        if (p[i] == 0) return i;
    }
}

int main(void) {
    int n, v[200000];
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) scanf("%d", v+i);
    printf("Numero desaparecido: %d", desaparecido(v, n-1));
}