#include <stdio.h>
#include <stdlib.h>

static int qtdTrocas;


typedef struct{
    int chave;
}NoQuick;

typedef struct{
    int M;
    NoQuick *dados;    
}VetorQuick;

void imprimirVetor(VetorQuick *v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", v->dados[i].chave);
    }
    printf("\n");
}


void trocar(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
    qtdTrocas++;
}

int particionar(VetorQuick *v, int p, int r) {
 
    int pivo = v->dados[r].chave;
    int i = p - 1;
   
    

  
    for (int j = p; j <= r - 1; j++) {
        if (v->dados[j].chave < pivo) {
            i++;
            trocar(&v->dados[i].chave, &v->dados[j].chave);
            
        }
    }

    trocar(&v->dados[i+1].chave,&v->dados[r].chave);
    printf("Vetor durante particionar: ");
    imprimirVetor(v,r+1);
    return i + 1;
}


void quicksort(VetorQuick *v, int p, int r) {

    if (p < r) {

      
        int q = particionar(v, p, r);        
        quicksort(v, p, q-1);
        quicksort(v, q + 1, r);
    }
}




int main() {
   
    int m = 5;
    VetorQuick *v = malloc(sizeof(VetorQuick));
    v->dados = malloc(sizeof(NoQuick)*m);
    v->dados[0].chave = 3;
    v->dados[1].chave = 9;
    v->dados[2].chave =1;
    v->dados[3].chave =11;
    v->dados[4].chave =112;
    printf("Vetor original: ");
    imprimirVetor(v, m);
    quicksort(v, 0, m-1);

    printf("Trocas: %d\n", qtdTrocas);
    
    printf("Vetor após quicksort: ");
    imprimirVetor(v, 5);
    return 0;
}
