#include <stdio.h>
#include <string.h>

int main() {
    char str1[80], str2[80];
    fgets(str1, 80, stdin);
    fgets(str2, 80, stdin);

    char strf[160];
    int j = 0;
    for (int i = 0; str1[i] != '\n'; i++) {
        strf[j] = str1[i];
        j++;
    }
    for (int i = 0; str2[i] != '\n'; i++) {
        strf[j] = str2[i];
        j++;
    }
    strf[j] = '\0';

    printf("String Final: %s\n", strf);
    printf("Tamanho: %ld\n", strlen(strf));
    
    return 0;
}