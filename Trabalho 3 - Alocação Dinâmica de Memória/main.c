#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

//tive que adicionar essa funcao pois quando o user digita um valor invalido, o sistema entra em um loop infinito
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inicializar(TTemperaturas *reg) {
    desalocar(reg);
 
    printf("Quantos dias serao registrados? ");
    if (scanf("%d", &reg->qtde_dias) != 1) {
        printf("Entrada invalida. Voltando ao Menu.\n");
        limparBuffer();
        reg->qtde_dias = 0;
        return;
    }
 
    if (reg->qtde_dias <= 0) {
        printf("Valor informado invalido.\n");
        reg->qtde_dias = 0;
        return;
    }
 
    reg->medidas = (TMedidas *) malloc(reg->qtde_dias * sizeof(TMedidas));
    if (reg->medidas == NULL) {
        printf("Falha na alocacao do vetor principal.\n");
        reg->qtde_dias = 0;
        return;
    }
 
    int k;
    for (k = 0; k < reg->qtde_dias; k++) {
        reg->medidas[k].temperatura = (float *) malloc(sizeof(float));
        if (reg->medidas[k].temperatura == NULL) {
            printf("Falha na alocacao da posicao %d.\n", k);
            int j;
            for (j = 0; j < k; j++)
                free(reg->medidas[j].temperatura);
            free(reg->medidas);
            reg->medidas = NULL;
            reg->qtde_dias = 0;
            return;
        }
        *reg->medidas[k].temperatura = 0.0f;
        reg->medidas[k].cidade[0] = '\0';
    }
 
    reg->qtde_medidas = 0;
    printf("Pronto! Capacidade configurada para %d registros.\n", reg->qtde_dias);
}
 
void novaEntrada(TTemperaturas *reg) {
    if (reg->medidas == NULL) {
        printf("Nenhuma capacidade alocada. Volte ao menu e escolha Reset.\n");
        return;
    }
    if (reg->qtde_medidas >= reg->qtde_dias) {
        printf("Limite de %d registros ja foi atingido.\n", reg->qtde_dias);
        return;
    }
 
    int pos = reg->qtde_medidas;
 
    printf("Cidade: ");
    scanf("%19s", reg->medidas[pos].cidade);
 
    printf("Temperatura (C): ");
    scanf("%f", reg->medidas[pos].temperatura);
 
    reg->qtde_medidas++;
    printf("Registro adicionado.\n");
}
 
void resumo(TTemperaturas *reg) {
    if (reg->medidas == NULL || reg->qtde_medidas == 0) {
        printf("\nSem dados para exibir.\n");
        return;
    }
 
    float acumulado = 0.0f;
    int menor = 0, maior = 0;
    int i;
 
    for (i = 0; i < reg->qtde_medidas; i++) {
        float t = *reg->medidas[i].temperatura;
        acumulado += t;
        if (t < *reg->medidas[menor].temperatura) menor = i;
        if (t > *reg->medidas[maior].temperatura) maior = i;
    }
 
    float media = acumulado / reg->qtde_medidas;
 
    printf("\n====== Relatorio (%d registros) ======\n", reg->qtde_medidas);
    printf("Media        : %.2f C\n", media);
    printf("Mais fria    : %s (%.2f C)\n",
           reg->medidas[menor].cidade, *reg->medidas[menor].temperatura);
    printf("Mais quente  : %s (%.2f C)\n",
           reg->medidas[maior].cidade, *reg->medidas[maior].temperatura);
    printf("======================================\n");
}
 
void desalocar(TTemperaturas *reg) {
    if (reg->medidas != NULL) {
        int i;
        for (i = 0; i < reg->qtde_dias; i++)
            free(reg->medidas[i].temperatura);
        free(reg->medidas);
        reg->medidas = NULL;
    }
    reg->qtde_dias    = 0;
    reg->qtde_medidas = 0;
}
 
int main(void) {
    TTemperaturas registro;
    registro.qtde_dias    = 0;
    registro.qtde_medidas = 0;
    registro.medidas      = NULL;
 
    int escolha;
 
    do {
        printf("\n-------- MENU --------\n");
        printf("1. Reset\n");
        printf("2. Inserir Medida\n");
        printf("3. Estatistica\n");
        printf("4. Sair\n");
        printf(">> ");
        if (scanf("%d", &escolha) != 1) {
            printf("\nEntrada invalida. Voltando ao menu.\n");
            limparBuffer();
            escolha = 0;
            continue;
        }
 
        switch (escolha) {
            case 1: inicializar(&registro);  break;
            case 2: novaEntrada(&registro);  break;
            case 3: resumo(&registro);       break;
            case 4:
                desalocar(&registro);
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpcao nao reconhecida.\n");
        }
    } while (escolha != 4);
 
    return 0;
}