#include <stdio.h>

int main(){
    int A = 10;
    int B = 20;
    int *ptr1, *ptr2;

    ptr1 = &A;
    ptr2 = &B;

    printf("Valor de A: %d\n", *ptr1);
    printf("Valor de B: %d\n", *ptr2);

    ptr1 = &B;
    ptr2 = &A;

    printf("Valor de A: %d\n", *ptr2);
    printf("Valor de B: %d\n", *ptr1);

    return 0;
}
