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

Endereco *construir_endereco();

Aluno *construir_aluno();

/*
    Busca um aluno
*/
Aluno *buscar_aluno();

void remover_aluno();

void imprimir_aluno(Aluno *aluno);

void imprimir_endereco(Endereco *endereco);

#endif