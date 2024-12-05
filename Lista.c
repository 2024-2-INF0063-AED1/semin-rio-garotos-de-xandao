/*
Arquivo de implementação para as funções responsáveis por gerir a lista e os candidatos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "Lista.h"

// Função para criar uma lista de candidatos vazia e a retornar. Retorna NULL se não for possível criá-la.
Lista* criarLista(){
    Lista* list = (Lista*) calloc(1, sizeof(Lista));
    if(list == NULL){
        return NULL;
    }
    list->start = NULL;
    list->end = NULL;
    return list;
}

// Função para criar um candidato com os parametros dados e retorná-lo. Retorna NULL se não for possível criá-la.
Candidato* criarCandidato(char* nome, char* partido, char* numero) {
    Candidato* candidato = (Candidato*) calloc(1, sizeof(Candidato));  
    if (candidato == NULL) {
        return NULL;
    }

    candidato->nome = (char*) calloc(strlen(nome) + 1, sizeof(char));
    candidato->partido = (char*) calloc(strlen(partido) + 1, sizeof(char));
    candidato->numero = (char*) calloc(strlen(numero) + 1, sizeof(char));

    if (candidato->nome == NULL || candidato->partido == NULL || candidato->numero == NULL) {
        return NULL;
    }

    strcpy(candidato->nome, nome);
    strcpy(candidato->partido, partido);
    strcpy(candidato->numero, numero);

    candidato->prox = NULL;
    candidato->votos = 0;

    return candidato;
}

// Função para verificar se o número de um candidato é igual ao de outro. Retorna 1 se forem iguais, retorna 0 do contrário.
int equalsCandidato(Candidato* cand1, Candidato* cand2){
    if(strcmp(cand1->numero, cand2->numero) == 0){
        return 1;
    }
    return 0;
}


// Função para vericiar se uma função tem candidatos; retorna 1 se sim, e 0 do contrário
int temCandidato(Lista *lista){
    if(lista -> start != NULL)
        return 1;
    
    return 0;

}
// Função para verificar se já existe um candidato com um determinado número na lista. Retorna 1 se existir, retorna 0 do contrário.
int equalsCandList(Lista* lista, Candidato* cand){
    Candidato* temp = lista->start;
    while(temp != NULL && strcmp(temp->numero, cand->numero) != 0){
        temp = temp->prox;
    }
    if(temp == NULL){
        return 0;
    }
    return 1;
}

// Função para adicionar um candidato ao início de uma lista
void addStart(Lista* lista, Candidato* candidato){
    if(lista == NULL){
        printf("\nLista invalida!");
        return;
    }
    if(lista->start == NULL){
        candidato->prox = NULL;
        lista->start = candidato;
        lista->end = candidato;
        return;
    }
    if(equalsCandList(lista, candidato) == 0){
        candidato->prox = lista->start;
        lista->start = candidato;
        return;
    }
    else{
        printf("\nCandidato ja existe!");
        return;
    }
    return;
}

// Função para adicionar um candidato ao final de uma lista
void addEnd(Lista* lista, Candidato* candidato){
    if(lista == NULL){
        printf("\nLista invalida!");
        return;
    }
    if(lista->end == NULL){
        candidato->prox = NULL;
        lista->start = candidato;
        lista->end = candidato;
        return;
    }
    if(equalsCandList(lista, candidato) == 0){
        candidato->prox = NULL;
        lista->end->prox = candidato;
        lista->end = candidato;
        return;
    }
    else{
        printf("\nCandidato ja existe!\n");
    }
}

// Função que retorna um candidato que possui um determinado numero. Retorna NULL se não encontrá-lo.
Candidato* findCand(Lista* lista, char* numero){
    if(lista == NULL || lista->start == NULL){
        return NULL;
    }
    Candidato* temp = lista->start;
    while(temp != NULL && strcmp(temp->numero, numero) != 0){
        temp = temp->prox;
    }
    if(temp == NULL){
        return NULL;
    }
    return temp;
}

// Função para remover um candidato do início da lista
void removeStart(Lista* lista){
    if(lista == NULL || lista->start == NULL){
        return;
    }
    Candidato* temp = lista->start;
    if(lista->start == lista->end){
        free(temp->nome);
        free(temp->partido);
        free(temp->numero);
        free(temp);
        lista->start = NULL;
        lista->end = NULL;
    }
    else{
        lista->start = temp->prox;
        free(temp->nome);
        free(temp->partido);
        free(temp->numero);
        free(temp);
    }
}

//Função para remover um candidato do fim da lista
void removeEnd(Lista* lista){
    if(lista == NULL || lista->start == NULL){
        return;
    }
    Candidato* temp = lista->start;
    if(lista->start == lista->end){
        free(temp->nome);
        free(temp->partido);
        free(temp->numero);
        free(temp);
        lista->start = NULL;
        lista->end = NULL;
    }
    else{
        while(temp->prox != lista->end){
            temp = temp->prox;
        }
        free(lista->end->nome);
        free(lista->end->partido);
        free(lista->end->numero);
        free(lista->end);
        lista->end = temp;
        lista->end->prox = NULL;
    }
}

// Remove um candidato de uma lista a partir do seu número
int removerNum(Lista* lista, char* numero){
    // Encontra o candidato e o salva em "temp". Salva "NULL" se não encontar o candidato
    if(lista == NULL){
        return -1;
    }
    Candidato* cand = findCand(lista, numero);
    if(cand == NULL){
        return 0;
    }
    // Remove o candidato encontrado
    if(cand == lista->start){
        removeStart(lista);
        return 1;
    }
    if(cand == lista->end){
        removeEnd(lista);
        return 1;
    }
    
    Candidato* anterior = lista->start;
    while(anterior->prox != cand){
        anterior = anterior->prox;
    }
    anterior->prox = cand->prox;
    free(cand->nome);
    free(cand->partido);
    free(cand->numero);
    free(cand);
    return 1;
}

// Função para editar um candidato já existente em uma lista, indentificado pelo seu número. Retorna -1 se o candidato não for encontrado,
// retorna 0 se já existir um candidato com o novo número, e retorna 1 se a edição for realizada com sucesso.
int editarCandidato(Lista* lista, char* numero, char* newName, char* newPartido, char* newNumero){
    Candidato* cand = findCand(lista, numero);
    if(cand == NULL){
        return -1;
    }
    char* temp = cand->numero;
    cand->numero[0] = '\0';
    if(findCand(lista, newNumero) != NULL){
        cand->numero = temp;
        return 0;
    }
    free(cand->nome);
    free(cand->partido);
    free(cand->numero);
    cand->nome = newName;
    cand->partido = newPartido;
    cand->numero = newNumero;
    return 1;
}

// Função para limpar uma lista completamente
void limparLista(Lista* lista){
    if(lista == NULL || lista->start == NULL){
        return;
    }
    Candidato* temp;
    while(lista->start != NULL){
        temp = lista->start;
        lista->start = temp->prox;
        free(temp->nome);
        free(temp->partido);
        free(temp->numero);
        free(temp);
    }
    lista->end = NULL;
}

// Função para exibir um candidato. Se "imprimirVotos" = 1, os votos serão imprimidos. Do contrário, não serão.
void printCandidato(Candidato* candidato, int imprimirVotos){
    if(candidato == NULL){
        printf("\nCandidato invalido!");
        return;
    }
    printf("\nNome: %s\n", candidato->nome);
    printf("Partido: %s\n", candidato->partido);
    printf("Numero: %s\n", candidato->numero);
    if(imprimirVotos == 1){
        printf("Votos: %i\n", candidato->votos);
    }
}

// Função para exibir todos os candidatos de uma lista. Retorna -1 para lista inválida, 0 para lista vazia e 1 do contrário.
// Se "imprimirVotos" = 1, os votos serão imprimidos. Do contrário, não serão.
int printLista(Lista* lista, int imprimirVotos){
    if(lista == NULL){
        return -1;
    }
    Candidato* temp = lista->start;
    if(temp == NULL){
        return 0;
    }
    int i = 1;
    while(temp != NULL){
        printCandidato(temp, imprimirVotos);
        temp = temp->prox;
        i++;
    }
    return 1;
}

// Recebe uma lista de candidatos e a coloca em ordem decrescente
void orderDecrescente(Lista* lista){
    if(lista == NULL || lista->start == NULL) return;

    Candidato* cand = lista->start;
    Candidato* maior;
    Candidato* temp;
    while(cand != NULL){
        maior = cand;
        temp = cand->prox;
        while(temp != NULL){
            if(temp->votos > maior->votos){
                maior = temp;
            }
            temp = temp->prox;
        }
        if(cand != maior){
            char* nome = cand->nome;
            char* partido = cand->partido;
            char* numero = cand->numero;
            int votos = cand->votos;

            cand->nome = maior->nome;
            cand->partido = maior->partido;
            cand->numero = maior->numero;
            cand->votos = maior->votos;

            maior->nome = nome;
            maior->partido = partido;
            maior->numero = numero;
            maior->votos = votos;
        }
        cand = cand->prox;
    }
}
