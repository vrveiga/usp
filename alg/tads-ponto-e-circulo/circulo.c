#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

struct circulo_ {
    PONTO *p;
    float raio;
};

CIRCULO *circulo_criar (PONTO *p, float raio) {
    CIRCULO *c = malloc(sizeof(CIRCULO));
    if (c != NULL) {
        c->p = p;
        c->raio = raio;
    }
    return c;
}

bool circulo_set_ponto (CIRCULO *c, PONTO *p) {
    if (c != NULL) {
        c->p = p;
        return true;
    }
    return false;
}

bool circulo_set_raio (CIRCULO *c, float raio) {
    if (c != NULL) {
        c->raio = raio;
        return true;
    }
    return false;
}

PONTO *circulo_get_ponto (CIRCULO *c) {
    if (c != NULL) {
        return c->p;
    }
    exit(-1);
}

float circulo_get_raio (CIRCULO *c) {
    if (c != NULL) {
        return c->raio;
    }
    exit(-1);
}

void circulo_apagar (CIRCULO **circulo) {
    if (*circulo != NULL) {
        ponto_apagar(&((*circulo)->p));
        free(*circulo);
        *circulo = NULL;
    } else {
        exit(-1);
    }
}