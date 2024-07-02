#include <stdio.h>

void InsertionSort(int v[],int tam){
    for(int i = 1;i<tam;i++){
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j-=1;
        }
        v[j+1] = key;
    }
}

int main()
{
  
  int tam = 3;
  int v[tam];
  v[0] = 5;
  v[1] = 3;
  v[2] = 2;
  
  InsertionSort(v,tam);
  
  for(int i = 0;i<tam;i++){
      printf(" %d ",v[i]);
  }
  
  
}
