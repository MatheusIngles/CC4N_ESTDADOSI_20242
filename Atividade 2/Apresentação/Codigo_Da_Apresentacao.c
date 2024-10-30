#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellsort(int size, int *v){
    int i,j,h = 1, aux;
    
    for(;h < size; h = h * 3 + 1);
    
    do{
        h /= 3;
        
        for(i = h; i < size; i++){
            aux = v[i];
            j = i;
            while (j >= h && v[j -h]>aux){
                v[j] = v[j -h];
                j -= h;
            }
            v[j] = aux;
        }
    } while (h != 1);
    
}

int main()
{
    int size = 10;
    int v[] = {1,2,3,4,8,9,1,1,4,9};
    shellsort(size,v);
    

    return 0;
}