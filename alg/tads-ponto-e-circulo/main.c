#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main() {
    float px, py, cx, cy, r;
    scanf("%f%f%f%f%f", &px, &py, &cx, &cy, &r);

    PONTO *ponto = ponto_criar(px, py);
    PONTO *centro = ponto_criar(cx, cy);
    CIRCULO *circulo = circulo_criar(centro, r);

    printf("Ponto: (%.1f, %.1f)\n", ponto_get_x(ponto), ponto_get_y(ponto));
    printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f\n", ponto_get_x(centro), ponto_get_y(centro), circulo_get_raio(circulo));

    ponto_apagar(&ponto);
    circulo_apagar(&circulo);

    return 0;
}