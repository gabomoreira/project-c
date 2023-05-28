#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Aluno *criarAluno(char *matricula, char *cpf, char *nome, Endereco *end) {
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if (aluno) {
    strcpy(aluno->matricula,
           matricula); // Copia matricula para aluno->matricula
    strcpy(aluno->cpf, cpf);
    strcpy(aluno->nome, nome);
    aluno->endereco = end;
  } else {
    perror("Não há memória disponível. Encerrando\n\n");
  }
  return aluno;
}
Professor *criarProfessor(char *matricula, char *cpf, char *nome,
                          Endereco *end) {
  Professor *professor = (Professor *)malloc(sizeof(Professor));
  if (professor) {
    strcpy(professor->matricula,
           matricula); // Copia matricula para aluno->matricula
    strcpy(professor->cpf, cpf);
    strcpy(professor->nome, nome);
    professor->endereco = end;
  } else {
    perror("Não há memória disponível. Encerrando\n\n");
  }
  return professor;
}
Turma *criarTurma(char *matricula, char *cpf, char *nome, Endereco *end) {
  Turma *turma = (Turma *)malloc(sizeof(Turma));
  if (turma) {
    strcpy(turma->matricula,
           matricula); // Copia matricula para aluno->matricula
    strcpy(turma->cpf, cpf);
    strcpy(turma->nome, nome);
    turma->endereco = end;
  } else {
    perror("Não há memória disponível. Encerrando\n\n");
  }
  return turma;
}

Endereco *criarEndereco(char *logradouro, char *bairro, char *cidade,
                        char *estado, char *numero) {
  Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
  if (endereco) {
    strcpy(endereco->logradouro, logradouro);
    strcpy(endereco->bairro, bairro);
    strcpy(endereco->cidade, cidade);
    strcpy(endereco->estado, estado);
    strcpy(endereco->numero, numero);
  } else {
    perror("Não há memória disponível. Encerrando\n\n");
  }
  return endereco;
}

void destruirAluno(Aluno *aluno) {
  if (aluno) {
    Endereco *end = aluno->endereco;
    destruirEndereco(end);
    free(aluno);
  }
}
void destruirProfessor(Professor *professor) {
  if (professor) {
    Endereco *end = professor->endereco;
    destruirEndereco(end);
    free(professor);
  }
}
void destruirTurma(Turma *turma) {
  if (turma) {
    Endereco *end = turma->endereco;
    destruirEndereco(end);
    free(turma);
  }
}

void destruirEndereco(Endereco *endereco) {
  if (endereco)
    free(endereco);
}