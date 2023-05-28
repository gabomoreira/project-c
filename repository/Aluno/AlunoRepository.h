#include "../../dados.h"

// Função para obter a quantidade de alunos armazenados em um arquivo binário
int obterQuantidadeAlunos();

// Função para salvar um aluno em um arquivo binário
void salvarAlunoBinario(Aluno *aluno);

// Função para obter a um aluno em um arquivo binário
Aluno *resgatarAluno(char *matricula);

// Função para atualizar um aluno em um arquivo binário
void atualizarAluno(Aluno *aluno);

// Função para remover um aluno em um arquivo binário
void excluirAluno(char *matricula);
