#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * nome;
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
} Receita;

typedef struct { 
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
} Estoque;

int main() {
    char op;
    int tot = 0, f, ov, ol, a, c;
    Receita *livro = NULL;
    Estoque estoque = {0, 0, 0, 0, 0};
    
    while(1) {
        scanf(" %c", &op);

        if (op == 'R') {
            livro = realloc(livro, (tot+1) * sizeof(Receita));
            livro[tot].nome = malloc(20 * sizeof(char));

            scanf("%s %d %d %d %d %d", livro[tot].nome, &f, &ov, &ol, &a, &c);
            livro[tot].farinha = f;
            livro[tot].ovos = ov;
            livro[tot].oleo = ol;
            livro[tot].acucar = a;
            livro[tot].chocolate = c;
            tot++;
        }
        else if (op == 'C') {
            scanf("%d %d %d %d %d", &f, &ov, &ol, &a, &c);
            estoque.farinha += f;
            estoque.ovos += ov;
            estoque.oleo += ol;
            estoque.acucar += a;
            estoque.chocolate += c;
        }
        else if (op == 'F') {
            int k;
            scanf("%d", &k);
            if (k >= tot) {
                printf("Receita nao encontrada!\n");
            }
            else if (estoque.farinha < livro[k].farinha) {
                printf("Farinha insuficiente\n");
            }
            else if (estoque.ovos < livro[k].ovos) {
                printf("Ovos insuficientes\n");
            }
            else if (estoque.oleo < livro[k].oleo) {
                printf("Oleo insuficiente\n");
            }
            else if (estoque.acucar < livro[k].acucar) {
                printf("Acucar insuficiente\n");
            }
            else if (estoque.chocolate < livro[k].chocolate) {
                printf("Chocolate insuficiente\n");
            }
            else {
                estoque.farinha -= livro[k].farinha;
                estoque.ovos -= livro[k].ovos;
                estoque.oleo -= livro[k].oleo;
                estoque.acucar -= livro[k].acucar;
                estoque.chocolate -= livro[k].chocolate;
                printf("%s feita com sucesso!\n", livro[k].nome);
            }
        }
        else if (op == 'S') {
            printf("Quantidade no estoque:\n");
            printf("Acucar: %d\n", estoque.acucar);
            printf("Chocolate: %d\n", estoque.chocolate);
            printf("Farinha: %d\n", estoque.farinha);
            printf("Oleo: %d\n", estoque.oleo);
            printf("Ovos: %d\n", estoque.ovos);
            printf("Receitas cadastradas: %d\n", tot);
            break;
        }
        else {
            printf("Codigo invalido\n");
        }
    }

    for (int i = 0; i < tot; i++) {
        free(livro[i].nome);
    }
    free(livro);

    return 0;
}