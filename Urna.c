/******************************************************************************

Desenvolvimento das listas responsáveis por armazenar os candidatos das eleições 
e executar operações algumas operações;

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "Util.h"
#include "Lista.h"
#include "Execucao.h"

// Teste de métrica, retorna o tempo necessário para inserir n candidatos
double teste(Lista* lista, int n){
    if(lista == NULL){
        return 0;
    }
    char charN[20];

    clock_t inicio = clock();

    for(int i = 1; i <= n; i++){
        sprintf(charN, "%i", i);
        Candidato* cand = criarCandidato("teste", "teste", charN);
        addEnd(lista, cand);
    }
    clock_t final = clock();
    double time = (double)(final - inicio) / CLOCKS_PER_SEC;
    return time;
}


int main(){

    printf("\t\t### SISTEMA ELEITORAL ###\n\n");
    Lista* lista = criarLista();

    int confirmar; // Variável para confirmar se as eleições vão iniciar ou não
    int votosNulos = 0; // Variável para guardar a quantidade de votos nulos
    int* votosNulosPtr = &votosNulos; // Ponteiro para a variável dos votos nulos

    int i; // Variável para administrar a seleção de opções da etapa de registro de candidatos
    int* iptr = &i; // Ponteiro para a variável de auxílio da etapa de registro
    char* ichar = (char*) malloc(SIZENUMERO + 1); // char referente à variavel de auxílio "i", para fazer validação

    int ehAdministrador = loginAdministrador();
    if(ehAdministrador){
        do{
            i = 0;
            printf("\n1 - Inserir candidato");
            printf("\n2 - Remover candidato");
            printf("\n3 - Ver candidatos");
            printf("\n4 - Editar candidato");
            printf("\n5 - Iniciar eleições");
            printf("\n6 - Sair");
            printf("\nInsira a opção desejada: ");
            fgets(ichar, SIZENUMERO + 1, stdin);
            removerN(ichar);
            i = atoi(ichar);
            if(isNumber(ichar) == 1 && i >= 1 && i <= 6){
                switch(i){
                case 1: // Inserir candidato
                    addCandMain(lista);
                    break;
                case 2: // Remover candidato
                    removeCandMain(lista);
                    break;
                case 3: // Exibir candidatos
                    exibirCandMain(lista);
                    break;
                case 4: // Editar candidato
                    editCandMain(lista);
                    break;
                case 5: // Iniciar eleições
                    confirmar = iniciarConfirmar(lista);
                    break;
                case 6: // Sair do programa
                    sairConfirmacao(iptr);
                    break;
                }
            }
            else{
                printf("Opcao invalida\n");
            }
        } while(i != 6 && confirmar != 1);
        if(confirmar == 1){
            executarEleicoes(lista, votosNulosPtr);

            printf("        \n### Resultados ###\n\n");
            printLista(lista, 1);
            printf("\nVotos nulos: %i", votosNulos);
        }
    }else {
        limparLista(lista);
        free(ichar);
        printf("Você saiu do sistema. Vote sempre! \n");
    }
    
    

    /*
    //Teste de métrica. Para realizá-lo, basta descomentá-lo e comentar todo o código anterior
    Lista* lista = criarLista();
    int nCandidatos = 50000;
    printf("Tempo de execução: %f segundos", teste(lista, nCandidatos));
    */

    return 0;
}
