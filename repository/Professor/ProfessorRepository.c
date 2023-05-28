#include "./ProfessorRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do db de aluno
static const char* RELATIVE_PATH_DB = "db/professor.bin";
static const char* RELATIVE_PATH_DB_TURMA = "db/turma.bin";

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
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "ab");
    if (arquivo)
    {
        fwrite(professor, sizeof(Professor), 1, arquivo);
        fclose(arquivo);
        printf("Professor adicionado com sucesso!\n");
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n");
    }
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
void excluirProfessorRepository(char *matricula) {
    FILE *arquivo;
    FILE *temporario;
    Professor professor;
    int encontrado = 0;
    int professorJaCadastrado = 0;

    // acessar o abnco de dados de turmas e recuperar todos os registros
    // verificar cada matricula de cada turma com o parametro da matricula que foi passado
    professorJaCadastrado = 1;

    if (professorJaCadastrado) {
        
    } else {
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

    // Lê cada registro do arquivo, excluindo o aluno com a matrícula correspondente
    while (fread(&professor, sizeof(Professor), 1, arquivo) == 1) {
        if (strcmp(professor.matricula, matricula) != 0) {
            // Escreve o registro no arquivo temporário, exceto se for o professor a ser excluído
            fwrite(&professor, sizeof(Professor), 1, temporario);
        } else {
            encontrado = 1;
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temporario);

    // Remove o arquivo original
    remove(RELATIVE_PATH_DB);

    // Renomeia o arquivo temporário para o nome original
    rename("temp.bin", RELATIVE_PATH_DB);

    if (encontrado) {
        printf("Professor excluído com sucesso!\n");
    } else {
        printf("Professor não encontrado!!\n");
    }
    }
    
}
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

