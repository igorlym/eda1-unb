#include <stdio.h>

typedef struct{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main(){
    Produto p1 = {"Monster - mango loco", 10.99, 20};
    
    printf("Produto 1\n");
    printf("Nome: %s\n", p1.nome);
    printf("Preco: %.2f\n", p1.preco);
    printf("Quantidade em estoque: %d\n", p1.quantidade);
    
    return 0;
}