#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int i, n, aux, *v, j;
    bool troca = true;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\n");

    i = 0;

    while (1) {
        troca = false;

        for (i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i + 1];
                v[i + 1] = v[i];
                v[i] = aux;
                troca = true;
            }
        }

        if (!troca)
            break;

        else {
            for (j = 0; j < n; j++)
                printf("%d ", v[j]);

            printf("\n");
        }

        troca = false;

        for (i = n - 1; i > 0; i--) {
            if (v[i] < v[i - 1]) {
                aux = v[i - 1];
                v[i - 1] = v[i];
                v[i] = aux;
                troca = true;
            }
        }

        if (!troca)
            break;

        else {
            for (j = 0; j < n; j++)
                printf("%d ", v[j]);

            printf("\n");
        }
    }

    free(v);

    return 0;
}
