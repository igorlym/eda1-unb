#include <stdio.h>

typedef struct{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main(){
    Produto p1 = {"Monster - mango loco", 10.99, 20};
    Produto *ptr = &p1; //(item A)

    //(item B)
    printf("Produto 1\n");
    printf("Nome: %s\n", ptr->nome);
    printf("Preco: %.2f\n", ptr->preco);
    printf("Quantidade em estoque: %d\n", ptr->quantidade);
    
    //(item C):
    //(*ptr).preco acessa primeiro o conteúdo apontado pelo ponteiro e depois o campo preco.
    //ptr->preco é apenas uma forma abreviada equivalente dessa mesma operação.
    
    return 0;
}