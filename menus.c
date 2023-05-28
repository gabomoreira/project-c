#include "menus.h"
#include <stdio.h>

int menu_principal() {
  int opcao = 0;
  do {
    printf("== Menu principal==\n\n");
    printf("1 - Menu aluno\n");
    printf("2 - Menu professor\n");
    printf("3 - Menu turma\n");
    printf("4 - Sair\n");
    printf("Opcao > ");
    scanf("%d", &opcao);
    getchar();
    if (opcao > 0 && opcao < 6) {
      return opcao;
    }
    printf("Opcao inválida!! Tente novamente\n\n");

  } while (1);
}

int menu_crud_aluno() {
  int opcao = 1;
  do {
    printf("== Menu aluno==\n\n");
    printf("1 - Criar aluno\n");
    printf("2 - Ler aluno\n");
    printf("3 - Atualizar aluno\n");
    printf("4 - Deletar aluno\n");
    printf("5 - Voltar menu anterior\n");
    printf("Opcao > ");
    scanf("%d", &opcao);
    getchar();
    if (opcao > 0 && opcao < 6) {
      return opcao;
    }
    printf("Opcao inválida!! Tente novamente\n\n");

  } while (1);
}
int menu_crud_professor() {
  int opcao = 2;
  do {
    printf("== Menu professor==\n\n");
    printf("1 - Criar professor\n");
    printf("2 - Ler professor\n");
    printf("3 - Atualizar professor\n");
    printf("4 - Deletar professor\n");
    printf("5 - Voltar menu anterior\n");
    printf("Opcao > ");
    scanf("%d", &opcao);
    getchar();
    if (opcao > 0 && opcao < 6) {
      return opcao;
    }
    printf("Opcao inválida!! Tente novamente\n\n");

  } while (1);
}
int menu_crud_turma() {
  int opcao = 3;
  do {
    printf("== Menu turma==\n\n");
    printf("1 - Criar turma\n");
    printf("2 - Ler turma\n");
    printf("3 - Atualizar turma\n");
    printf("4 - Deletar turma\n");
    printf("5 - Voltar menu anterior\n");
    printf("Opcao > ");
    scanf("%d", &opcao);
    getchar();
    if (opcao > 0 && opcao < 6) {
      return opcao;
    }
    printf("Opcao inválida!! Tente novamente\n\n");

  } while (1);
}