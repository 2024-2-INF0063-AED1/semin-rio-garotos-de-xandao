/*
Cabeçalho para as funções usadas para executar o programa principal
*/

#ifndef EXECUCAO_H
#define EXECUCAO_H

#define SIZENOME 100
#define SIZEPARTIDO 40
#define SIZENUMERO 50

#include "Lista.h"

// Função para adicionar candidato durante a execução do programa
void addCandMain(Lista* lista);

// Função para remover candidato durante a execução do programa
void removeCandMain(Lista* lista);

// Função para editar candidato durante a execução do programa
void editCandMain(Lista* lista);

// Função para exibir os candidatos na main
void exibirCandMain(Lista* lista);

// Função para confirmar se o usuário realmente deseja sair do programa, para evitar missclick
void sairConfirmacao(int* i);

// Função para fazer a confirmação antes de iniciar as eleições. Retorna 1 se a confirmação for bem sucedida, 0 do contrário.
int iniciarConfirmar(Lista *lista);

// Função para realização das eleições. Recebe a lista dos candidatos, e o ponteiro para a variável que guardará o número de votos nulos
void executarEleicoes(Lista* lista, int* votosNulos);

// Função para fazer o login inicial do programa
int loginAdministrador();

#endif