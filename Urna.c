/******************************************************************************

Desenvolvimento das listas responsáveis por armazenar os candidatos das eleições 
e executar operações algumas operações;

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define SIZENOME 100
#define SIZEPARTIDO 40

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

// Função para criar uma lista de candidatos vazia e a retornar. Retorna NULL se não for possível criá-la.
Lista* criarLista(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if(list == NULL){
        return NULL;
    }
    list->start = NULL;
    list->end = NULL;
    return list;
}

// Função para criar um novo candidato e retorná-lo. Retorna NULL se não for possível criá-lo.
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

// Função para verificar se o número de um candidato é igual ao de outro. Retorna 1 se forem iguais, retorna 0 do contrário.
int equalsCandidato(Candidato* cand1, Candidato* cand2){
    if(cand1->numero == cand2->numero){
        return 1;
    }
    return 0;
}

// Função para verificar se já existe um candidato com um determinado número na lista. Retorna 1 se existir, retorna 0 do contrário.
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

// Função que retorna um candidato que possui um determinado numero. Retorna NULL se não encontrá-lo.
Candidato* findCand(Lista* lista, int numero){
    if(lista == NULL || lista->start == NULL){
        return NULL;
    }
    Candidato* temp = lista->start;
    while(temp != NULL && temp->numero != numero){
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

// Remove um candidato de uma lista a partir do seu número
int removerNum(Lista* lista, int numero){
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
    free(cand);
    return 1;
}

// Função para editar um candidato já existente em uma lista, indentificado pelo seu número. Retorna -1 se o candidato não for encontrado,
// retorna 0 se já existir um candidato com o novo número, e retorna 1 se a edição for realizada com sucesso.
int editarCandidato(Lista* lista, int numero, char* newName, char* newPartido, int newNumero){
    Candidato* cand = findCand(lista, numero);
    if(cand == NULL){
        return -1;
    }
    cand->numero = -1;
    if(findCand(lista, newNumero) != NULL){
        return 0;
    }
    free(cand->nome);
    free(cand->partido);
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
        free(temp);
    }
    lista->end = NULL;
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

// Função para exibir todos os candidatos de uma lista. Retorna -1 para lista inválida, 0
int printLista(Lista* lista){
    if(lista == NULL){
        return -1;
    }
    Candidato* temp = lista->start;
    if(temp == NULL){
        return 0;
    }
    int i = 1;
    while(temp != NULL){
        printf("\nCandidato %i", i);
        printCandidato(temp);
        temp = temp->prox;
        i++;
    }
    return 1;
}

/*
As funções a seguir são para as operações realidadas no código main, e utilizam as funções anteriores para isso.
*/

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

// Função para adicionar candidato durante a execução do programa
void addCandMain(Lista* lista){
    Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));
    candidato->nome = (char*) malloc(SIZENOME + 1);
    candidato->partido = (char*) malloc(SIZEPARTIDO + 1);
    if(candidato == NULL || candidato->nome == NULL || candidato->partido == NULL){
        printf("Erro de alocação de memória.");
        return;
    }
    printf("\nInsira o nome do candidato: ");
    fgets(candidato->nome, SIZENOME + 1, stdin);
    removerN(candidato->nome);
    printf("Insira o partido do candidato: ");
    fgets(candidato->partido, SIZEPARTIDO + 1, stdin);
    removerN(candidato->partido);
    printf("Insira o número do candidato: ");
    scanf("%i", &candidato->numero);
    limparBuffer();
    addEnd(lista, candidato);
    printf("Candidato adicionado!\n");
    return;
}

// Função para remover candidato durante a execução do programa
void removeCandMain(Lista* lista){
    int num;
    printf("\nInsira o número do candidado para removê-lo (0 para cancelar): ");
    scanf("%i", &num);
    if(num == 0){
        return;
    }
    int test = removerNum(lista, num);
    if(test == -1){
        printf("Lista inválida!\n\n");
        return;
    }
    if(test == 0){
        printf("Candidato não encontrado!\n");
        return;
    }
    if(test == 1){
        printf("Candidato removido.\n");
        return;
    }
}

