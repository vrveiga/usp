#include <stdio.h>

int main(void) 
{
    int n, v[30] = {}, ok = 1;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        // printf("%c, ", c);
        v[c-'a']++;
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (v[i-'a'] % 2 != 0) ok = 0;
        // printf("%d\n", v[i-'a']);
    }
    if (ok) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}