// Shell Sort e Inserção Simples

/**********************************************************************************************************************
| Método:                 N = |    10    |    100   |   1000   |   10000  |   10^6   |   10^7   |   10^8   |   10^9   | 
| Insertion Sort              | 0.000002 | 0.000042 | 0.003826 | 0.118806 |  >10min  |  >>>>>>  |  >>>>>>  | Estoura  |
| h[] = {5, 3, 1}             | 0.000002 | 0.000051 | 0.003312 | 0.108158 |  >10min  |  >>>>>>  |  >>>>>>  | Estoura  |
| N/2^k (Original)            | 0.000002 | 0.000009 | 0.000108 | 0.000546 | 0.070795 | 0.825019 | 9.488275 | Estoura  |
| 2^k-1 (Hibbard)             | 0.000001 | 0.000010 | 0.000100 | 0.000497 | 0.064523 | 0.724818 | 9.086136 | Estoura  |
| (9(9/4)^k-4)/5 (Tokuda)     | 0.000001 | 0.000010 | 0.000095 | 0.000437 | 0.056544 | 0.695130 | 7.729941 | Estoura  |
| h(i+1) = 3*h(i) + 1 (Knuth) | 0.000001 | 0.000008 | 0.000078 | 0.000369 | 0.046409 | 0.566931 | 6.743652 | Estoura  |
**********************************************************************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i-1;
        while (j >= 0 && x < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void shell_sort(int v[], int n, int hh[], int nh) {
    for (int k = 0; k < nh; k++) {
        int h = hh[k];
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j;
            for (j = i - h; j >= 0 && v[j] > x; j-=h)
                v[j+h] = v[j];
            v[j+h] = x;
        }
    }
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int *a, n;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        a[i] = n-i;

    printf("Tempo estimado n^2 operações: %lf\n", (double) n/(9*1e8)*n);

    clock_t start, end;

    start = clock();
    // insertion_sort(a, n);
    end = clock();

    double tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Insertion: %lf\n", tempo);

    for (int i = 0; i < n; i++)
        a[i] = n-i;

    int h[30];

    h[2] = 5, h[1] = 3, h[0] = 1;

    start = clock();
    // shell_sort(a, n, h, 3);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Shell Ruim: %lf\n", tempo);

    for (int i = 0; i < n; i++)
        a[i] = n-i;

    int pot = 1;
    int id = 0;
    while (n/pot >= 1) {
        h[id] = n/pot;
        pot*=2;
        id++;
    }
    
    start = clock();
    shell_sort(a, n, h, id);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Shell Original: %lf\n", tempo);

    for (int i = 0; i < n; i++)
        a[i] = n-i;

    pot = 2;
    id = 0;
    while (pot - 1 < n) {
        h[id] = pot - 1;
        pot *= 2;
        id++;
    }
    for (int i = 0, j = id-1; i < j; i++, j--) {
        swap(h+i, h+j);
    }
    // for (int i = 0; i < id; i++) printf("%d ", h[i]);
    // printf("\n");
    
    start = clock();
    shell_sort(a, n, h, id);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Shell Hibbard: %lf\n", tempo);

    for (int i = 0; i < n; i++)
        a[i] = n-i;

    id = 0;
    while (ceil((9*pow(9.0/4, id)-4)/5) < n) {
        h[id] = ceil((9*pow(9.0/4, id)-4)/5);
        id++;
    }
    for (int i = 0, j = id-1; i < j; i++, j--) {
        swap(h+i, h+j);
    }
    // for (int i = 0; i < id; i++) printf("%d ", h[i]);
    // printf("\n");
    
    start = clock();
    shell_sort(a, n, h, id);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Shell Tokuda: %lf\n", tempo);

    for (int i = 0; i < n; i++)
        a[i] = n-i;

    h[19] = 1;
    for (int i = 18; i >= 0; i--) {
        h[i] = h[i+1]*3+1;
    }

    start = clock();
    shell_sort(a, n, h, 20);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Shell Knuth: %lf\n", tempo);
}