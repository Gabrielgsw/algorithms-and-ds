#include <stdio.h>

void bubble_sort(int* v,int tam){
    for(int i = 0;i<tam;i++){
        int trocou = 1; // verificando se houve trocas, para caso o arranjo já esteja ordenado
        for(int j = 0;j<tam - i;j++){
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                trocou = 0;
            }
        }
       if(trocou){
           break;
       }
    }
   
}

int main()
{
   
   int v[]={4,87,1,3,88,33};
   
   bubble_sort(v,6);
    for(int i = 0;i<6;i++){
        printf("%d ",v[i]);
    }
   
}
