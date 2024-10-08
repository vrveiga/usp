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

void merge(int v[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = v[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }

    printa(v, l, r);

    free(L);
    free(R);
}

void merge_sort(int v[], int l, int r, int k) {
    if (r - l + 1 <= k) {
        insertion_sort(v, l, r);
        return;
    }

    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(v, l, m, k);
        merge_sort(v, m + 1, r, k);
        merge(v, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int v[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int k;
    scanf("%d", &k);

    merge_sort(v, 0, n - 1, k);

    return 0;
}
