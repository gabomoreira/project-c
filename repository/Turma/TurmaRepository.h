// Inclui o arquivo de cabeçalho "dados.h" 
#include "../../dados.h"

// Função para obter a quantidade de turmas armazenados em um arquivo binário
int obterQuantidadeTurmasRepository();

// Função para cadastrar turma 
void cadastrarTurma();

// Função para exibir as informações de uma turma
void exibirTurma(const Turma* turma);

// Função para exibir todas as turmas cadastradas
void exibirTurmas();

// Função para atualizar as informações de uma turma
void atualizarTurma();

// Função para excluir uma turma
void excluirTurma();

// Função para verificar código da turma 
int verificarCodigoTurma(const char* codigo);

// Função para imprimir turma 
void imprimirTurma(const char* codigo);

// Função que permite que os dados das turmas sejam acessados e manipulados fora da função.
Turma* buscarTurmasRepository(int* numTurmas);
