#include <stdio.h>
#include <stdlib.h>

char * aloca_string(int n) {
    char *s;
    s = (char *) malloc((n+1));
    return s;
}

int * aloca_array(int n) {
    int *v;
    v = (int *) malloc(n * sizeof(int));
    return v;
}

char ** aloca_array_string(int n) {
    char **mat;
    mat = (char **) malloc(n * sizeof(char*));
    return mat;
}

int encontra_tamanho(int n) {
    int at = n, sum = 0;
    for (int i = 2; i <= n; i++) {
        if (at % i == 0) {
            sum += i;
            while (at % i == 0) {
                at /= i;
            }
        }
    }
    return sum;
}

void solve(int *ip, int *n, char **s) {
    scanf("%d%d", ip, n);
    int tam = encontra_tamanho(*n);
    *s = aloca_string(tam);
    scanf("%s", *s);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_str(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void ordena(int *vetip, int *vetn, char **vets, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (vetip[i] < vetip[j]) {
                swap(&vetip[i], &vetip[j]);
                swap(&vetn[i], &vetn[j]);
                swap_str(&vets[i], &vets[j]);
            }
        }
    }
}

void imprima(int *vetn, char **vets, int n) {
    if (n == 0) {
        printf("Sem produtos a serem cadastrados\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", vets[i], vetn[i]);
    }
}

void desaloca_str(char **s, int n) {
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
}

int main(void) {
    int q, *vetip, *vetn;
    char **vets;
    scanf("%d", &q);
   
    vetip = aloca_array(q);
    vetn = aloca_array(q);
    vets = aloca_array_string(q);
    
    for (int i = 0; i < q; i++) {
        int ip, n;
        char *s;
        solve(&ip, &n, &s);
        
        vetip[i] = ip;
        vetn[i] = n;
        vets[i] = s;
    }
    
    ordena(vetip, vetn, vets, q);
    imprima(vetn, vets, q);

    free(vetip);
    free(vetn);
    desaloca_str(vets, q);

    return 0;
}