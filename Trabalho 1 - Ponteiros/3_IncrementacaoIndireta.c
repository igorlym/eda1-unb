#include <stdio.h>

int main(){
    int A = 5;
    int *ptr = &A;

    printf("Valor original: %d\n", *ptr);

    *ptr += 5;
    *ptr *= 2;
    
    printf("Valor final: %d\n", *ptr);

    return 0;
}