// Função para editar candidato durante a execução do programa
void editCandMain(Lista* lista){
    if(lista == NULL){
        printf("Lista inválida!");
        return;
    }
    int numero;
    char* newNome = (char*) malloc(SIZENOME + 1);
    char* newPartido = (char*) malloc(SIZEPARTIDO + 1);
    int newNumero;
    printf("\nInsira o número do candidato a ser editado: ");
    scanf("%i", &numero);
    limparBuffer();
    Candidato* cand = findCand(lista, numero);
    if(cand == NULL){
        printf("Candidato não encontrado.\n");
        return;
    }
    printf("Insira o novo nome: ");
    fgets(newNome, SIZENOME + 1, stdin);
    removerN(newNome);
    printf("Insira o novo partido: ");
    fgets(newPartido, SIZEPARTIDO + 1, stdin);
    removerN(newPartido);
    printf("Insira o novo número: ");
    scanf("%i", &newNumero);
    limparBuffer();
    int teste = editarCandidato(lista, numero, newNome, newPartido, newNumero);
    if(teste == 0){
        printf("Já existe um candidato com esse número!\n");
    }
    printf("Candidato editado com sucesso!\n");
    return;
}

// Função para exibir os candidatos na main
void exibirCandMain(Lista* lista){
    if(printLista(lista) == 0){
        printf("\nNenhum candidato registrado.\n");
    }
}

void sairConfirmacao(int* i){
    printf("\nDeseja sair ? (Os dados atuais não serão salvos)");
    printf("\n1 - Sim");
    printf("\n2 - Nao");
    printf("\nResposta: ");
    scanf("%i", i);
    limparBuffer();
    if(*i == 1){
        *i = 6;
        return;
    }
    if(*i == 2){
        *i = 0;
        return;
    }
    printf("Opção inválida!\n");
    *i = 0;
    return;
}

// Função para fazer a confirmação antes de iniciar as eleições. Retorna 1 se a confirmação for bem sucedida, 0 do contrário.
int iniciarConfirmar(){
    int i;
    char senha[20];
    printf("\nDeseja iniciar as eleições? (As edições serão desabilitadas)");
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
            printf("\nSenha incorreta! Tente novamente (0 para cancelar)");
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
    printf("\nOpção inválida!\n");
    return 0;;
}

// Função para mostrar as opções disponíveis no menu
void mostrarOpcoes(){
    printf("\n1 - Inserir candidato");
    printf("\n2 - Remover candidato");
    printf("\n3 - Ver candidatos");
    printf("\n4 - Editar candidato");
    printf("\n5 - Iniciar eleições");
    printf("\n6 - Sair");
    printf("\nInsira a opção desejada: ");
}

// Função para mostrar as opções disponíveis na eleição
void mostrarOpcoesEleicoes(){
    printf("\n1 - Votar");
    printf("\n2 - Encerrar eleições");
    return;
}

//adm
int loginAdministrador(){
    char senha[20];
    printf("Digite a senha para acesso como administrador: ");
    scanf("%19s", senha);

    if(strcmp(senha, "admin123") == 0) {
        printf("login de administrador bem sucedido!\n");
        return 1;
    }
    return 0;
}

// Teste de métrica
double teste(Lista* lista, int n){
    if(lista == NULL){
        return 0;
    }
    clock_t inicio = clock();

    for(int i = 1; i <= n; i++){
        Candidato* cand = criarCandidato("teste", "teste", i);
        addEnd(lista, cand);
    }
    clock_t final = clock();
    double time = (double)(final - inicio) / CLOCKS_PER_SEC;
    return time;
}

int main(){
    printf("    ### SISTEMA ELEITORAL ###\n\n");
    Lista* lista = criarLista();

    int confirmar; // Variável para confirmar se as eleições vão iniciar ou não

    int i;
    int* iptr = &i;
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
                removeCandMain(lista);
                break;
            case 3:
                exibirCandMain(lista);
                break;
            case 4:
                editCandMain(lista);
                break;
            case 5:
                confirmar = iniciarConfirmar();
                break;
            case 6:
                sairConfirmacao(iptr);
                break;
            }
        } while(i != 6 && confirmar != 1);
        if(confirmar == 1){
            mostrarOpcoesEleicoes();
        }
    }else {
        printf("voce não tem permissão para acessar o sistema. \n");
    }
    
    /* Teste de métrica
    int nCandidatos = 20000;
    printf("Tempo de execução: %f s", teste(lista, nCandidatos));
    */
    return 0;
}