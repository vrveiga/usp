#include <stdio.h>

int main(void) {
    int op, qnt = 0, prod;
    while (1) {
        scanf("%d", &op);
        if (op == 3)
            break;
        else {
            if (op == 1) {
                scanf("%d", &prod);
                qnt++;
            } 
            else {
                printf("%d\n", qnt);
            }
        }
    }
}