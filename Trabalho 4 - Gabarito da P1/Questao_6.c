#include <stdio.h>

int main()
{
    FILE *arquivo;
    char nome[50];
    float preco;

    arquivo = fopen("produtos.txt", "w");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(arquivo, "Arroz 25.90\n");
    fprintf(arquivo, "Monster 10.99\n");

    fclose(arquivo);

    // Reabre para leitura 
    arquivo = fopen("produtos.txt", "r");
    
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    while(fscanf(arquivo, "%s %f", nome, &preco) != EOF)
    {
        printf("Produto: %s | Preco: %.2f\n", nome, preco);
    }

    fclose(arquivo);

    return 0;
}