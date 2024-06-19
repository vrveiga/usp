#include <stdio.h>
#include <string.h>

void geraPalavra(int x, int y, int m, char v[30][26], char *at) {
    char att[30];
    memcpy(att, at, sizeof(att));
    att[x] = v[x][y];

    if (x == m-1) {
        printf("%s\n", att);
        return;
    }

    for (int i = 0; i < 26; i++) {
        geraPalavra(x+1, i, m, v, att);
    } 
}

int main() {
    int m;
    scanf("%d", &m);

    char v[30][26], at[30];
    memset(at, '\0', sizeof(at));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            v[i][j] = 'a' + j;
        }
    }

    for (int i = 0; i < 26; i++) {
        geraPalavra(0, i, m, v, at);
    }

    return 0;
}