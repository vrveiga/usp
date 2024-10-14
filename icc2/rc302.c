#include <stdio.h>
#include <stdlib.h>

// Função para obter o maior valor do array
int getMax(int arr[], int n) {
    int max = abs(arr[0]);
    for (int i = 1; i < n; i++)
        if (abs(arr[i]) > max)
            max = abs(arr[i]);
    return max;
}

// Função para contar a ordenação com base em um dígito específico
void countSort(int arr[], int n, int exp) {
    int output[n];  // array de saída
    int count[10] = {0};

    // Contagem das ocorrências
    for (int i = 0; i < n; i++)
        count[(abs(arr[i]) / exp) % 10]++;

    // Modificação de count[] para conter a posição real de cada dígito
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(abs(arr[i]) / exp) % 10] - 1] = arr[i];
        count[(abs(arr[i]) / exp) % 10]--;
    }

    // Copiar o array de saída para arr[], para que arr[] contenha os números ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função para executar o Radix Sort
void radixSort(int arr[], int n) {
    // Encontrar o maior número para saber o número de dígitos
    int m = getMax(arr, n);

    // Executar a contagem de ordenação para cada dígito
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Função para dividir o array em negativos e não-negativos
void radixSortExtended(int arr[], int n) {
    int i, negCount = 0;

    // Contar quantos números negativos existem
    for (i = 0; i < n; i++)
        if (arr[i] < 0)
            negCount++;

    // Criar arrays separados para negativos e não-negativos
    int neg[negCount], pos[n - negCount];
    int negIndex = 0, posIndex = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] < 0)
            neg[negIndex++] = arr[i];
        else
            pos[posIndex++] = arr[i];
    }

    // Aplicar Radix Sort para ambos os arrays
    if (negCount > 0) {
        for (i = 0; i < negCount; i++) // Inverter o sinal dos negativos
            neg[i] = -neg[i];
        radixSort(neg, negCount);
        for (i = 0; i < negCount; i++) // Restaurar o sinal dos negativos
            neg[i] = -neg[i];
    }

    if (posIndex > 0)
        radixSort(pos, posIndex);

    // Combinar os negativos (em ordem decrescente) e não-negativos (em ordem crescente)
    for (i = 0; i < negCount; i++)
        arr[i] = neg[negCount - i - 1];
    for (i = 0; i < posIndex; i++)
        arr[negCount + i] = pos[i];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSortExtended(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}