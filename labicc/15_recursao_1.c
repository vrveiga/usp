#include <stdio.h>

int soma (int a, int b) {
    if (b == 0) return a;
    return soma(a + 1, b - 1);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int s = soma(a, b);
    printf("%d\n", s);

    return 0;
}