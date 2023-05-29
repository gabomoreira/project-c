#include "../../dados.h"

// Função para obter a quantidade de turmas armazenados em um arquivo binário
int obterQuantidadeTurmasRepository();

// Função para salvar uma turma em um arquivo binário
void salvarTurmaRepository(Turma *turma);

// Função para obter a turma em um arquivo binário
Turma *resgatarTurmaRepository(char *codigo);

// Função para atualizar uma turma em um arquivo binário
void atualizarTurmaRepository(Turma *turma);

// Função para remover uma turma em um arquivo binário
void excluirTurmaRepository(char *codigo);

// Função para buscar todas as turmas em um arquivo binário
Turma* buscarTurmasRepository(int* numTurmas);

// Função que retorna se o professor está relacionado a uma turma
int verificarProfessorTurma(char *matricula);

