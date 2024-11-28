/******************************************************************************

Desenvolvimento das listas responsáveis por armazenar os candidatos das eleições 
e executar operações algumas operações;

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrtura responsável por definir os candidatos que serão armazenados na lista de candidatos
typedef struct Candidato {
    char* nome;
    char* partido;
    int numero;
    int votos;
    struct Candidato* prox;
} Candidato;

// Estrutura responsável por definir a lista que armazenará os candidatos
typedef struct Lista{
    Candidato* start;
    Candidato* end;
} Lista;

// Função para criar uma lista de candidatos vazia
Lista* criarLista(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if(list == NULL){
        return NULL;
    }
    list->start = NULL;
    list->end = NULL;
    return list;
}

// Função para criar um novo candidato
Candidato* criarCandidato(char* nome, char* partido, int numero){
    Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));
    if(candidato == NULL){
        return NULL;
    }
    candidato->nome = (char*) malloc(strlen(nome) + 1);
    candidato->partido = (char*) malloc(strlen(partido) + 1);
    strcpy(candidato->nome, nome);
    strcpy(candidato->partido, partido);
    candidato->numero = numero;
    candidato->prox = NULL;
    return candidato;
}

// Função para verificar se o número de um candidato é igual ao de outro
int equalsCandidato(Candidato* cand1, Candidato* cand2){
    if(cand1->numero == cand2->numero){
        return 1;
    }
    return 0;
}

// Função para verificar se já existe um candidato com um determinado número na lista
int equalsCandList(Lista* lista, Candidato* cand){
    Candidato* temp = lista->start;
    while(temp != NULL && temp->numero != cand->numero){
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
        printf("\nLista inválida!");
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
        printf("\nCandidato já existe!");
        return;
    }
}

// Função para adicionar um candidato ao final de uma lista
void addEnd(Lista* lista, Candidato* candidato){
    if(lista == NULL){
        printf("\nLista inválida!");
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
        printf("\nCandidato já existe!\n");
    }
}

//Função para remover um candidato do início da lista
void removeStart(Lista* lista){
    if(lista == NULL || lista->start == NULL){
        return;
    }
    Candidato* temp = lista->start;
    if(lista->start == lista->end){
        free(lista->start);
        lista->start = NULL;
        lista->end = NULL;
    }
    else{
        lista->start = lista->start->prox;
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
        free(lista->start);
        lista->start = NULL;
        lista->end = NULL;
    }
    else{
        while(temp->prox != lista->end){
            temp = temp->prox;
        }
        free(lista->end);
        lista->end = temp;
        lista->end->prox = NULL;
    }
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
        free(temp);
    }
    lista->end = NULL;
}

// Função para buscar um candidato em uma lista pelo seu número
Candidato* buscarNumero(Lista* lista, int numero){
    if(lista == NULL || lista->start == NULL){
        printf("\nLista inválida.");
        return NULL;
    }
    Candidato* temp = lista->start;
    while(temp != NULL && temp->numero != numero){
        temp = temp->prox;
    }
    if(temp == NULL){
        printf("\nCandidato não encontrado.");
        return NULL;
    }
    return temp; 
}

// Função para exibir um candidato
void printCandidato(Candidato* candidato){
    if(candidato == NULL){
        printf("\nCandidato inválido!");
        return;
    }
    printf("\nNome: %s\n", candidato->nome);
    printf("Partido: %s\n", candidato->partido);
    printf("Número: %i\n", candidato->numero);
}

// Função para exibir todos os candidatos de uma lista
void printLista(Lista* lista){
    if(lista == NULL){
        printf("\nLista inválida!");
        return;
    }
    Candidato* temp = lista->start;
    int i = 1;
    while(temp != NULL){
        printf("\nCandidato %i", i);
        printCandidato(temp);
        temp = temp->prox;
        i++;
    }
}

// Função para limpar o buffer após scanf
void limparBuffer(){
    while(getchar() != '\n');
}

// Função para remover o caractere \n da string
void removerN(char* string){
    for(int i = 1; i <= string[i] != '\0'; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
            break;
        }
    }
}

// Função para adicionar candidato durante a execução do programa
void addCandMain(Lista* lista){
    Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));
    candidato->nome = (char*) malloc(101);
    candidato->partido = (char*) malloc(41);
    if(candidato == NULL || candidato->nome == NULL || candidato->partido == NULL){
        printf("Erro de alocação de memória.");
        return;
    }
    printf("\nInsira o nome do candidato: ");
    fgets(candidato->nome, 101, stdin);
    removerN(candidato->nome);
    printf("Insira o partido do candidato: ");
    fgets(candidato->partido, 41, stdin);
    removerN(candidato->partido);
    printf("Insira o número do candidato: ");
    scanf("%i", &candidato->numero);
    limparBuffer();
    addEnd(lista, candidato);
}

// Função para mostrar as opções disponíveis na main
void mostrarOpcoes(){
    printf("\n1 - Inserir candidato\n");
    printf("2 - Remover candidato\n");
    printf("3 - Ver candidatos\n");
    printf("4 - Editar candidato\n");
    printf("5 - Sair\n");
    printf("Insira a opção desejada: ");
}

//adm
int loginAdministrador(){

    char senha[20];
    printf("Digite a senha para acesso comno administrador: ");
    scanf("%19s", senha);

    if(strcmp(senha, "admin123") == 0) {
        printf("login de administrador bem sucedido! gaRAIO\n");
        return 1;
    } else{
        printf("senha incorreta. Acesso como usuario normal. \n");
        return 0;
    }
}

int main(){
    printf("    ### SISTEMA ELEITORAL ###\n");
    Lista* lista = criarLista();
    int i;
    int ehAdministrador = loginAdministrador();
    if(ehAdministrador){
        do{
            mostrarOpcoes();
            scanf("%i", &i);
            limparBuffer();
            switch(i){
            case 1:
                addCandMain(lista);
                break;
            case 2:
                
            case 3:
                printLista(lista);
                break;
        }
    } while(i != 5);
    }else {
        printf("voce não tem permissão para adicionar candidatos. \n");
    }
    return 0;
}