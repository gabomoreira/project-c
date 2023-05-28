#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
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