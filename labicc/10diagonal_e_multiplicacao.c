#include <stdio.h>

void leia(int n, int t[100][100]);
void escreva(int n, int t[100][100]);
int eh_diagonal(int n, int t[100][100]);
void multiplica(int n, int t1[100][100], int t2[100][100]);

int main(void) {
    int n, m, t1[100][100], t2[100][100];
    scanf("%d%d", &n, &m);
    
    leia(n, t1);
    leia(m, t2);

    printf("Matrizes:\n");
    escreva(n, t1);
    escreva(m, t2);
    
    if (eh_diagonal(n, t1)) {
        printf("A matriz 1 eh diagonal\n");
    } else {
        printf("A matriz 1 nao eh diagonal\n");
    }
    if (eh_diagonal(m, t2)) {
        printf("A matriz 2 eh diagonal\n");
    } else {
        printf("A matriz 2 nao eh diagonal\n");
    }

    if (n == m) {
        multiplica(n, t1, t2);
    } else {
        printf("Matrizes de tamanho incompativel\n");
    }
}

void leia(int n, int t[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &t[i][j]);
        }
    }
}

void escreva(int n, int t[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

int eh_diagonal(int n, int t[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && t[i][j] != 0) return 0;
        }
    }
    return 1;
}

void multiplica(int n, int t1[100][100], int t2[100][100]) {
    printf("Matriz multiplicada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int s = 0;
            for (int k = 0; k < n; k++) {
                s += t1[i][k] * t2[k][j];
            }
            printf("%d ", s);
        }
        printf("\n");
    }
}