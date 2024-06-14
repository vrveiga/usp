#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[30], *text;
    scanf("%s", s);
    text = malloc(1 * sizeof(char));
    int tam = 1;
    FILE *fp = fopen(s, "r");
    char c;
    while(fscanf(fp, "%c", &c) != EOF) {
        text = realloc(text, tam+1);
        text[tam-1] = c; 
        tam++;
    }
    text[tam-1] = '\0';
    puts(text);
    free(text);
    fclose(fp);
    return 0;
}