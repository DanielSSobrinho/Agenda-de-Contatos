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
  char email;

  do {
    printf("Adicionar contato %d\n", *pos + 1);
    clearBuffer();
    printf("Nome: ");
    fgets(tarefas[*pos].nome, 50, stdin);
    printf("Sobrenome: ");
    fgets(tarefas[*pos].sobrenome, 50, stdin);

    printf("Telefone: ");
    fgets(tarefas[*pos].telefone, 15, stdin);

    FILE *f;
    int localizado = 0;

    f = fopen("tarefas.bin", "rb");

    if (f == NULL) {
      perror("Erro ao abrir o arquivo");
      return 1;
    }

    Contato temp_contato;

    while (fread(&temp_contato, sizeof(Contato), 1, f)) {
      if (strcmp(temp_contato.telefone, tarefas[*pos].telefone) == 0) {
        localizado = 1;
        break;
      }
    }

    fclose(f);

    if (localizado) {
      printf("Telefone já existe.\n");
    }

    // Fecha o arquivo
    fclose(f);

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

ERROS deletar(Contato tarefas[], int *pos) {
  // teste se existem tarefas
  if (*pos == 0) {
    return SEM_CONTATOS;
  }
  char excluir[15];
  printf("\nDigite o numero de telefone do contato que deseja excluir: ");
  fgets(excluir, 15, stdin);

  int contatos_excluidos = 0;
  int pos_deletar = -1;
  int i, j;
  int t;

  for (i = 0; i < *pos; i++) {
    if (strcmp(excluir, tarefas[i].telefone) == 0) {
      // Move os contatos restantes uma posição para trás
      pos_deletar = i;
    }
  }
  for (j = pos_deletar; j < *pos; j++) {
    strcpy(tarefas[j].telefone, tarefas[j + 1].telefone);
    strcpy(tarefas[j].nome, tarefas[j + 1].nome);
    strcpy(tarefas[j].sobrenome, tarefas[j + 1].sobrenome);
    strcpy(tarefas[j].email, tarefas[j + 1].email);
  }
  contatos_excluidos++;
  *pos = *pos - 1;
  i--;

  // printf("%d", deletar);

  if (contatos_excluidos > 0) {
    printf("\nContato(s) excluido(s) com sucesso!\n");
  } else {
    printf("\nNenhum contato encontrado com o numero de telefone fornecido.\n");
  }

  // Mostrar os contatos restantes
  printf("\nLista de contatos atualizada:\n");
  for (i = 0; i < *pos; i++) {
    printf("Nome: %s, Telefone: %s\n", tarefas[i].nome, tarefas[i].telefone);
  }

  return 0;
}


ERROS carregar(Contato tarefas[], int *pos) {
  FILE *f = fopen("tarefas.bin", "rb");
  if (f == NULL) {
    return ABRIR;
  }
  int qtd = fread(tarefas, TOTAL, sizeof(Contato), f);
  if (qtd == 0) {
    return CARREGAR;
  }
  qtd = fread(pos, 1, sizeof(int), f);
  if (qtd == 0) {
    return CARREGAR;
  }
  if (fclose(f)) {
    return FECHAR;
  }
  return OK;
}


void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

ERROS salvar(Contato tarefas[], int *pos) {
  FILE *f = fopen("tarefas.bin", "wb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return ABRIR;
  }

  int qtd = fwrite(tarefas, TOTAL, sizeof(Contato), f);
  if (qtd == 0) {
    printf("Erro ao escrever");
    return ESCREVER;
  }
  qtd = fwrite(pos, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao escrever posição\n");
    return ESCREVER;
  }

  if (fclose(f)) {
    printf("Erro ao fechar \n");
    return FECHAR;
  }
  return OK;
}

