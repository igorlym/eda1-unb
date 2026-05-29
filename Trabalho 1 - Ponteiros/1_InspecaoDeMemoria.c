#include <stdio.h>

int main (){
    int inteiro = 10;
    float flutuante = 10.50777;

    int *ptrint = &inteiro;
    float *ptrfloat = &flutuante;

    printf("Endereco de memoria inteiro: %p\n", ptrint);
    printf("Valor do inteiro: %d\n", *ptrint);
    printf("\nEndereco de memoria ponto flutuante: %p\n", ptrfloat);
    printf("Valor do ponto flutuante: %.2f\n", *ptrfloat);

    return 0;
}