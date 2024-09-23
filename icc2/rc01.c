#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a, const void* b)
{
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int m;
    scanf(" %d", &m);

    char a[30], b[30];

    for (int i = 0; i < m; i++) {
        scanf("%c", a+i);
        b[i] = a[i];
    }

    qsort(b, m, sizeof(char), cmp);

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        if (a[i] != b[i]) cnt++;
    }

    if (cnt == 0 || cnt == 2) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}