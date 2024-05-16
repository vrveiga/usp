#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    int a = 0, b = 0, bt;
    for (int i = n-1; i >= 0; i--) {
        scanf("%d", &bt);
        a |= bt;
        a <<= 1;
    }
    a >>= 1;
    for (int i = m-1; i >= 0; i--) {
        scanf("%d", &bt);
        b |= bt;
        b <<= 1;
    }
    b >>= 1;
    printf("%d\n", a+b);
}