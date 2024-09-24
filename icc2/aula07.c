// Problema Maximum Subarray Sum

#include <stdio.h>

#define min(a,b) (a) < (b) ? a : b
#define max(a,b) (a) > (b) ? a : b
const int MIN = -999999999;

// Solução em O(N^3);

int on3(int vet[], int n) {
    int ret = MIN, sum = 0;
    for (int range = 1; range <= n; range++) { //seta o range
        for (int i = 0; i <= n-range; i++) { //seta o inicio da substring
            for (int j = i; j < range+i; j++) //percorre do inicio ao fim da substring
                sum += vet[j];

        ret = max(ret,sum);
        sum = 0;
        }
    }  
    return ret;
}

// Solução em O(NlogN)

// Teorema Mestre
// T(N) = aT(N/b)+O(N^d)
// a = 2 (número de subproblemas)
// b = 2 (fator de divisão de N)
// d = 1 O(N^1) fora das chamadas
// Como a = b^d, a complexidade é O(N^d * logN) = O(NlogN).

int onlogn(int vet[], int l, int r) {
    if (l == r) return vet[l];
    
    int m = (l+r)/2;

    int at = 0, lsum = MIN, rsum = MIN;
    for (int i = m; i >= l; i--) {
        at += vet[i];
        if (at > lsum) lsum = at;
    }
    at = 0;
    for (int i = m+1; i <= r; i++) {
        at += vet[i];
        if (at > rsum) rsum = at;
    }

    int ret = lsum + rsum;

    int k = onlogn(vet, l, m);
    if (k > ret) ret = k;
    
    k = onlogn(vet, m+1, r);
    if (k > ret) ret = k;

    return ret;
}

// Solução em O(N)

int on(int vet[], int n) {
    int s = 0;
    int men = 0;
    int ret = MIN;
    for (int i = 0; i < n; i++) {
        s += vet[i];
        ret = max(ret, s - men);
        men = min(men, s);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int vet[n+1];
    for (int i = 0; i < n; i++)
        scanf("%d", vet+i);

    int r1 = on3(vet, n);
    int r2 = onlogn(vet, 0, n-1);
    int r3 = on(vet, n);

    printf("%d %d %d\n", r1, r2, r3);
}