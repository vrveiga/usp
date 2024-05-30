#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro {
    char *nome;
    char *autor;
    int ano;
    int qnt;
};

char* leia_str() {
    char *buffer = malloc(1 * sizeof(char));
    int size = 1, id = 0;
    char ch;
    getchar();

    while ((ch = getchar()) != ',' && ch != EOF) {
        if (id == size - 1) {
            size *= 2;
            buffer = realloc(buffer, size * sizeof(char));
        }
        buffer[id++] = ch;
    }
    buffer[id] = '\0';

    return buffer;
}

void escreva(struct livro *biblioteca, int n) {
    printf("Catalogo de Livros:\n");
    for (int i = 1; i <= n; i++) {
        printf("Livro %d:\n", i);
        printf("Titulo: %s\n", biblioteca[i-1].nome);
        printf("Autor: %s\n", biblioteca[i-1].autor);
        printf("Ano: %d\n", biblioteca[i-1].ano);
        printf("Quantidade: %d", biblioteca[i-1].qnt);
        if (i != n) printf("\n\n");
    }
}

int main() {
    int n, tam = 0;
    scanf("%d", &n);

    struct livro *biblioteca;
    biblioteca = malloc(n * sizeof(struct livro));

    for (int i = 0; i < n; i++) {
        char *nome = leia_str();
        char *autor = leia_str();
        int ano, ok = 0;
        scanf("%d", &ano);
        for (int j = 0; j < tam; j++) {
            if (!strcmp(nome, biblioteca[j].nome) && !strcmp(autor, biblioteca[j].autor) && ano == biblioteca[j].ano) {
                biblioteca[j].qnt++;
                ok = 1;
                free(nome);
                free(autor);
                break;
            }
        }
        if (!ok) {
            biblioteca[tam].nome = nome;
            biblioteca[tam].autor = autor;
            biblioteca[tam].ano = ano;
            biblioteca[tam].qnt = 1;
            tam++;
        }
    }

    escreva(biblioteca, tam);
    free(biblioteca);

    return 0;
}