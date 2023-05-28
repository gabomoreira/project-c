#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno)
    {
        strcpy(aluno->matricula, matricula); // Copia matricula para aluno->matricula
        strcpy(aluno->cpf, cpf);
        strcpy(aluno->nome, nome);
        aluno->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return aluno;
}
Professor *criarProfessor(char *matricula,
                          char *cpf,
                          char *nome,
                          Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    if (professor)
    {
        strcpy(professor->matricula, matricula);
        strcpy(professor->cpf, cpf);
        strcpy(professor->nome, nome);
        professor->endereco = end;
}
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return professor;
}

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
    if (endereco)
    {
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return endereco;
}



Turma* criarTurma(char* codigo,
                  char* disciplina,
                  char* professor_turma,
                  char** matriculas,
                  char* media_turma)
{
    Turma* turma = (Turma*)malloc(sizeof(Turma));
    if (turma)
    {
        strcpy(turma->codigo, codigo);
        strcpy(turma->disciplina, disciplina);
        strcpy(turma->professor_turma, professor_turma);

        // Copia as matrículas para a estrutura de dados
        int num_matriculas = sizeof(matriculas) / sizeof(matriculas[0]);
        turma->lista_alunos = (char**)malloc(num_matriculas * sizeof(char*));
        for (int i = 0; i < num_matriculas; i++)
        {
            turma->lista_alunos[i] = (char*)malloc((strlen(matriculas[i]) + 1) * sizeof(char));
            strcpy(turma->lista_alunos[i], matriculas[i]);
        }

        strcpy(turma->media_turma, media_turma);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return turma;
}

void destruirAluno(Aluno *aluno)
{
    if (aluno)
    {
        Endereco *end = aluno->endereco;
        destruirEndereco(end);
        free(aluno);
    }
}

void destruirEndereco(Endereco *endereco)
{
    if (endereco)
        free(endereco);
}