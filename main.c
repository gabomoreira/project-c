#include "constantes.h"
#include "dados.h"
#include "menus.h"
#include "tratadores.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int op_menu_principal = 0;
  Aluno *alunos[MAX_ALUNO] = {NULL};
  Professor *professores[MAX_PROFESSOR] = {NULL};
  Turma *turmas[MAX_TURMA] = {NULL};

  int qtd_atual_aluno = 0;
  int qtd_atual_professor = 0;
  int qtd_atual_turma = 0;

  do {
    op_menu_principal = menu_principal();
    switch (op_menu_principal) {
    case 1:
      tratador_menu_aluno(alunos, &qtd_atual_aluno);
      break;
    case 2:
      tratador_menu_professor(professores, &qtd_atual_professor);
      break;
    case 3:
      tratador_menu_turma(turmas, &qtd_atual_turma);
      break;
    case 4:
      printf("Finalizando app...\n\n");
    }
  } while (op_menu_principal != 5);
  return 0;
}
