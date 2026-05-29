#include <stdio.h>

int main(){
    int v[5] = {10, 20, 30, 40, 50};
    int *ptr = v;
    int soma = 0;

    printf("Valores do vetor:\n");

    for (int i = 0; i < 5; i++){
        printf("Posicao %d: %d\n", (i+1), *(ptr + i));

        soma += *(ptr + i);
    }

    printf("\nSoma dos valores do vetor: %d\n", soma);

    return 0;
}