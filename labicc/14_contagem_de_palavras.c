#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char aqr[20], palavra[20];
    scanf("%s %s", aqr, palavra);
    int len = strlen(palavra);

    for (int i = 0; i < len; i++) {
        palavra[i] = tolower(palavra[i]);
    }
    
    FILE *fp = fopen(aqr, "r");
    if (fp == NULL) return 1;

    int cnt = 0, i = 0;
    char ch, s[20];
    memset(s, '\0', sizeof(s));

    while (fscanf(fp, "%c", &ch) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            s[i] = tolower(ch);
            i++;
        } else if (ch == ' ' || ch == '\n') {
            if (!strcmp(s, palavra)) {
                cnt++;
            }
            memset(s, '\0', sizeof(s));
            i = 0;
        }
    }
    if (!strcmp(s, palavra)) {
        cnt++;
    }
    
    printf("quantidade: %d\n", cnt);

    fclose(fp);
    return 0;
}