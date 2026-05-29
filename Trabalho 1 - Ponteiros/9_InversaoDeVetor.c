#include <stdio.h>

void inverte(int *v, int tamanho){
    int *inicio;
    int *fim;

    for(inicio = v, fim = v + tamanho - 1; inicio < fim; inicio++, fim--){
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
    }
}

int main(){
     int v[] = {1, 2, 3, 4};

    inverte(v, 4);

    for(int i = 0; i < 4; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;    
}