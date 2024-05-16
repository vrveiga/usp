#include <stdio.h>

int main(void) 
{
    int v[10000], tam = 0, x;
    while (scanf("%d", &x) && x != 1) {
        v[tam] = x;
        tam++;
    }

    char com;
    scanf(" %c", &com);

    if (com == 'a') {
        for (int i = 0; i < tam; i++) {
            for (int j = i; j < tam; j++) {
                if (v[i] > v[j]) {
                    int tmp = v[i];
                    v[i] = v[j];
                    v[j] = tmp;
                }
            }
        }
        printf("vetor ordenado:");
        for (int i = 0; i < tam; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    else if (com == 'b') {
        printf("Numeros de Fibonacci:");
        for (int i = 0; i < tam; i++) {
            int a = 1, b = 1, c, ok = 0;
            while (a < 2200) {
                c = a + b;
                a = b;
                b = c;
                if (c == v[i]) ok = 1;
            }
            if (ok) printf("%d ", v[i]);
        }
        printf("\n");
    }

    else if (com == 'c') {
        printf("Vetor maiusculo:");
        for (int i = 0; i < tam; i++) {
            printf("%c ", v[i] - ('a' - 'A'));
        }
        printf("\n");
    }

    else printf("Comando inexistente\n");

    return 0;
}