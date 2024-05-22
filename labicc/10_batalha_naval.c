#include <stdio.h>

void leia(int n, char t[30][30]);
void testa(int n, char t[30][30], int a, int b);
void escreva(int n, char t[30][30]);

int main(void) {
    int n;
    char t[30][30];
    scanf("%d", &n);
    leia(n, t);
    
    int q;
    scanf("%d", &q);

    while (q--) {
        char a;
        int b;
        scanf(" %c%d", &a, &b);
        testa(n, t, a-'A', b-1);
    }

    escreva(n, t);
}

void leia(int n, char t[30][30]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &t[i][j]);
        }
    }
}

void testa(int n, char t[30][30], int a, int b) {
    if (t[a][b] == 'N') {
        printf("acerto!\n");
        t[a][b] = 'X';
    } else {
        printf("erro!\n");
    }
}

void escreva(int n, char t[30][30]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", t[i][j]);
        }
        printf("\n");
    }   
}