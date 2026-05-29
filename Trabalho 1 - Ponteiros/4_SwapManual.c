#include <stdio.h>

//Sem funcao!!!

int main(){
    int A = 10;
    int B = 20;

    int *p1 = &A;
    int *p2 = &B;

    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;

    printf("A = %d\n", *p1);
    printf("B = %d\n", *p2);
    
    return 0;
}