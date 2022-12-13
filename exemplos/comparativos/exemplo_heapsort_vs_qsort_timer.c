#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Comparador
int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
// Função para trocar a posição de dois elementos

void rotacionar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

void executeHeapSort() {

    int heapSortArr[] = {4, 10, 3, 5, 1};
    int iteracoes = 0;
    int N = sizeof(heapSortArr) / sizeof(heapSortArr[0]);

    int msec = 0, trigger = 10; /* 10ms */
    clock_t before = clock();

    do {
        // Chamando função
        heapSort(heapSortArr, N);
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
        iteracoes++;
    } while ( msec < trigger );

    printf("Levou %d segundos e %d millisegundos (%d clocks) com HeapSort\n",
           msec/1000, msec%1000, iteracoes);


    printf("Depois do HeapSort:\n");
    printArray(heapSortArr, N);
}

void executeQsort() {

    int qsortArr[] = {4, 10, 3, 5, 1};
    int iteracoes = 0;
    int N = sizeof(qsortArr)/sizeof(*qsortArr);

    int msec = 0, trigger = 10; /* 10ms */
    clock_t before = clock();

    do {
        // Chamando função Qsort
        qsort(qsortArr, N, sizeof(*qsortArr), comp);
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
        iteracoes++;
    } while ( msec < trigger );

    printf("Levou %d segundos e %d millisegundos (%d clocks) para executar com Qsort\n",
           msec/1000, msec%1000, iteracoes);


    printf("Depois do Qsort:\n");
    for (int i = 0 ; i < N ; i++)
        printf("%d ", qsortArr[i]);
}

// Main :)
int main() {

    executeHeapSort();
    executeQsort();

    return 0;
}