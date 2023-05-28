#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
void tratador_menu_professor(Professor **professores, int *qtd_atual_professor);
void tratador_menu_turma(Turma **turma, int *qtd_atual_turma);
Endereco *construir_endereco();

Aluno *construir_aluno();
Professor *construir_professor();
Turma *construir_turma();

/*
    Busca um aluno
*/
Aluno *buscar_aluno(Aluno **alunos, int *posicao);
Professor *buscar_professor(Professor **professores, int *posicao);
Turma *buscar_turma(Turma **turmas, int *posicao);

void imprimir_aluno(Aluno *aluno);
void imprimir_professor(Professor *professor);
void imprimir_turma(Turma *turma);

void imprimir_endereco(Endereco *endereco);

#endif