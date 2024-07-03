#include <stdio.h>

int linearSearch(int v[],int tam, int n){
    for(int i = 0;i<tam;i++){
        if(v[i] == n){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int x[2];
    x[0] = 3;
    x[1] = 4;
    
    printf("%d",linearSearch(x,2,30));
    
}