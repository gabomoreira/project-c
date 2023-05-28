#include "./AlunoRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do db de aluno
static const char* RELATIVE_PATH_DB = "db/aluno.bin";

// Função para obter a quantidade de alunos armazenados em um arquivo binário
int obterQuantidadeAlunos()
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo)
    {
        // Definir o tamanho do registro do aluno no arquivo binário
        long tamanhoRegistro = sizeof(Aluno);

        // Mover o cursor do arquivo para o final
        fseek(arquivo, 0, SEEK_END);

        // Obter o tamanho total do arquivo
        long tamanhoArquivo = ftell(arquivo);

        // Calcular a quantidade de registros de alunos
        int quantidadeAlunos = tamanhoArquivo / tamanhoRegistro;

        fclose(arquivo);

        return quantidadeAlunos;
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n");
        return -1; // Valor de erro, se necessário
    }
}

// Função para adicionar um aluno a um arquivo binário existente
void salvarAlunoBinario(Aluno *aluno)
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "ab");
    if (arquivo)
    {
        fwrite(aluno, sizeof(Aluno), 1, arquivo);
        fclose(arquivo);
        printf("Aluno adicionado com sucesso!\n");
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n");
    }
}

// Função para resgatar um aluno de um arquivo binário a partir da matrícula
Aluno *resgatarAluno(char *matricula) {
    FILE *arquivo;
    Aluno *aluno;
    int encontrado = 0;

    // Abre o arquivo binário para leitura
    arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Aloca memória para o ponteiro aluno
    aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno == NULL) {
        printf("Erro ao alocar memória para o aluno.\n");
        fclose(arquivo);
        return NULL;
    }

    // Lê cada registro do arquivo, procurando pelo aluno com a matrícula correspondente
    while (!encontrado && fread(aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (strcmp(aluno->matricula, matricula) == 0) {
            encontrado = 1;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    if (encontrado) {
        // Aloca memória para o ponteiro endereco do aluno
        aluno->endereco = (Endereco *)malloc(sizeof(Endereco));
        if (aluno->endereco == NULL) {
            printf("Erro ao alocar memória para o endereço do aluno.\n");
            free(aluno);
            return NULL;
        }

        return aluno;
    } else {
        printf("Aluno não encontrado.\n");
        return NULL;
    }
}


// Função para atualizar um aluno de um arquivo binário
void atualizarAluno(Aluno *aluno) {
    FILE *arquivo;
    FILE *temporario;
    Aluno alunoAtualizado;

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
    while (fread(&alunoAtualizado, sizeof(Aluno), 1, arquivo) == 1) {
        if (strcmp(alunoAtualizado.matricula, aluno->matricula) == 0) {
            // Atualiza os dados do aluno
            strcpy(alunoAtualizado.nome, aluno->nome);
            strcpy(alunoAtualizado.cpf, aluno->cpf);
            // Atualiza o endereço
            strcpy(alunoAtualizado.endereco->logradouro, aluno->endereco->logradouro);
            strcpy(alunoAtualizado.endereco->bairro, aluno->endereco->bairro);
            strcpy(alunoAtualizado.endereco->cidade, aluno->endereco->cidade);
            strcpy(alunoAtualizado.endereco->estado, aluno->endereco->estado);
            strcpy(alunoAtualizado.endereco->numero, aluno->endereco->numero);
        }
        // Escreve o registro atualizado no arquivo temporário
        fwrite(&alunoAtualizado, sizeof(Aluno), 1, temporario);
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temporario);

    // Remove o arquivo original
    remove(RELATIVE_PATH_DB);

    // Renomeia o arquivo temporário para o nome original
    rename("temp.bin", RELATIVE_PATH_DB);

    printf("Dados do aluno atualizados com sucesso!\n");
}

// Função para remover um aluno de um arquivo binário
void excluirAluno(char *matricula) {
    FILE *arquivo;
    FILE *temporario;
    Aluno aluno;

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
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (strcmp(aluno.matricula, matricula) != 0) {
            // Escreve o registro no arquivo temporário, exceto se for o aluno a ser excluído
            fwrite(&aluno, sizeof(Aluno), 1, temporario);
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temporario);

    // Remove o arquivo original
    remove(RELATIVE_PATH_DB);

    // Renomeia o arquivo temporário para o nome original
    rename("temp.bin", RELATIVE_PATH_DB);

    printf("Aluno excluído com sucesso!\n");
}