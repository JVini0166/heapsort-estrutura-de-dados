#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void rotacionar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int l,
           int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],
               int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
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

void executeMergeSort() {

    int mergeSortArr[] = {4, 10, 3, 5, 1};
    int iteracoes = 0;
    int N = sizeof(mergeSortArr)/sizeof(*mergeSortArr);

    int msec = 0, trigger = 10; /* 10ms */
    clock_t before = clock();

    do {
        // Chamando função QuickSort
        mergeSort(mergeSortArr, 0, N - 1);
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
        iteracoes++;
    } while ( msec < trigger );

    printf("Levou %d segundos e %d millisegundos (%d clocks) para executar com MergeSort\n",
           msec/1000, msec%1000, iteracoes);


    printf("Depois do MergeSort:\n");
    for (int i = 0 ; i < N ; i++)
        printf("%d ", mergeSortArr[i]);
}

// Main :)
int main() {

    executeHeapSort();
    executeMergeSort();

    return 0;
}