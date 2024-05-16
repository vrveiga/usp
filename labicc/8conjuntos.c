#include <stdio.h>

int main(void) 
{
    int n, m, v[10], tipo[10] = {};
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < n; j++) {
            if (x == v[j]) tipo[j] = 1;
        }
    }

    int ok = 0;
    printf("intersecao: ");
    for (int i = 0; i < n; i++) {
        if (tipo[i]) {
            printf("%d ", v[i]);
            ok = 1;
        }
    }
    if (!ok) printf("vazio");
    ok = 0;

    printf("\na - b: ");
    for (int i = 0; i < n; i++) {
        if (!tipo[i]) {
            printf("%d ", v[i]);
            ok = 1;
        }
    }
    if (!ok) printf("vazio");
    printf("\n");

    return 0;
}