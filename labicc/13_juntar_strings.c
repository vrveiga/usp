#include <stdio.h>
#include <string.h>

int main() {
    char a[140], b[140], c[30];
    fgets(a, 140, stdin);
    fgets(b, 140, stdin);
    fgets(c, 30, stdin);

    char *aa = strstr(a, c);
    char *bb = strstr(b, c);

    int ta = 0;

    if (aa == NULL) {
        for (int i = 0; i < (int)strlen(a) - 2; i++) {
            printf("%c", a[i]); 
        }
        ta = 1;
    } else {
        int end = aa - a;
        for (int i = 0; i < end; i++) {
            printf("%c", a[i]);
        }
    }
    
    if (bb != NULL) {
        if (ta) {
            printf(" ");
        }
        int str = bb - b;
        for (int i = str + strlen(c) + 1; i < (int)strlen(b) - 1; i++) {
            printf("%c", b[i]);
        }
    }

    printf("\n");

    return 0;
}