/*
implementação para as funções usadas para executar o programa principal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "Execucao.h"
#include "Lista.h"
#include "Util.h"

// Função para adicionar candidato durante a execução do programa
void addCandMain(Lista* lista){
    char* nome = (char*) malloc(SIZENOME + 1);
    char* partido = (char*) malloc(SIZEPARTIDO + 1);
    char* numero = (char*) malloc(SIZENUMERO + 1);
    if(nome == NULL || partido == NULL || numero == NULL){
        printf("Erro de alocacao de memoria!! Contate um tecnico para resolver o problema");
        return;
    }
    printf("\nInsira o nome do candidato: ");
    fgets(nome, SIZENOME + 1, stdin);
    removerN(nome);
    printf("Insira o partido do candidato: ");
    fgets(partido, SIZEPARTIDO + 1, stdin);
    removerN(partido);
    printf("Insira o numero do candidato: ");
    fgets(numero, SIZENUMERO + 1, stdin);
    removerN(numero);
    if(isNumber(numero) == 0){
        puts("Numero invalido!");
        return;
    }
    if(findCand(lista, numero) != NULL){
        puts("Candidato ja existente!");
        free(nome);
        free(partido);
        free(numero);
        return;
    }
    Candidato* candidato = criarCandidato(nome, partido, numero);
    addEnd(lista, candidato);
    puts("Candidato adicionado!");
    return;
}

// Função para remover candidato durante a execução do programa
void removeCandMain(Lista* lista){
    if(temCandidato(lista)){
        char* numero = (char*) malloc(SIZENUMERO + 1);
        printf("\nInsira o numero do candidado para remove-lo (0 para cancelar): ");
        fgets(numero, SIZENUMERO + 1, stdin);
        removerN(numero);
        if(strcmp(numero, "0") == 0){
            free(numero);
            return;
        }
        int test = removerNum(lista, numero);
        free(numero);
        if(test == -1){
            printf("Lista invalida!\n\n");
            return;
        }
        if(test == 0){
            printf("Candidato nao encontrado!\n");
            return;
        }
        if(test == 1){
            printf("Candidato removido.\n");
            return;
        }
    }
    else if(!(temCandidato(lista))){
         puts("\nNao ha candiatos registrados!\n");
    }
    return ;
}

// Função para editar candidato durante a execução do programa
void editCandMain(Lista* lista){
    if(temCandidato(lista)){
        if(lista == NULL){
            printf("Lista invalida!");
            return;
        }
        char* numero = (char*) malloc(SIZENUMERO + 1);
        if(numero == NULL){
            printf("Erro de alocacao de memoria!! Contate um tecnico para resolver o problema");
            return;
        }
        printf("\nInsira o numero do candidato a ser editado: ");
        fgets(numero, SIZENUMERO + 1, stdin);
        removerN(numero);
        if(isNumber(numero) == 0){
            printf("Numero invalido!\n");
            free(numero);
            return;
        }
        Candidato* cand = findCand(lista, numero);
        if(cand == NULL){
            printf("Candidato nao encontrado.\n");
            return;
        }
        char* newNome = (char*) malloc(SIZENOME + 1);
        char* newPartido = (char*) malloc(SIZEPARTIDO + 1);
        char* newNumero = (char*) malloc(SIZENUMERO + 1);
        if (newNome == NULL || newPartido == NULL || newNumero == NULL){
            printf("Erro de alocacao de memoria!! Contate um tecnico para resolver o problema");
            return;
        }
        
        printf("Insira o novo nome: ");
        fgets(newNome, SIZENOME + 1, stdin);
        removerN(newNome);
        printf("Insira o novo partido: ");
        fgets(newPartido, SIZEPARTIDO + 1, stdin);
        removerN(newPartido);
        printf("Insira o novo numero: ");
        fgets(newNumero, SIZENUMERO + 1, stdin);
        removerN(newNumero);
        if(isNumber(newNumero) == 0){
            printf("Numero invalido!\n");
            free(numero);
            free(newNome);
            free(newPartido);
            free(newNumero);
            return;
        }

        int teste = editarCandidato(lista, numero, newNome, newPartido, newNumero);
        free(numero);
        if(teste == 0){
            printf("Ja existe um candidato com esse numero!\n");
            return;
        }
        printf("Candidato editado com sucesso!\n");
        return;
    } 
    else if(!(temCandidato(lista))){
         puts("Nao ha candidatos cadastrados\n");
    }
    return ;
}

// Função para exibir os candidatos na main
void exibirCandMain(Lista* lista){
    if(printLista(lista, 0) == 0){
        printf("Nao ha candidatos cadastrados!\n");
    }
}

// Função para confirmar se o usuário realmente deseja sair do programa, para evitar missclick
void sairConfirmacao(int* i){
    char* resposta = (char*) malloc(SIZENUMERO + 1);
    printf("\nDeseja sair ? (Os dados atuais nao serao salvos)");
    printf("\n1 - Sim");
    printf("\n2 - Nao");
    printf("\nResposta: ");
    fgets(resposta, SIZENUMERO + 1, stdin);
    removerN(resposta);
    if(isNumber(resposta) == 1){
        *i = atoi(resposta);
        free(resposta);
        if(*i == 1){
            *i = 6;
            return;
        }
        if(*i == 2){
            *i = 0;
            return;
        }
    }
    free(resposta);
    printf("Opcao invalida!\n");
    *i = 0;
    return;
}

// Função para fazer a confirmação antes de iniciar as eleições. Retorna 1 se a confirmação for bem sucedida, 0 do contrário.
int iniciarConfirmar(Lista *lista){
    int i;
    char senha[20];
    if(temCandidato(lista)){

        printf("\nDeseja iniciar as eleicoes? (As edicoes serao desabilitadas)");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        printf("\nResposta: ");
        scanf("%i", &i);
        limparBuffer();
        if(i == 1){
            printf("\nDigite a senha de acesso do administrador (0 para cancelar): ");
            scanf("%19s", senha);
            limparBuffer();

            while(strcmp(senha, "admin123") != 0 && strcmp(senha, "0") != 0){
                printf("Senha incorreta! Tente novamente (0 para cancelar)");
                scanf("%19s", senha);
                limparBuffer();
            }

            if(strcmp(senha, "admin123") == 0){
                return 1;
            }

        return 0;
        }

        if(i == 2){
            return 0;
        }
        printf("\nOpcao invalida!\n");
    }
    else if(!(temCandidato(lista)))
        puts("Nao ha candidatos cadastrados");

    return 0;
}

// Função para realização das eleições. Recebe a lista dos candidatos, e o ponteiro para a variável que guardará o número de votos nulos
void executarEleicoes(Lista* lista, int* votosNulos){
    int j;
    char* charJ = (char*) malloc(SIZENUMERO + 1);
    int k;
    char* charK = (char*) malloc(SIZENUMERO + 1);
    char* numero = (char*) malloc(SIZENUMERO + 1);
    if(charJ == NULL || charK == NULL || numero == NULL){
        printf("Erro de alocacao de memoria!! Contate um tecnico para resolver o problema");
        return;
    }

    do{
        j = 0;
        k = 0;
        printf("\n1 - Votar");
        printf("\n2 - Encerrar eleicoes");
        printf("\nResposta: ");
        scanf("%s", charJ);
        limparBuffer();
        if(isNumber(charJ) == 1){
            j = atoi(charJ);
            if(j == 1){
                printf("\nInsira o numero do candidato: ");
                fgets(numero, SIZENUMERO + 1, stdin);
                removerN(numero);
                if(isNumber(numero) == 1){
                    Candidato* candidato = findCand(lista, numero);
                    if(candidato != NULL){
                        printCandidato(candidato, 0);
                        printf("\n1 - Confirmar \n2 - Cancelar \nResposta: ");
                        fgets(charK, SIZENUMERO + 1, stdin);
                        removerN(charK);
                        if(isNumber(charK) == 1){
                            k = atoi(charK);
                            if(k == 1){
                                candidato->votos = candidato->votos + 1;
                                printf("Voto registrado com sucesso! Pilililili\n");
                            }
                            if(k != 1 && k != 2){
                                printf("Opção invalida!\n");
                            }
                        }
                        else{
                            printf("Opção invalida!\n");
                        }
                    }
                    else{
                        printf("\nCandidato inexistente! Deseja votar nulo? ");
                        printf("\n1 - Confirmar \n2 - Cancelar \nResposta: ");
                        fgets(charK, SIZENUMERO + 1, stdin);
                        removerN(charK);
                        if(isNumber(charK) == 1){
                            k = atoi(charK);
                            if(k == 1){
                                *votosNulos = *votosNulos + 1;
                                printf("Voto registrado com sucesso! Pilililili\n");
                            }
                            if(k != 1 && k != 2){
                                printf("Opcao invalida!\n");
                            }
                        }
                        else{
                            printf("Opcao invalida!\n");
                        }
                    }
                }
                else{
                    printf("Opcao invalida!\n");
                }
            }
            else if(j == 2){
                char senha[20];
                printf("\nDeseja encerrar as eleicoes?");
                printf("\n1 - Sim \n2 - Nao \nResposta: ");
                fgets(charK, SIZENUMERO + 1, stdin);
                removerN(charK);
                if(isNumber(charK) == 1){
                    k = atoi(charK);
                    if(k == 1){
                        printf("\nDigite a senha de acesso do administrador (0 para cancelar): ");
                        scanf("%19s", senha);
                        limparBuffer();

                        while(strcmp(senha, "admin123") != 0 && strcmp(senha, "0") != 0){
                            printf("Senha incorreta! Tente novamente (0 para cancelar)");
                            scanf("%19s", senha);
                            limparBuffer();
                        }

                        if(strcmp(senha, "admin123") == 0){
                            j = 2;
                            return;
                        }
                        else{
                            j = 0;
                        }
                    }
                    else{
                        j = 0;
                    }
                }
                else{
                    printf("Opcao invalida!\n");
                    j = 0;
                }
            }
            else{
                printf("Opcao invalida!\n");
            }
        }
        else{
            printf("Opcao invalida!\n");
        }
    } while(j != 2);
}


// Função para fazer o login inicial do programa
int loginAdministrador(){
    char senha[20];
    printf("Digite a senha para acesso como administrador (0 para sair) (senha correta: admin123): ");
    scanf("%19s", senha);
    limparBuffer();
    while(strcmp(senha, "admin123") != 0 && strcmp(senha, "0") != 0){
        printf("Senha incorreta! Tente novamente (0 para sair): ");
        scanf("%19s", senha);
        limparBuffer();
    }
    if(strcmp(senha, "admin123") == 0) {
        printf("login de administrador bem sucedido!\n");
        return 1;
    }
    return 0;
}