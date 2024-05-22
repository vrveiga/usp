#include <stdio.h>

int main() {
    printf("Tam char: %ld\n", sizeof((char)'c'));
    printf("Tam int: %ld\n", sizeof((int)1));
    printf("Tam float: %ld\n", sizeof((float)1));
    printf("Tam double: %ld\n", sizeof((double)1));
    printf("Tam unsigned char: %ld\n", sizeof((unsigned char)'c'));
    printf("Tam signed char: %ld\n", sizeof((signed char)'c'));
    printf("Tam unsigned int: %ld\n", sizeof((unsigned int)1));
    printf("Tam signed int: %ld\n", sizeof((signed int)1));
    printf("Tam short int: %ld\n", sizeof((short int)1));
    printf("Tam long int: %ld\n", sizeof((long int)1));
    printf("Tam long long int: %ld\n", sizeof((long long int)1));
}