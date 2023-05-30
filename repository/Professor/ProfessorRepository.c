#include "./ProfessorRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do db de aluno
static const char* RELATIVE_PATH_DB = "db/professor.bin";

// Função para obter a quantidade de professores armazenados em um arquivo binário
int obterQuantidadeProfessoresRepository()
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo)
    {
        // Definir o tamanho do registro do aluno no arquivo binário
        long tamanhoRegistro = sizeof(Professor);

        // Mover o cursor do arquivo para o final
        fseek(arquivo, 0, SEEK_END);

        // Obter o tamanho total do arquivo
        long tamanhoArquivo = ftell(arquivo);

        // Calcular a quantidade de registros de alunos
        int quantidadeProfessores = tamanhoArquivo / tamanhoRegistro;

        fclose(arquivo);

        return quantidadeProfessores;
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n");
        return -1; // Valor de erro, se necessário
    }
}

// Função para adicionar um professor a um arquivo binário existente
void salvarProfessorRepository(Professor *professor)
{
     FILE *arquivo = fopen(RELATIVE_PATH_DB, "ab+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    rewind(arquivo);
    Professor professorExistente;
    while (fread(&professorExistente, sizeof(Professor), 1, arquivo) == 1)
    {
        if (strcmp(professorExistente.matricula, professor->matricula) == 0)
        {
            printf("Ja existe um professor com essa matricula.\n");
            fclose(arquivo);
            return;
        }
    }

    rewind(arquivo);
    while (fread(&professorExistente, sizeof(Professor), 1, arquivo) == 1)
    {
        if (strcmp(professorExistente.cpf, professor->cpf) == 0)
        {
            printf("Ja existe um professor com esse CPF.\n");
            fclose(arquivo);
            return;
        }
    }

    fwrite(professor, sizeof(Professor), 1, arquivo);

    printf("Professor cadastrado com sucesso!\n");

    fclose(arquivo);
}

// Função para resgatar um professor de um arquivo binário a partir da matrícula
Professor *resgatarProfessorRepository(char *matricula)
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); // Nome do arquivo binário dos alunos
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo\n");
        return NULL;
    }
    
    Professor *professor = NULL;
    while (1)
    {
        professor = (Professor *)malloc(sizeof(Professor));
        if (!professor)
        {
            perror("Não há memória disponível. Encerrando\n\n");
            return NULL;
        }
        
        if (fread(professor, sizeof(Professor), 1, arquivo) != 1)
        {
            free(professor);
            break; // Finaliza o loop quando não houver mais professor para ler
        }
        
        if (strcmp(professor->matricula, matricula) == 0)
        {
            fclose(arquivo);
            return professor; // Retorna o professor encontrado
        }
        
        free(professor); // Libera a memória alocada para o aluno atual
    }
    
    fclose(arquivo);
    return NULL; // Retorna NULL se o aluno não for encontrado
}


