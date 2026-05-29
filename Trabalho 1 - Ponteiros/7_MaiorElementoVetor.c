#include <stdio.h>

int maior(int *v, int tamanho){
    int *ptr = v;
    int valorMaior = *ptr;

    for (int i = 0; i<tamanho; i++){
        if (*(ptr+i) > valorMaior){
            valorMaior = *(ptr+i);
        }
    }
    
    return valorMaior;
}

int main(){
    int v[5] = {4, 12, 7, 25, 30};

    printf("O maior valor do vetor e: %d\n", maior(v, 5));

    return 0;
    
}