#include "tarefas.h"
#include <stdio.h>  //inclui biblioteca stdio
#include <string.h> //inclei biblioteca de caracteres

int main() {
  funcao fs[] = {adicionar, deletar, listar, carregar, salvar};

  Contato tarefas[TOTAL];
  int pos;

  ERROS erro = fs[3](tarefas, &pos);
  if (erro != OK) {
    printf("teste");
    pos = 0;
  }

  int opcao;
  do {
    printf("\nMenu principal\n");
    printf("1 - Adiconar contato\n");
    printf("2 - Deletar contato\n");
    printf("3 - Listar contato\n");
    printf("0 - Salvar e Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    opcao--;
    if (opcao > 2) {
      printf("Opcao invalida\n");
    } else if (opcao >= 0) {
      ERROS resultado = fs[opcao](tarefas, &pos);
      if (resultado != OK) {
        printf("Erro: %d\n", resultado);
      }
    } else {
      printf("Sair...\n");
      // erro = fs[4](tarefas, &pos);
      // if (erro != OK) {
      //   printf("Erro ao salvar os contatos: %d\n", erro);
      // }
    }
  } while (opcao >= 0);

  erro = fs[4](tarefas, &pos);
  if (erro != OK)
    printf("Erro ao salvar as tarefas: %d\n", erro);

  return 0;
}