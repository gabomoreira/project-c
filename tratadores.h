#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"

/*
 tratadores
*/
// Declaração das fucções relacionadas a tratadores responsaveis por lidar com as operacoes especificas de cada entidade nos menus
void tratador_menu_aluno(); //declaracao de funcao que nao possui valor de retorno (void) e nao recebe nenhum parametro manupula o menu relacionado a aluno
void tratador_menu_turma(); //declaracao de funcao que nao possui valor de retorno (void) e nao recebe nenhum parametro, manupula o menu relacionado turma
void tratador_menu_professor(); //declaracao de funcao que nao possui valor de retorno (void) e nao recebe nenhum parametro, manupula o menu relacionado professor
void tratador_menu_estatistica(); //declaracao de funcao que nao possui valor de retorno (void) e nao recebe nenhum parametro, manupula o menu relacionado estatistica

/*
 Constructors 
*/

Endereco *construir_endereco(); //declaracao indicando a existencia da funcao "constuir_endereco"
Aluno *construir_aluno(); //declaracao indicando a existencia da funcao "constuir_aluno"
Professor *construir_professor(); //declaracao indicando a existencia da funcao "constuir_professor"
Turma *construir_turma(); //declaracao indicando a existencia da funcao "constuir_turma"

/*
    Busca um aluno
*/
Aluno *buscar_aluno(); //declaracao de funcao "buscar_aluno", que retorna um ponteiro da estrutura de dados "Aluno", que busca e retoma um aluno especifico.
void imprimir_endereco(Endereco *endereco);//declaracao defuncao sem retorno que imprimi as informacoes de um endereco
void cadastrarTurma();//declaracao de funcao sem retorno que cadastra uma nova turma com base na interacao do usuario


/*
    impressoes
*/

void imprimir_aluno(Aluno *aluno); //declaracao de funcao que nao retorna um valor e recebe um ponteiro para a estrutura de dados "Aluno" como parametro que imprime as informacoes de um aluno na tela.
void imprimir_professor(Professor *professor);//declaracao de funcao que nao retorna um valor e recebe um ponteiro para a estrutura de dados "Professor" como parametro que imprime as informacoes de um professor na tela.
void imprimir_turma(Turma *turma); //declaracao de funcao que nao retorna um valor e recebe um ponteiro para a estrutura de dados "Turma" como paramentro que imprime as informacoes de uma turma na tela.
void imprimirTurma(const char* codigo); //declaracao de funcao que retorna valor e recebe um ponteiro para um array de caracteres "const char" como parametro.


int printAllTeachesNoClass(); //declaracao de funcao que retorma um valor inteiro e responsavel por imprimir todas as disciplinas que nao possuem professores atriuido.
void imprimirProfessoresNaoRelacionados(Turma* turmas, int numTurmas, Professor* professores, int numProfessores);// declzracao de funcao que nao retorna valor, e recebe como parametro um array de estruturas de dados "Turma" e o ponteiro de total de professores.
void calcularMediaTurmas();//declaracao de funcao que realiza o calculo da media das turmas existentes

void verificarMatricula(char* matricula) ;//declaracao que retorna nenhum valor e que recebe como parametro um array de caracteres "char" que representa a matricula.
#endif //diretiva é utilizada para fechar a estrutura condicional iniciada pela diretiva #ifndef no início do arquivo de cabeçalho