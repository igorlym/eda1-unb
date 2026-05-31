#include <stdio.h>

//(item A)
int fatorial(int n){
    if (n == 1  || n == 0) return 1;
    return n * fatorial(n-1);
}

//(item B)
int soma_vetor(int v[], int tam){
    if (tam == 0) return 0;
    return v[tam-1] + soma_vetor(v, tam - 1);
}

int main(){
    int i = 0;
    int v[] = {1, 2, 3, 4};

    printf("Fatorial de %d: %d\n", i, fatorial(i));
    printf("Soma do vetor: %d\n", soma_vetor(v, 4));

    return 0;
}