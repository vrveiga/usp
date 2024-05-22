#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%02d/%02d/%02d\n", (n-n%1000000)/1000000, (n%1000000 - n%10000)/10000, n%10000);

    return 0;
}