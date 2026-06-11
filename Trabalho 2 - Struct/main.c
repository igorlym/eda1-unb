#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cadastro {
    char cnpj[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;

//cad unificado 
typedef struct CadastroUni {
    char cnpj[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo;
} TCadastroUni;

//Industria - simplesmente ecadeada
typedef struct NoI {
    TCadastro *dados;
    struct NoI *prox;
} TNOI;

//Comercio - duplamente encadeada sem descritor
typedef struct NoC {
    TCadastro *dados;
    struct NoC *Ant;
    struct NoC *prox;
} TNOC;

//Servicos - duplamente encadeada com descritor
typedef struct NoS {
    TCadastro *dados;
    struct NoS *Ant;
    struct NoS *prox;
} TNOS;

typedef struct DescritorS {
    TNOS *Inicio;
    int Tamanho;
    TNOS *Fim;
} TDescritorS;

typedef struct NoUni {
    TCadastroUni *Dados;
    struct NoUni *Ant;
    struct NoUni *Prox;
} TNoU; 

typedef struct DescritorUni {
    TNoU *Inicio;
    int Tamanho;
    TNoU *Fim;
} TDescritorUni;

//=========================================

TCadastro *lerCadastro(FILE *arq) {
    TCadastro *c = (TCadastro *)malloc(sizeof(TCadastro));
    if (!c) { fprintf(stderr, "Erro ao alocar cadastro.\n"); exit(1); }
    if (fscanf(arq, " %14s %49s %29s %11s",
               c->cnpj, c->RazaoSocial, c->Cidade, c->Fone) == 4) {
        return c;
    }
    free(c);
    return NULL;
}

int carregarArquivos() {
    FILE *arq;
    TCadastro *dados;
    int total = 0;
 
    /* Industria */
    arq = fopen("Industria.txt", "r");
    if (!arq) {
        printf("[AVISO] Arquivo Industria.txt nao encontrado.\n");
    } else {
        while ((dados = lerCadastro(arq)) != NULL) {
            inserirIndustria(dados);
            total++;
        }
        fclose(arq);
        printf("[OK] Industria.txt carregado.\n");
    }
 
    /* Comercio */
    arq = fopen("Comercio.txt", "r");
    if (!arq) {
        printf("[AVISO] Arquivo Comercio.txt nao encontrado.\n");
    } else {
        while ((dados = lerCadastro(arq)) != NULL) {
            inserirComercio(dados);
            total++;
        }
        fclose(arq);
        printf("[OK] Comercio.txt carregado.\n");
    }
 
    /* Servico */
    arq = fopen("Servico.txt", "r");
    if (!arq) {
        printf("[AVISO] Arquivo Servico.txt nao encontrado.\n");
    } else {
        while ((dados = lerCadastro(arq)) != NULL) {
            inserirServicos(dados);
            total++;
        }
        fclose(arq);
        printf("[OK] Servico.txt carregado.\n");
    }
 
    printf("Total de registros carregados: %d\n", total);
    return total;
}

//================================================

void exibirMenu() {
    printf("\n========================================\n");
    printf("  SECRETARIA DA FAZENDA - DF\n");
    printf("  Sistema de Cadastro de Contribuintes\n");
    printf("========================================\n");
    printf(" 1. Carregar Dados de Entrada\n");
    printf(" 2. Gerar Lista Unificada\n");
    printf(" 3. Relatorio: Industrias\n");
    printf(" 4. Relatorio: Comercio\n");
    printf(" 5. Relatorio: Comercio Invertida\n");
    printf(" 6. Relatorio: Servicos\n");
    printf(" 7. Relatorio: Servicos Invertida\n");
    printf(" 8. Relatorio: Lista Unificada\n");
    printf(" 9. Relatorio: Lista Unificada Invertida\n");
    printf("10. Apagar Listas\n");
    printf(" 0. Sair\n");
    printf("========================================\n");
    printf("Opcao: ");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//================================================

int main() {
    // Inicializar lists antigas
    TNOI *listaIndustria = NULL;
    TNOC *listaComercio = NULL;
    
    TDescritorS *listaServicos = (TDescritorS*) malloc(sizeof(TDescritorS));
    listaServicos->Inicio = NULL;
    listaServicos->Fim = NULL;
    listaServicos->Tamanho = 0;

    TDescritorUni *listaUnificada = (TDescritorUni*) malloc(sizeof(TDescritorUni));
    listaUnificada->Inicio = NULL;
    listaUnificada->Fim = NULL;
    listaUnificada->Tamanho = 0;

    int opcao;
    
    //Criar o loop do menu!!!!
    //usar  doWhile e switch?

    return 0;
}