#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"

/*
 tratadores
*/

void tratador_menu_aluno();
void tratador_menu_turma();
void tratador_menu_professor();
void tratador_menu_estatistica();

/*
 Constructors 
*/

Endereco *construir_endereco();
Aluno *construir_aluno();
Professor *construir_professor();
Turma *construir_turma();

/*
    Busca um aluno
*/
Aluno *buscar_aluno();

void remover_aluno();

void imprimir_endereco(Endereco *endereco);

void cadastrarTurma();

/**
 professor services
*/

void salvar_professor_service();
Professor *buscar_professor_service();
void atualizar_professor_service(Professor *professor);
void remover_professor_service();

/**
 turma services
*/

void salvar_turma_service();
void buscar_turma_service();
void atualizar_turma_service(Turma *turma);
void remover_turma_service();

/*
    impressoes
*/

void imprimir_aluno(Aluno *aluno);
void imprimir_professor(Professor *professor);
void imprimir_turma(Turma *turma);
void imprimirTurma(const char* codigo);



int printAllTeachesNoClass();
void imprimirProfessoresNaoRelacionados(Turma* turmas, int numTurmas, Professor* professores, int numProfessores);

#endif