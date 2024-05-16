#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        float a, b;
        int t;
        scanf("%f%f%d", &a, &b, &t);
        if (t == 0) {
            printf("A corrida ainda nao comecou\n");
        } else if (a == 0 && b == 0) {
            printf("Os dois pilotos nao querem competir\n");
        } else if (a == 0) {
            printf("O piloto A desistiu inesperadamente\n");
        } else if (b == 0) {
            printf("O piloto B desistiu inesperadamente\n");
        } else if (t < 0) {
            printf("De alguma forma os pilotos voltaram no tempo\n");
        } else if (a == b) {
            printf("Os karts empataram, percorrendo cada %.2fkm\n", a*t);
        } else if (a > b) {
            printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", (a-b)*t);
        } else if (b > a) {
            printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", (b-a)*t);
        }
    }
}