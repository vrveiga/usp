#include <stdio.h>

int main(void) {
    int n, v[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
    }
    for (int i = n-1; i >= 0; i--) {
        printf("%d ", *(v+i));
    }
    printf("\n");
    return 0;
}