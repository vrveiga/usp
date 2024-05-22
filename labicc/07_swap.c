#include <stdio.h>

int main(void) {
    int n1, n2, temp;
    scanf("%d%d", &n1, &n2);
    int *ptr1 = &n1, *ptr2 = &n2;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("%d %d\n", n1, n2);
}