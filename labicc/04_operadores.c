#include <stdio.h>

int main(void) 
{
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    
    if ((n1 > n2 && (n1 - n2)%3 == 0) || (n2 > n1 && n1+n2 > 400) || (n1 == n2 && n1%2 == 1)) {
        printf("%d\n", n1+n2);
    } else {
        printf("Nenhuma condicao foi satisfeita\n");
    }

    return 0;
}