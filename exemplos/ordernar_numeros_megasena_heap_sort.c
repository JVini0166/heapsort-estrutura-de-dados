#include <stdio.h>

// Usando HeapSort pra ordenar os números da MegaSena de todos os jogos de 3 meses atrás
// Parece que o número 8, 44, 38 são ótimos números para jogar nesse final de ano :) (Jogos Reais, peguei via API)

// Função para trocar a posição de dois elementos

void rotacionar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int count_occur(int a[], char exists[], int num_elements, int value)
{
    int i, count = 0;
    for (i = 0; i < num_elements; i++)
    {
        if (a[i] == value)
        {
            if (exists[i] != 0) return 0;
            ++count;
        }
    }
    return (count);
}


// Para empilhar uma subárvore enraizada com o nó i
// que é um índice em arr[].
// N é o tamanho do heap
void construirHeap(int arr[], int N, int i)
{
    // Encontra o maior entre raiz, filho esquerdo e filho direito

    // Inicializa o maior como a raiz
    int maior = i;

    // esquerdo = 2*i + 1
    int noEsquerdo = 2 * i + 1;

    // direito = 2*i + 2
    int noDireito = 2 * i + 2;

    // Se o filho esquerdo for maior que o nó raiz
    if (noEsquerdo < N && arr[noEsquerdo] > arr[maior]) {
        maior = noEsquerdo;
    }

    // Se o direito for maior que o nó raiz
    if (noDireito < N && arr[noDireito] > arr[maior]) {
        maior = noDireito;
    }

    // É feito a troca e continua heapificando se o nó raiz não for o maior
    // Se o maior não for o nó raiz
    if (maior != i) {
        rotacionar(&arr[i], &arr[maior]);
        // Recursivamente heapifica a subárvore afetada
        construirHeap(arr, N, maior);
    }
}

// Função do HeapSort
void heapSort(int arr[], int N)
{

    // Heapificar (construir o max heap)
    for (int i = N / 2 - 1; i >= 0; i--) {
        construirHeap(arr, N, i);
    }

    // HeapSort
    for (int i = N - 1; i >= 0; i--) {
        rotacionar(&arr[0], &arr[i]);

        // Heapificar o nó raiz pra pegar o maior elemento
        construirHeap(arr, i, 0);
    }
}

// Apenas uma subrotina que itera para apresentar o valor depois do HeapSort
// Lembrando que N é o tamanho do Heap
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Main :)
int main() {
    int arr[] = {15, 17, 20, 35, 37, 43,11, 25, 32, 37, 47, 56,01, 13, 27, 41, 51, 58,13, 19, 29, 42, 49, 52,18, 30, 32, 35, 40, 48,14, 20, 21, 31, 49, 52,02, 06, 11, 15, 17, 39,13, 26, 31, 46, 51, 60, 8, 10, 51, 56, 57, 58,10, 14, 15, 24, 34, 44, 9, 14, 22, 24, 44, 47,21, 38, 50, 53, 56, 59,28, 34, 40, 41, 52, 55,10, 19, 46, 47, 49, 50,15, 40, 44, 45, 47, 51,15, 24, 33, 49, 53, 59,16, 17, 18, 28, 35, 47, 8, 11, 16, 21, 32, 37,03, 16, 23, 41, 45, 57,11, 16, 31, 37, 42, 51,02, 07, 24, 43, 52, 56,03, 8, 23, 29, 53, 54,02, 03, 13, 20, 53, 54,01, 10, 19, 34, 35, 45,22, 35, 41, 42, 53, 57,05, 28, 30, 38, 52, 55,8, 33, 40, 42, 48, 51,8, 23, 29, 30, 36, 55,05, 13, 18, 23, 35, 36,15, 18, 28, 42, 55, 60,22, 30, 38, 39, 49, 56,01, 40, 44, 45, 58, 60,02, 07, 32, 46, 49, 55,20, 33, 37, 38, 49, 50,02, 17, 23, 28, 39, 46,10, 15, 17, 20, 21, 35,04, 06, 9, 31, 50, 56,01, 8, 21, 27, 36, 37,01, 32, 35, 44, 45, 57,20, 34, 38, 40, 49, 54,11, 14, 36, 41, 54, 59,05, 12, 32, 38, 47, 60,8, 9, 17, 19, 33, 56,23, 36, 42, 48, 54, 58,17, 31, 34, 40, 56, 57,03, 10, 13, 25, 41, 42,11, 16, 17, 41, 46, 59,22, 29, 38, 43, 48, 53,10, 30, 31, 33, 42, 52,04, 9, 37, 43, 44, 56,01, 04, 10, 22, 53, 54, 8, 12, 14, 30, 33, 41,07, 26, 31, 38, 46, 58,05, 14, 23, 46, 48, 52, 9, 12, 26, 29, 46, 47,11, 19, 38, 47, 56, 59,05, 16, 25, 32, 39, 55,11, 27, 32, 40, 58, 59,16, 20, 21, 39, 44, 55,03, 14, 16, 38, 43, 45,14, 33, 41, 42, 44, 55,03, 05, 19, 26, 43, 51,21, 22, 29, 34, 40, 44,04, 06, 12, 34, 35, 53,41, 45, 48, 51, 53, 58, 8, 37, 39, 50, 59, 60, 8, 13, 25, 32, 44, 57};
    int N = sizeof(arr) / sizeof(arr[0]);

    char exists[401] = {0};
    int num_occ, i;

    heapSort(arr, N);
    for (i = 0; i < 401; i++)
    {
        num_occ = count_occur(arr, exists, 401, arr[i]);
        if (num_occ) {
            exists[i] = 1;
            printf("O numero %d foi encontrado %d vezes.\n", arr[i], num_occ);
        }
    }

    // Chamando função
    printf("Depois do HeapSort:\n");
    printArray(arr, N);
}