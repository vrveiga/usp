#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char *cpf;
    int idade;
    float saldo;
    float credito;
    float divida;
} Pessoa;

char * leiaString() {
    char s[40];
    scanf(" %s", s);
    char *buffer = malloc(strlen(s) * sizeof(char));
    strcpy(buffer, s);
    buffer[strlen(s)-1] = '\0';
    return buffer;
}

void desaloca(Pessoa *d, int n) {
    for (int i = 0; i < n; i++) {
        free(d[i].nome);
        free(d[i].cpf);
    }
    free(d);
}

int main() {
    int n;
    scanf("%d", &n);
    
    Pessoa *database = malloc(n * sizeof(Pessoa));
    for (int i = 0; i < n; i++) {
        database[i].nome = leiaString();
        database[i].cpf = leiaString();
        scanf("%d", &database[i].idade);
        getchar();
        scanf("%f", &database[i].saldo);
        getchar();
        scanf("%f", &database[i].credito);
        getchar();
        database[i].divida = database[i].credito - database[i].saldo;
    }

    for (int i = 0; i < n; i++) {
        printf("Dados da pessoa %d:\n", i+1);
        printf("Nome: %s\nCPF: %s\nIdade: %d\nSaldo: %.2f\nCredito: %.2f\n\n", 
            database[i].nome, database[i].cpf, database[i].idade, database[i].saldo, database[i].credito);
        
    }

    printf("Pessoas endividadas:");
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (database[i].divida > 0) {
            ok = 1;
            printf("\nNome: %s\nCPF: %s\nDivida: %.2f\n", 
                database[i].nome, database[i].cpf, database[i].divida);
        }
    }
    if (!ok) {
        printf("\nNenhuma pessoa endividada encontrada.\n");
    }
    desaloca(database, n);
    
    return 0;
}