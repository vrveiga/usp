#include <stdio.h>
#include <string.h>

void strsubst(char *str, char *de, char *para) {
    int l = -1;

    for (int i = 0; i <= strlen(str) - strlen(de); i++) {
        int ok = 1;
        for (int j = 0; j < strlen(de); j++) {
            if (str[i+j] != de[j]) ok = 0;
        }
        if (ok) {
            l = i;
            break;
        }
    }
    if (l == -1) return;

    char ret[120];
    int idx = 0;

    for (int i = 0; i < l; i++) {
        ret[idx++] = str[i];
    }
    for (int i = 0; i < strlen(para); i++) {
        ret[idx++] = para[i];
    }
    for (int i = l + strlen(de); i < strlen(str); i++) {
        ret[idx++] = str[i];
    }
    ret[idx] = '\0';

    strcpy(str, ret);
}

int main() {
    char a[80] = "communication";
    char b[40] = "tion";
    char c[40] = "cao";

    strsubst(a, b, c);
    printf("%s\n", a);

    return 0;
}