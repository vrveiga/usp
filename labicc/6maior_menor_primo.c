#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    int men = -1, mai = -1;
    for (int i = a; i <= b; i++) {
        int ok = 1;
        if (i == 1 || i == 0) ok = 0;
        for (int j = 2; j*j < i; j++) {
            if (i % j == 0) ok = 0;
        }
        if (ok) {
            if (men == -1) men = i;
            mai = i;
        }
    }
    if (mai == -1 && men == -1) {
        printf("nenhum primo no intervalo\n");
    } else {
        printf("menor primo: %d\nmaior primo: %d\n", men, mai);
    }
}