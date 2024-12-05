/*
Implementação para as funções que executam certas operações específicas que podem ser úteis para o código em geral
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "Util.h"

// Função para limpar o buffer após scanf
void limparBuffer(){
    while(getchar() != '\n');
}

// Função para remover o caractere \n da string
void removerN(char* string){
    for(int i = 1; string[i] != '\0'; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
            break;
        }
    }
}

// Função para verificar se uma string possui apenas números, retorna 1 se a repsosta for positiva, e do contrário retorna 0.
int isNumber(char* string){
    int i = 0;
    while(string[i] != '\0' && i != -1){
        if(isdigit(string[i]) == 0){
            i = -1;
            break;
        }
        i+=1;
    }
    if(i == -1){
        return 0;
    }
    return 1;
}
