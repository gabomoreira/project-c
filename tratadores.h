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

/*
    Busca um aluno
*/
Aluno *buscar_aluno();

void remover_aluno();

void imprimir_endereco(Endereco *endereco);

/**
 professor services
*/

void salvar_professor_service();
Professor *buscar_professor_service();
void atualizar_professor_service(Professor *professor);
void remover_professor_service();

/*
    impressoes
*/

void imprimir_aluno(Aluno *aluno);
void imprimir_professor(Professor *professor);

#endif