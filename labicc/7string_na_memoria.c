#include <stdio.h>

int main(void) {
    char str[26];
    fgets(str, 26, stdin);
    char *ptr = str;
    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr++;
    }
}