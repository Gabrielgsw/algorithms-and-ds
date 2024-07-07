#include <stdio.h>

int binarySearch(int v[],int tam, int n){
    int first = 0;
    int last = tam - 1;
    while(last >= first){
        int mid = (int)((first + last)/2);
        if(v[mid] == n){
            return 1;
        }else{
            if(n < v[mid]){
                last = mid - 1;
            }else{
                first = mid + 1;
            }
        }
    }
    return 0;
}

int main()
{
    int v[4]={1,2,5,7};
    printf("%d",binarySearch(v,4,2));
}
