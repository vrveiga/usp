#include <stdio.h>

int main(void)
{
    int d, bool;
    scanf("%d%d", &d, &bool);

    if (d < 1 || d > 7) {
        printf("Dia nao registrado\n");
        return 0;
    }

    if (bool == 0)
        switch (d) {
            case 1 : printf("Segunda: Aula de computacao\n");
            case 2 : printf("Terca: Treino de volei\n");
            case 3 : printf("Quarta: Aula de calculo\n");
            case 4 : printf("Quinta: Lista de GA\n");
            case 5 : printf("Sexta: Festa da Sacim\n");
            case 6 : printf("Sabado: Jantar em familia\n");
            case 7 : printf("Domingo: Depressao pos final de semana\n");
        }
    else {
        switch (d) {
            case 1 : printf("Segunda: Aula de computacao\n"); break;
            case 2 : printf("Terca: Treino de volei\n"); break;
            case 3 : printf("Quarta: Aula de calculo\n"); break;
            case 4 : printf("Quinta: Lista de GA\n"); break;
            case 5 : printf("Sexta: Festa da Sacim\n"); break;
            case 6 : printf("Sabado: Jantar em familia\n"); break;
            case 7 : printf("Domingo: Depressao pos final de semana\n"); break;
        }
    }
    
    return 0;
}