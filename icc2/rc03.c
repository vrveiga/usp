#include <stdio.h>
#include <stdbool.h>

bool rec(int x, int* v, int n) {
    if (n == 0) {
        if (x == 23)
            return true;
        else
            return false;
    }

    if(rec(x+v[0], v+1, n-1) || rec(x-v[0], v+1, n-1) || rec(x*v[0], v+1, n-1))
        return true;
    
    return false;
}

void permut(int* v, int *p, bool* visited, int n, bool* resp) {
    if (n == 5) {
        
        if (rec(p[0], p+1, 4))
            *resp = true;

    } else {
        for (int i = 0; i < 5; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            p[n] = v[i];
            permut(v, p, visited, n+1, resp);
            visited[i] = false;
        }
    }
}

int main() {
    while (1) {
        int v[5];
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", v+i);
            cnt += v[i];
        }
        if (cnt == 0) break;

        bool visited[5] = {};
        int p[5] = {};

        bool ok = false;

        permut(v, p, visited, 0, &ok);

        if (ok) 
            printf("possivel\n");
        else
            printf("impossivel\n");
    }
}