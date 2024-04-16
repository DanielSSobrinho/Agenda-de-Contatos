#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 255
#define TAM_NOME 30
#define TAM_TELEFONE 11

struct Contato {
  char nome[TAM_NOME];
  char telefone[TAM_TELEFONE];
};

int main() {

  struct Contato contatos[MAX_CONTATOS];

  int num_contatos = 0;
  char resposta;
  do {
    printf("Adicionar contato %d\n", num_contatos + 1);
    printf("Nome: ");
    fgets("%s", contatos[num_contatos].nome);
    printf("Telefone: ");
    fgets("%s", contatos[num_contatos].telefone);

    num_contatos++;

    if (num_contatos < MAX_CONTATOS) {
      printf("Deseja adicionar mais contatos? ");
      fgets(" %c", &resposta);
    } else {
      printf("Número máximo de contatos atingido.\n");
      break;
    }
  } while (resposta == 'sim');

  return 0;
}

