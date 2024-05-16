#include <stdio.h>

int main(void) {
    int n, m, a[30], b[30];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", b+i);
    }
    int sum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (*(a+i)) {
            sum += (1 << (n-1-i));
        }
    }
    for (int i = m-1; i >= 0; i--) {
        if (*(b+i)) {
            sum += (1 << (m-1-i));
        }
    }
    printf("%d\n", sum);
}