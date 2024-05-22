#include <stdio.h>

int main(void) 
{
    int n, mai = -1;
    float resultado = 0, lucrorel = -1;

    scanf("%d", &n);

    if (n == 0) {
        printf("Sem atividades registradas hoje\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        float precoc, precov;
        int qntc, qntv;
        scanf("%f%f%d%d", &precoc, &precov, &qntc, &qntv);
        float lucroat = precov*qntv - precoc*qntc;
        resultado += lucroat;
        if (lucroat > lucrorel) {
            mai = i;
            lucrorel = lucroat;
        }
    }

    if (resultado < 0) {
        printf("prejuizo: %.2f\n", -1 * resultado);
    } else {
        printf("lucro: %.2f\n", resultado);
    }

    printf("produto: %d lucro relativo: %.2f\n", mai, lucrorel);

    return 0;
}