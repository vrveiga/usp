#include <stdio.h>

void leia(char t[25][25], int n, int m);
int entenda(char t[25][25], int n, int m, int linha[25], int coluna[25], char resp[25][25]);
void escreva(char resp[25][25], int n, int m);

int main(void) {
    int n, m, linha[25] = {}, coluna[25] = {};
    char t[25][25], resp[25][25];

    scanf("%d%d", &n, &m);
    leia(t, n, m);
    if (entenda(t, n, m, linha, coluna, resp)) {
        escreva(resp, n, m);
    } else {
        printf("Eh um dia triste para os mono Yasuo\n");
    }
}

void leia(char t[25][25], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &t[i][j]);
        }
    }
}

int entenda(char t[25][25], int n, int m, int linha[25], int coluna[25], char resp[25][25]) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (t[i][j] ==  'c') {
                linha[i] = 1;
                coluna[j] = 1;
            }
        }
    }

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            if (t[i][j] == 'v' && linha[i] == 0 && coluna[j] == 0) {
                ret = 1;
                resp[i][j] = 'o';
            } else {
                resp[i][j] = 'x';
            }
        }
    }
    return ret;
}

void escreva(char resp[25][25], int n, int m) {
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", resp[i][j]);
        }
        printf("\n");
    }
}