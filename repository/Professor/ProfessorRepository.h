// Inclui o arquivo de cabeçalho "dados.h" 
#include "../../dados.h"

// Função para obter a quantidade de professores armazenados em um arquivo binário
int obterQuantidadeProfessoresRepository();

// Função para salvar um orifessor em um arquivo binário
void salvarProfessorRepository(Professor *professor);

// Função para obter a um orifessor em um arquivo binário
Professor *resgatarProfessorRepository();

// Função para atualizar um orifessor em um arquivo binário
void atualizarProfessorRepository(Professor *professor);

// Função para remover um orifessor em um arquivo binário
void excluirProfessorRepository();

// Função para listar os nomes dos professores
void listarNomesProfessores();

// Função para buscar todos os professores
Professor* buscarProfessoresRepository(int* numProfessores);

// Função para buscar os professores na turma
int verificarProfessorEmTurma(char* matricula);



