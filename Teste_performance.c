#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para definir candidatos
typedef struct Candidato {
    char* nome;
    char* partido;
    int numero;
    int votos;
    struct Candidato* prox;
} Candidato;

// Estrutura para a lista de candidatos
typedef struct Lista {
    Candidato* start;
    Candidato* end;
} Lista;

// Função para criar lista vazia
Lista* criarLista() {
    Lista* list = (Lista*) malloc(sizeof(Lista));
    list->start = list->end = NULL;
    return list;
}

// Função para criar novo candidato
Candidato* criarCandidato(char* nome, char* partido, int numero) {
    Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));
    candidato->nome = strdup(nome);
    candidato->partido = strdup(partido);
    candidato->numero = numero;
    candidato->prox = NULL;
    candidato->votos = 0;
    return candidato;
}

// Função para adicionar no fim
void addEnd(Lista* lista, Candidato* candidato) {
    if (lista->end == NULL) {
        lista->start = lista->end = candidato;
    } else {
        lista->end->prox = candidato;
        lista->end = candidato;
    }
}

// Função para buscar candidato por número
Candidato* buscarNumero(Lista* lista, int numero) {
    Candidato* temp = lista->start;
    while (temp != NULL) {
        if (temp->numero == numero) return temp;
        temp = temp->prox;
    }
    return NULL;
}

// Função para medir tempo de execução de inserção
double medirTempoInsercao(Lista* lista, int n) {
    clock_t inicio = clock();
    for (int i = 0; i < n; i++) {
        char nome[20], partido[20];
        sprintf(nome, "Candidato%d", i);
        sprintf(partido, "Partido%d", i);
        addEnd(lista, criarCandidato(nome, partido, i));
    }
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// Função para medir tempo de busca
double medirTempoBusca(Lista* lista, int numero) {
    clock_t inicio = clock();
    buscarNumero(lista, numero);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

int main() {
    Lista* lista = criarLista();
    
    // Medindo o tempo de inserção
    int n = 1000;  // Inserindo 1000 candidatos
    double tempoInsercao = medirTempoInsercao(lista, n);
    printf("Tempo de inserção de %d candidatos: %.6f segundos\n", n, tempoInsercao);
    
    // Medindo o tempo de busca
    int numeroBusca = 500;
    double tempoBusca = medirTempoBusca(lista, numeroBusca);
    printf("Tempo de busca para o candidato %d: %.6f segundos\n", numeroBusca, tempoBusca);
    
    return 0;
}
