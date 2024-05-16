#include <stdio.h>

int main(void) {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, ok = 1;
        scanf("%d", &n);
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) ok = 0;
        }
        if (ok) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
}