#include <stdio.h>
#include <stdlib.h>


static int qtdTrocas;
static int qtdMaxHeapfy;

typedef struct {
    int chave;
} NoHeap;

typedef struct {
    int quantidade;
    NoHeap *heap;
} Heap;

void imprimirHeap(Heap *heap,int tam){
  for(int i = 0;i<tam;i++){
    printf("%d ",heap->heap[i].chave);
  }
  printf("\n");
}

int retornarIndicePai(int i) {
    return (int)((i - 1) / 2);
}

int retornarIndiceFilhoEsquerda(int i) {
    return 2 * i + 1;
}

int retornarIndiceFilhoDireita(int i) {
    return 2 * i + 2;
}

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
    qtdTrocas++;
}

void maxHeapfy(Heap *h, int i, int qtd) {
    qtdMaxHeapfy++;
    int maior;
    int l = retornarIndiceFilhoEsquerda(i);
    int r = retornarIndiceFilhoDireita(i);
    if ((l < qtd) && (h->heap[l].chave > h->heap[i].chave)) {
        maior = l;
    } else {
        maior = i;
    }
    if ((r < qtd) && (h->heap[r].chave > h->heap[maior].chave)) {
        maior = r;
    }
    if (maior != i) {
        trocar(&h->heap[i].chave, &h->heap[maior].chave);
        maxHeapfy(h, maior, qtd);
    }
  printf("Imprimindo durante maxHeapfy: ");
  imprimirHeap(h, 5);
}

void construirMaxHeap(Heap *h, int qtd) {
    for (int i = qtd / 2 - 1; i >= 0; i--) {
        maxHeapfy(h, i, qtd);
    }
    printf("Imprimindo durante construirMaxHeap: ");
    imprimirHeap(h, 5);
}

void heapsort(Heap *h, int qtd) {
    h->quantidade = qtd;
    construirMaxHeap(h, h->quantidade);
    for (int i = qtd - 1; i >= 1; i--) {
        trocar(&h->heap[0].chave, &h->heap[i].chave);
        h->quantidade--;
        maxHeapfy(h, 0, h->quantidade);
    }
}

int main(void) {
    Heap *h = malloc(sizeof(Heap));
    h->heap = malloc(sizeof(NoHeap) * 5);
    h->heap[0].chave = 1;
    h->heap[1].chave = 7;
    h->heap[2].chave = 88;
    h->heap[3].chave = 5;
    h->heap[4].chave = 23;

    //imprimindo vetor original
    printf("Vetor antes do heapsort: ");
    imprimirHeap(h, 5);
    heapsort(h, 5);

 

    printf("Quantidade de trocas: %d\n", qtdTrocas);
    printf("Quantidade de maxHeapfy: %d\n", qtdMaxHeapfy);
    printf("Vetor após o heapsort: ");
    imprimirHeap(h, 5);
    free(h->heap);
    free(h);

    return 0;
}
