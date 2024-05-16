#include <stdio.h>
#include <string.h>

void inteiroParaRomano(int x) {
    char n[100] = {};
    int i = 0;
    int cnt = 0;
    char ch[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    while (x > 0) {
        int y = x % 10;
        switch (y) {
            case 1: n[i] = ch[2*cnt]; i++; break;
            case 2: n[i] = ch[2*cnt]; n[i+1] = ch[2*cnt]; i+=2; break;
            case 3: n[i] = ch[2*cnt]; n[i+1] = ch[2*cnt]; n[i+2] = ch[2*cnt]; i+=3; break;
            case 4: n[i] = ch[2*cnt+1]; n[i+1] = ch[2*cnt]; i+=2; break;
            case 5: n[i] = ch[2*cnt+1]; i++; break;
            case 6: n[i] = ch[2*cnt]; n[i+1] = ch[2*cnt+1]; i+=2; break;
            case 7: n[i] = ch[2*cnt]; n[i+1] = ch[2*cnt]; n[i+2] = ch[2*cnt+1]; i+=3; break;
            case 8: n[i] = ch[2*cnt]; n[i+1] = ch[2*cnt]; n[i+2] = ch[2*cnt]; n[i+3] = ch[2*cnt+1]; i+=4; break;
            case 9: n[i] = ch[2*cnt+2]; n[i+1] = ch[2*cnt]; i+=2; break;
        }
        cnt++;
        x /= 10;
    }
    int len = strlen(n);
    for (int i = len-1; i >= 0; i--) printf("%c", n[i]);
    printf("\n");
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        inteiroParaRomano(x);
    }
}