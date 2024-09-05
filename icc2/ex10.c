// maior soma de subsequência em um vetor

#include <stdio.h>

const int MIN = -999999999;

int solve(int v[], int l, int r) {
    if (l == r) return v[l];
    
    int m = (l+r)/2;

    int at = 0, lsum = MIN, rsum = MIN;
    for (int i = m; i >= l; i--) {
        at += v[i];
        if (at > lsum) lsum = at;
    }
    at = 0;
    for (int i = m+1; i <= r; i++) {
        at += v[i];
        if (at > rsum) rsum = at;
    }

    int ret = lsum + rsum;

    int k = solve(v, l, m);
    if (k > ret) ret = k;
    
    k = solve(v, m+1, r);
    if (k > ret) ret = k;

    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int v[n+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
    }
    int resp = solve(v, 0, n-1);
    printf("%d\n", resp);
}