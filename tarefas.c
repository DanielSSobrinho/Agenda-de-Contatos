#include "tarefas.h"
#include <stdio.h>
#include <string.h>

int i;
int j;

ERROS adicionar(Contato tarefas[], int *pos) {
  if (*pos >= MAX_CONTATOS) {
    return MAX_CONTATOS;
  }
  int i;
  int num_contatos = 0;
  char resposta;
  do {
    printf("Adicionar contato %d\n", *pos + 1);
    clearBuffer();
    printf("Nome: ");
    fgets(tarefas[*pos].nome, 50, stdin);
    printf("Sobrenome: ");
    fgets(tarefas[*pos].sobrenome, 50, stdin);
    printf("Telefone: ");
    fgets(tarefas[*pos].telefone, 15, stdin);
    printf("E-mail: ");
    fgets(tarefas[*pos].email, 50, stdin);

    (*pos)++;

    // Verificar se deseja adicionar mais contatos
    if (*pos < MAX_CONTATOS) {
      printf("Deseja adicionar mais contatos? (s/n): ");
      scanf(" %c", &resposta);
    } else {
      printf("Numero maximo de contatos atingido.\n");
      break;
    }
  } while (resposta == 's' || resposta == 'S');

  // Mostrar os contatos adicionados
  printf("\nLista de contatos:\n");
  for (i = 0; i < num_contatos; i++) {
    printf("Nome: %s, Telefone: %s\n", tarefas[i].nome, tarefas[i].telefone);
  }

  return OK;
}

ERROS listar(Contato tarefas[], int *pos) {

  if (*pos == 0) {
    return SEM_CONTATOS;
  }
  // mostra os contatos
  printf("\nLista de contatos:\n");
  for (i = 0; i < *pos; i++) {
    printf("Nome: %s, Sobrenome: %s, Telefone: %s, E-mail: %s\n",
           tarefas[i].nome, tarefas[i].sobrenome, tarefas[i].telefone,
           tarefas[i].email);
  }

  return OK;
}
