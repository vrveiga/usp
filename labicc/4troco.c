#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);

    int notas[7] = {200, 100, 50, 20, 10, 5, 2};

    for (int i = 0; i < 7; i++) {
        int qnt = 0;
        while (x >= notas[i]) {
            x -= notas[i];
            qnt++;
        }
        printf("%d nota(s) de R$ %d\n", qnt, notas[i]);
    }
    printf("%d moeda(s) de R$ 1\n", x);
}