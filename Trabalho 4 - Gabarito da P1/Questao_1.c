#include <stdio.h>

int main(){
    int vetor[10] = {0}; //(item A)
    int matriz[3][3] = {{0}}; //(item B)

    //preenchendo a diagonal principal com for (item B)
    for (int i = 0; i <3; i++){
        matriz[i][i] = 1;
    }

    printf("Vetor ");
    for (int i = 0; i < 10; i++){
        printf("| %d ", vetor[i]);
    }
    printf("|\n");

    printf("\nMatriz:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("| %d ", matriz[i][j]);
        }
        printf("|\n");
    }

    return 0;
}