#include <stdlib.h>
#include <stdio.h>

void printa(int v[], int l, int r) {
    for (int i = l; i <= r; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void insertion_sort(int v[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= l && x < v[j]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
    printa(v, l, r);
}

int conta_um(int x) {
    int ret = 0;
    while (x != 0) {
        if (x & 1) ret++;
        x >>= 1;
    }
    return ret;
}

void bucket_sort(int v[], int n) {
    int bucket[10][1010];
    int tam[11] = {};

    for (int i = 0; i < n; i++) {
        int idx = conta_um(v[i]);
        bucket[idx][tam[idx]] = v[i];
        tam[idx]++;
    }

    for (int i = 0; i < 11; i++) {
        if (tam[i] > 0) {
            insertion_sort(bucket[i], 0, tam[i]-1);
        }
    }

    insertion_sort(v, 0, n-1);

    int idx = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < tam[i]; j++) {
            v[idx++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int v[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    bucket_sort(v, n);

    return 0;
}
