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

void cadastrarTurma();
// Função para exibir as informações de uma turma
void exibirTurma(const Turma* turma);

// Função para exibir todas as turmas cadastradas
void exibirTurmas();

// Função para atualizar as informações de uma turma
void atualizarTurma();

// Função para excluir uma turma
void excluirTurma();

int verificarCodigoTurma(const char* codigo);

void imprimirTurma(const char* codigo);

/*
    impressoes
*/

void imprimir_aluno(Aluno *aluno);
void imprimir_professor(Professor *professor);
void imprimir_turma(Turma *turma);
void imprimirTurma(const char* codigo);



int printAllTeachesNoClass();
void imprimirProfessoresNaoRelacionados(Turma* turmas, int numTurmas, Professor* professores, int numProfessores);
float lerMediaTurma();
#endif