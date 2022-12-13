## Como utilizar o HeapSort?

### Chamando a subrotina HeapSort, o que passar como parâmetro?

Para chamar a rotina HeapSort você precisa preencher os parâmetros passando um array e o número de posições dele após isso ele vai ordenar o array e todo seu conteúdo, após isso é só iterar sobre o array que terá ele ordenado pelo HeapSort. Isso pode ser exemplificado em 3 passos:

1. Chamar heapSort()
2. Passar como parâmetro o array: heapSort(int arr[], int N)
3. Iterar sobre o Array para ver o resultado da ordenação

Exemplo de declaração de array:  
`int arr[] = {4, 10, 3, 5, 1};`

### Como sei o número de posições do meu array?

Você pode fazer a divisão do array pela posição zero dele desta forma:

`sizeof(arr) / sizeof(arr[0]);`

### O que acontece por baixo dos panos??

Após isso ele vai iterar da metade do array até o início chamando a subrotina `construirHeap()`, passando nela como parâmetros o `array`, `numero de posições` e a variável `"i"` da iteração do laço de repetição. Após isso ele vai construir a estrutura

No algoritmo ele declara o maior como o nó raiz, e declara também o nó esquerdo como `2*i+1` e o direito `2*i+2` e faz as seguintes validações:

- Se o filho esquerdo for maior que o nó raiz: { maior = nó esquerdo }
- Se o direito for maior que o nó raiz: { maior = nó direito }
- Se o maior for diferente do `i` da iteração que é a raiz faça `rotacionar();` e `construirHeap();`

Após isso ele vai iterar ordenando fazendo de fato o HeapSort executando `rotacionar()` e `construirHeap()` de modo que ele caso o filho seja maior, troque de lugar com o nó raiz, dessa forma fazendo a ordenação.
