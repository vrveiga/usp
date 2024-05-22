#include <stdio.h>
#include <stdlib.h>

int sqr(int x);
int** aloca(int n);
void desaloca(int **mat, int n);
void leia(int **mat, int n);
void escreva (int **mat, int n);

int main(void) {
    int n;
    int **mat;

    scanf("%d", &n);
    n = sqr(n);

    mat = aloca(n);
    leia(mat, n);
    escreva(mat, n);
    free(mat);

    return 0;
}

int sqr(int x) {
    int k = 1;
    while (k*k < x) {
        k++;
    }
    return k;
}

int** aloca(int n) {
    int **mat;
    mat = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
    }
    return mat;
}

void desaloca(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

void leia(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void escreva (int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
