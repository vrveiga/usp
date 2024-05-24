#include <stdio.h>
#include <stdlib.h>

char ** aloca_matriz(int n, int m) {
    char **mat;
    mat = (char **) malloc(n * sizeof(char *));
    
    for (int i = 0; i < n; i++) {
        mat[i] = (char *) malloc(m * sizeof(char));
    }

    return mat;
}

void desaloca_matriz(char **mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

void leia(char **mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }
}

void imprima(char **mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void solve(char **mat, int n, int m) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'X') {
                continue;
            }
            int vizinhos = 0;
            
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    continue;
                }
                if (mat[x][y] == 'X') { 
                    vizinhos++;
                }
            }

            if (vizinhos % 2 == 0) {
                mat[i][j] = '*';
            } 
        }
    }
}

int main(void) {
    int n, m;
    char **mat;
    
    scanf("%d%d", &n, &m);

    mat = aloca_matriz(n, m);
    leia(mat, n, m);
    
    solve(mat, n, m);
    imprima(mat, n, m);

    desaloca_matriz(mat, n);
    
    return 0;
}