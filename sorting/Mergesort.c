#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
//definindo tipo
typedef struct {
  int chave;
} NoList;


typedef struct {
  int m;  
  NoList *lista;
} Lista;

void imprimirVetor(Lista *l, int tam){
  for(int i = 0;i<tam;i++){
    printf("%d ", l->lista[i].chave);
  }
}

void merge(Lista *l, int inicio, int meio, int fim){
  int i,j,k;
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;
  //ListaSeq *l1,*l2;
  int l1[n1+1];
  int l2[n2+1];

  for (i = 0; i < n1; i++){
    l1[i] = l->lista[inicio + i].chave;
  }
  for (j = 0; j < n2; j++){
    l2[j] = l->lista[meio + 1  + j].chave;
  }
  l1[n1] = INT_MAX;
  l2[n2] = INT_MAX;

  i = 0;
  j = 0;
  for(k = inicio ;k<=fim;k++){
    if(l1[i] < l2[j]){
      l->lista[k].chave = l1[i];
      i++;
    }else{
      l->lista[k].chave = l2[j];
      j++;
    }
    
  }

  
}

void mergesort(Lista *l,int inicio,int fim){
  if(inicio < fim){
    int meio = inicio + (fim-inicio)/2;
    mergesort(l,inicio,meio);
    mergesort(l,meio+1,fim);
    merge(l,inicio,meio,fim);
  }
}

int main(void) {
 // printf("oi\n");
  Lista *lista = malloc(sizeof(Lista));
  
  int tam = 6;
  
  lista->lista = malloc(sizeof(NoList)*tam);
   
  
  lista->lista[0].chave = 3;
 
  lista->lista[1].chave = 33;
  lista->lista[2].chave = 13;
  lista->lista[3].chave = 2;
  lista->lista[4].chave = 22;
  lista->lista[5].chave = 1;
  mergesort(lista, 0, tam-1);
  imprimirVetor(lista,tam);
  
    free(lista->lista);
    free(lista);
  
  return 0;
}