#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto_ {
    float x;
    float y;
};

PONTO *ponto_criar (float x, float y) {
    PONTO *p = malloc(sizeof(PONTO));
    if (p != NULL) {
        p->x = x;
        p->y = y;    
    }
    return p;
}

void ponto_apagar (PONTO **p) {
    if (*p != NULL) {
        free(*p);
        *p = NULL;
    } else {
        exit(-1);
    }
}

bool ponto_set (PONTO *p, float x, float y) {
    if (p != NULL) {
        p->x = x;
        p->y = y;
        return true;
    }
    return false;
}

float ponto_get_x (PONTO *p) {
    if (p != NULL) {
        return p->x;
    }
    exit(-1);
}

float ponto_get_y (PONTO *p) {
    if (p != NULL) {
        return p->y;
    }
    exit(-1);
}

void ponto_print (PONTO *p) {
    if (p != NULL) {
        printf("(%.1f, %.1f)", p->x, p->y);
    } else {
        exit(-1);
    }
}

float distancia (PONTO *p1, PONTO *p2) {
    // Faz mais sentido adicionar a função distancia aqui pois tem uma boa chance de
    // que essa função precise ser utilizada em uma aplicação que somente usa a TAD 
    // de ponto, já que não é necessário nenhum círculo para rodar a função.
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
}