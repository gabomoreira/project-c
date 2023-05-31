#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"

/*
 tratadores
*/
// Declaração das fucções relacionadas a tratadores que provavelmente
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
void imprimir_endereco(Endereco *endereco);
void cadastrarTurma();


/*
    impressoes
*/

void imprimir_aluno(Aluno *aluno);
void imprimir_professor(Professor *professor);
void imprimir_turma(Turma *turma);
void imprimirTurma(const char* codigo);



int printAllTeachesNoClass();
void imprimirProfessoresNaoRelacionados(Turma* turmas, int numTurmas, Professor* professores, int numProfessores);
void calcularMediaTurmas();

void verificarMatricula(char* matricula) ;
#endif