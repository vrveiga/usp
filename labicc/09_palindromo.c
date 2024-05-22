#include <string.h>
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        char s[100];
        scanf("%s", s);
        int tam = strlen(s);
        int ok = 1;
        for (int i = 0, j = tam-1; i < j; i++, j--) {
            if (s[i] != s[j]) ok = 0;
        }
        if (ok) {
            printf("%s eh um palindromo\n", s);
        } else {
            printf("%s nao eh um palindromo\n", s);
        }
    }
}