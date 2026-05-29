#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main(){
    int n;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    Produto *prod = (Produto *) malloc(n * sizeof(Produto));

    if (prod == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf("\n--- CADASTRO ---\nProduto %d\n", i+1);

        printf("Nome: ");
        scanf("%s", prod[i].nome);

        printf("Preco: ");
        scanf("%f", &prod[i].preco);

        printf("Quantidade: ");
        scanf("%d", &prod[i].quantidade);
    }

    printf("\n--- Produtos cadastrados ---\n");
    for (int i = 0; i < n; i++){
        printf("Produto %d: %s | R$ %.2f | Qtd: %d\n", i+1, prod[i].nome, prod[i].preco, prod[i].quantidade);
    }

    free(prod);
    prod = NULL;

    return 0;
}