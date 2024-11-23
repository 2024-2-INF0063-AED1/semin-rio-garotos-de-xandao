#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função responsávl por gereciar informações a cerca do canditado
typedef struct
{
  char nomeCanditado[100];
  int numCanditado;
  int numVotos;
} Canditado;

// Função responsável por fazer um cadastrio de um candidato 
void cadastrarCanditados(Canditado Canditado[], int n)
{

  for (int i = 0; i < n; i++)
  {
    printf("\n Cadastre o Canditado %d:\n ", i + 1);
    printf("Nome do Candditado: ");
    scanf("%c");
    fgets(Canditado[i].nomeCanditado, 100, stdin);
    candidatos[i].nomeCanditado[strcspn(candidatos[i].nome, "\n")] = 0;
    printf("Numero do Candidato: ");
    scanf("%d", &candidatos[i].numeroCandito);
    candidatos[i].numVotos = 0;
  }
}
