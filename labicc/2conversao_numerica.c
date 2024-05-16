#include <stdio.h>

int main() {
    char c;
    int n;
    scanf("%c%d", &c, &n);
    printf("numero correspondente: %d\n", c);
    printf("caracter correspondente: %c\n", n);
    printf("octal: %o\n", n);
    printf("hexadecimal: %x\n", n);
}