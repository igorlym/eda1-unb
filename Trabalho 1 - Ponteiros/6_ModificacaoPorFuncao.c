#include <stdio.h>

void dobra(int *x){
    *x *= 2;
}

int main(){
    int A = 2;
    int *ptr = &A;

    printf("Valor original: %d\n", *ptr);

    dobra(ptr);

    printf("Valor dobrado: %d\n", *ptr);

    return 0;
}