// Função para atualizar um professor de um arquivo binário
void atualizarProfessorRepository(Professor *professor) {
    FILE *arquivo;
    FILE *temporario;
    Professor professorAtualizado;

    // Abre o arquivo binário para leitura
    arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Abre um arquivo temporário para escrita
    temporario = fopen("temp.bin", "wb");
    if (temporario == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Lê cada registro do arquivo, atualiza os dados do aluno se encontrar a matrícula correspondente
    while (fread(&professorAtualizado, sizeof(Professor), 1, arquivo) == 1) {
        if (strcmp(professorAtualizado.matricula, professor->matricula) == 0) {
            // Atualiza os dados do aluno
            strcpy(professorAtualizado.nome, professor->nome);
            strcpy(professorAtualizado.cpf, professor->cpf);
            // Atualiza o endereço
            strcpy(professorAtualizado.endereco->logradouro, professor->endereco->logradouro);
            strcpy(professorAtualizado.endereco->bairro, professor->endereco->bairro);
            strcpy(professorAtualizado.endereco->cidade, professor->endereco->cidade);
            strcpy(professorAtualizado.endereco->estado, professor->endereco->estado);
            strcpy(professorAtualizado.endereco->numero, professor->endereco->numero);
        }
        // Escreve o registro atualizado no arquivo temporário
        fwrite(&professorAtualizado, sizeof(Professor), 1, temporario);
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temporario);

    // Remove o arquivo original
    remove(RELATIVE_PATH_DB);

    // Renomeia o arquivo temporário para o nome original
    rename("temp.bin", RELATIVE_PATH_DB);

    printf("Dados do professor atualizados com sucesso!\n");
}

// Função para remover um professor de um arquivo binário
void excluirProfessorRepository(char* matricula) {
    FILE* fileTurmas = fopen("db/turma.bin", "rb+");
    if (fileTurmas == NULL) {
        printf("Erro ao abrir o arquivo de turmas.\n");
        return;
    }

    Turma turma;

    // Percorre todas as turmas buscando a correspondência entre professor_turma e matricula
    while (fread(&turma, sizeof(Turma), 1, fileTurmas) == 1) {
        if (strcmp(turma.professor_turma, matricula) == 0) {
            printf("A matrícula do professor está associada à turma %s. A exclusão não pode ser realizada.\n", turma.codigo);
            fclose(fileTurmas);
            return;
        }
    }

    // Se a matrícula não está associada a nenhuma turma, inicia a exclusão do professor
    FILE* fileProfessores = fopen(RELATIVE_PATH_DB, "rb");
    if (fileProfessores == NULL) {
        printf("Erro ao abrir o arquivo de professores.\n");
        fclose(fileTurmas);
        return;
    }

    FILE* fileTemp = fopen("temp.bin", "wb");
    if (fileTemp == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(fileProfessores);
        fclose(fileTurmas);
        return;
    }

    Professor professor;

    // Copia todos os professores que não possuem a matrícula informada para o arquivo temporário
    while (fread(&professor, sizeof(Professor), 1, fileProfessores) == 1) {
        if (strcmp(professor.matricula, matricula) != 0) {
            fwrite(&professor, sizeof(Professor), 1, fileTemp);
        }
    }

    fclose(fileProfessores);
    fclose(fileTemp);
    fclose(fileTurmas);

    // Remove o arquivo de professores original
    remove(RELATIVE_PATH_DB);
    // Renomeia o arquivo temporário para o nome original
    rename("temp.bin", RELATIVE_PATH_DB);

    printf("Professor excluído com sucesso.\n");
}

// Função que verifica se um professor esta associado a uma turma
int verificarProfessorEmTurma(char* matricula) {
    FILE* arquivo;
    Turma turma;

    // Abre o arquivo binário de turmas para leitura
    arquivo = fopen("db/turma.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de turmas.\n");
        return 0;
    }

    // Lê cada registro de turma do arquivo e verifica se a matrícula do professor está presente
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.professor_turma, matricula) == 0) {
            fclose(arquivo);
            return 1;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}

// Função para listar os nomes dos professores
void listarNomesProfessores()
 {
    
    // Abrir o arquivo binário para leitura
    FILE* fp = fopen(RELATIVE_PATH_DB, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Calcular o tamanho do arquivo
    fseek(fp, 0, SEEK_END);
    long tamanhoArquivo = ftell(fp);
    rewind(fp);

    // Calcular o número de registros de professores
    int numProfessores = tamanhoArquivo / sizeof(Professor);
    if (numProfessores)
    {
        Professor professor;
    for (int i = 0; i < numProfessores; i++) {
        fread(&professor, sizeof(Professor), 1, fp);
        printf("%d. %s\n", i + 1, professor.nome);
    }

    } 
    else {
        printf("não há registros de professores ");
    }


    // Ler e listar os nomes dos professores
    

    // Fechar o arquivo
    fclose(fp);
}

// Função buscar um professor
Professor* buscarProfessoresRepository(int* numProfessores) {
    FILE* arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de professores.\n");
        return NULL;
    }

    Professor* professores = NULL;
    Professor professor;

    *numProfessores = 0;
    while (fread(&professor, sizeof(Professor), 1, arquivo) == 1) {
        professores = realloc(professores, (*numProfessores + 1) * sizeof(Professor));
        if (!professores) {
            perror("Erro ao alocar memória para os professores.\n");
            fclose(arquivo);
            return NULL;
        }
        professores[*numProfessores] = professor;
        (*numProfessores)++;
    }

    fclose(arquivo);
    return professores;
}
