#include <stdio.h>

int main(void) {
    unsigned short int a, b, c;
    scanf("%hu%hu%hu", &a, &b, &c);
    long int k = 0;
    k |= c;
    k <<= 16;
    k |= b;
    k <<= 16;
    k |= a;
    printf("%ld\n", k);
}
