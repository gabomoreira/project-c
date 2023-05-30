#include "../../dados.h"

// Função para obter a quantidade de turmas armazenados em um arquivo binário
int obterQuantidadeTurmasRepository();


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


Turma* buscarTurmasRepository(int* numTurmas);
