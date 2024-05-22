#include <stdio.h>
#include <stdlib.h>

int* aloca(int n) {
    int* vet;
    vet = (int*) malloc(n * sizeof(int));
    return vet;
}

void ordena(int* v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (v[i] > v[j]) {
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

void leia(int* v, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ordena(v, n);
}

void imprima(int* v, int n) {
    if (n == 0) {
        printf("vazio\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int* uniao(int *a, int n, int *b, int m, int* unisz) {
    int *ret;
    ret = aloca(0);
    int i = 0, j = 0, sz = 0;
    while (i < n || j < m) {
        if (i == n) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = b[j];
            j++;
            sz++;
        }
        else if (j == m) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = a[i];
            i++;
            sz++;
        }
        else if (a[i] == b[j]) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = a[i];
            i++;
            j++;
            sz++;
        }
        else if (a[i] > b[j]) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = b[j];
            j++;
            sz++;
        }
        else if (a[i] < b[j]) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = a[i];
            i++;
            sz++;
        }
    }
    *unisz = sz;
    return ret;
}

int* uniint(int *a, int n, int *b, int m, int* uninsz) {
    int *ret;
    ret = aloca(0);
    int i = 0, j = 0, sz = 0;
    while (i < n || j < m) {
        if (i == n) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = b[j];
            j++;
            sz++;
        }
        else if (j == m) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = a[i];
            i++;
            sz++;
        }
        else if (a[i] == b[j]) {
            i++;
            j++;
        }
        else if (a[i] > b[j]) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = b[j];
            j++;
            sz++;
        }
        else if (a[i] < b[j]) {
            ret = realloc(ret, (sz+1) * sizeof(int));
            ret[sz] = a[i];
            i++;
            sz++;
        }
    }
    *uninsz = sz;
    return ret;
}

int main(void) {
    int n, m, unisz, uninsz;
    int *a, *b, *uni, *unin;

    scanf("%d", &n);
    a = aloca(n);
    leia(a, n);

    scanf("%d", &m);
    b = aloca(m);
    leia(b, m);

    printf("conjunto A: ");
    imprima(a, n);
    printf("conjunto B: ");
    imprima(b, m);

    uni = uniao(a, n, b, m, &unisz);
    unin = uniint(a, n, b, m, &uninsz);

    printf("A uniao B: ");
    imprima(uni, unisz);
    printf("(A uniao B) - (A interseccao B): ");
    imprima(unin, uninsz);
}