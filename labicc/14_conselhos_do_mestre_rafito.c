#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inv[256], inp[256];
    scanf("%s %s", inv, inp);

    FILE *fp = fopen(inp, "r");
    if (fp == NULL) exit(1);

    char s[4096];
    int i = 0;
    while ((s[i] = fgetc(fp)) && (s[i] != EOF)) {
        i++;
    }
    s[i] = '\0';
    fclose(fp);

    char *ss = strstr(s, inv);
    int beg = ss - s;
    int end = beg + strlen(inv);
    for (int i = 0; i < (int)strlen(s); i++) {
        if (i >= beg && i < end) continue;
        if (i == end && s[i] == ' ') continue;
        putchar(s[i]);
    }

    return 0;
}