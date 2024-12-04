/*
Arquivo de cabeçalho para as funções responsáveis por gerir a lista e os candidatos
*/

#ifndef LISTA_H
#define LISTA_H

// Estrtura responsável por definir os candidatos que serão armazenados na lista de candidatos
typedef struct Candidato {
    char* nome;
    char* partido;
    char* numero;
    int votos;
    struct Candidato* prox;
} Candidato;

// Estrutura responsável por definir a lista que armazenará os candidatos
typedef struct Lista{
    Candidato* start;
    Candidato* end;
} Lista;

// Função para criar uma lista de candidatos vazia e a retornar. Retorna NULL se não for possível criá-la.
Lista* criarLista();

// Função para criar um candidato com os parametros dados e retorná-lo. Retorna NULL se não for possível criá-la.
Candidato* criarCandidato(char* nome, char* partido, char* numero);

// Função para verificar se o número de um candidato é igual ao de outro. Retorna 1 se forem iguais, retorna 0 do contrário.
int equalsCandidato(Candidato* cand1, Candidato* cand2);

// Função para vericiar se uma função tem candidatos; retorna 1 se sim, e 0 do contrário
int temCandidato(Lista *lista);

// Função para verificar se já existe um candidato com um determinado número na lista. Retorna 1 se existir, retorna 0 do contrário.
int equalsCandList(Lista* lista, Candidato* cand);

// Função para adicionar um candidato ao início de uma lista
void addStart(Lista* lista, Candidato* candidato);

// Função para adicionar um candidato ao final de uma lista
void addEnd(Lista* lista, Candidato* candidato);

// Função que retorna um candidato que possui um determinado numero. Retorna NULL se não encontrá-lo.
Candidato* findCand(Lista* lista, char* numero);

// Função para remover um candidato do início da lista
void removeStart(Lista* lista);

//Função para remover um candidato do fim da lista
void removeEnd(Lista* lista);

// Remove um candidato de uma lista a partir do seu número
int removerNum(Lista* lista, char* numero);

// Função para editar um candidato já existente em uma lista, indentificado pelo seu número. Retorna -1 se o candidato não for encontrado,
// retorna 0 se já existir um candidato com o novo número, e retorna 1 se a edição for realizada com sucesso.
int editarCandidato(Lista* lista, char* numero, char* newName, char* newPartido, char* newNumero);

// Função para limpar uma lista completamente
void limparLista(Lista* lista);

// Função para exibir um candidato. Se "imprimirVotos" = 1, os votos serão imprimidos. Do contrário, não serão.
void printCandidato(Candidato* candidato, int imprimirVotos);

// Função para exibir todos os candidatos de uma lista. Retorna -1 para lista inválida, 0 para lista vazia e 1 do contrário.
// Se "imprimirVotos" = 1, os votos serão imprimidos. Do contrário, não serão.
int printLista(Lista* lista, int imprimirVotos);

// Recebe uma lista de candidatos e a coloca em ordem decrescente
void orderDecrescente(Lista* lista);

#endif
