#include "tarefas.h"
#include <stdio.h>  //inclui biblioteca stdio
#include <string.h> //inclui biblioteca de caracteres

int main() {
  funcao fs[] = {
      adicionar, adicionar_corporativo, deletar, listar, alterar, carregar,
      salvar};

  int lista;
  printf(
      "\nVocê deseja modificar sua lista pessoal (1) ou corporativa (2) ?\n");
  scanf("%d", &lista);

  Contato tarefas[TOTAL];
  Contato tarefas_corporativa[TOTAL];
  int pos;

  ERROS erro = fs[5](tarefas, &pos);
  if (erro != OK) {
    printf("teste");
    pos = 0;
  }

  int opcao;
  do {
    printf("\nMenu principal\n");
    printf("1 - Adicionar contato pessoal\n");
    printf("2 - Adicionar contato corporativo\n");
    printf("3 - Deletar contato\n");
    printf("4 - Listar contato\n");
    printf("5 - Alterar contato\n");
    printf("0 - Salvar e Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    opcao--;
    if (opcao > 3) {
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

  erro = fs[6](tarefas, &pos);
  if (erro != OK)
    printf("Erro ao salvar as tarefas: %d\n", erro);

  return 0;
}