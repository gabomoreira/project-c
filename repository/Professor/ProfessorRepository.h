#include "../../dados.h"

// Função para obter a quantidade de professores armazenados em um arquivo binário
int obterQuantidadeProfessoresRepository();

// Função para salvar um orifessor em um arquivo binário
void salvarProfessorRepository(Professor *professor);

// Função para obter a um orifessor em um arquivo binário
Professor *resgatarProfessorRepository(char *matricula);

// Função para atualizar um orifessor em um arquivo binário
void atualizarProfessorRepository(Professor *professor);

// Função para remover um orifessor em um arquivo binário
void excluirProfessorRepository(char *matricula);

//função para listar os nomes dos professores
void listarNomesProfessores();

//função para buscar todos os professores
Professor* buscarProfessoresRepository(int* numProfessores);

int verificarProfessorEmTurma(char* matricula);



