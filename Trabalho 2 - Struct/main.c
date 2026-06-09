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