#include <stdio.h>

int conta(char *str, char c){
    int conta = 0;
    
    while(*str != '\0')
    {
        if(*str == c)
        {
            conta++;
        }

        str++;
    }
    return conta;
}

int main(){
    char nome[] = "programacao";
    char desejado = 'a';

    printf("Quantas vezes o caracter '%c' aparece na palavra '%s': %d", desejado, nome, conta(nome, desejado));

    return 0;
}