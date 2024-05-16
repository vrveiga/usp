#include <stdio.h>

void swap(int *a, int *b);
void sort(int *v, int n);
int pos(int *v, int x);

int main(void) {
    int n, v[110], vsort[110];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
        vsort[i] = v[i];
    }
    sort(vsort, n);
    for (int i = 1 ; i < n; i++) {
        if (vsort[i] == vsort[i-1]) {
            vsort[i-1] = -1;
        }
    }
    sort(vsort, n);
    for (int i = 0; i < n; i++) {
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, v[i], pos(vsort, v[i]));
    }
}

void sort(int *v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (v[i] < v[j]) swap(v+i, v+j);
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int pos(int *v, int x) {
    int i = 1;
    while (1) {
        if (v[i-1] == x) return i;
        i++;
    }
}