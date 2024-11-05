#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

// simples, O(n^2), não muito utilizado
void bubble(int v[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (v[j] < v[j - 1])
                swap(v + j, v + j + 1);
}

void quick(int v[], int n) {

}
