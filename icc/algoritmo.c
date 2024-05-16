#include <stdio.h>

int main(void) {
    unsigned long long int a, b;
    scanf("%llu%llu", &a, &b);
    if (a%2 == b%2) {
        if (a%2 == 1) {
            printf("O primeiro número é ímpar\nO segundo número é ímpar\nO resultado é %llu, que é ímpar\n", a*b);
        } else {
            printf("O primeiro número é par\nO segundo número é par\nO resultado é %llu, que é par\n", a*b);
        }
    } else {
        if (a%2 == 1) {
            printf("O primeiro número é ímpar\nO segundo número é par\nO resultadoa é %llu, que é ímpar\n", a+b);
        } else {
            printf("O primeiro número é par\nO segundo número é ímpar\nO resultado é %llu, que é ímpar\n", a+b);
        }
    }
}