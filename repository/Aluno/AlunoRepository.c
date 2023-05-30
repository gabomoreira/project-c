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
void salvarAlunoBinario(Aluno* aluno) 
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "ab+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    rewind(arquivo);
    Aluno alunoExistente;
    while (fread(&alunoExistente, sizeof(Aluno), 1, arquivo) == 1)
    {
        if (strcmp(alunoExistente.matricula, aluno->matricula) == 0)
        {
            printf("Ja existe um aluno com essa matricula.\n");
            fclose(arquivo);
            return;
        }
    }

    rewind(arquivo);
    while (fread(&alunoExistente, sizeof(Aluno), 1, arquivo) == 1)
    {
        if (strcmp(alunoExistente.cpf, aluno->cpf) == 0)
        {
            printf("Ja existe um aluno com esse CPF.\n");
            fclose(arquivo);
            return;
        }
    }

    fwrite(aluno, sizeof(Aluno), 1, arquivo);

    printf("Aluno cadastrado com sucesso!\n");

    fclose(arquivo);
}

// Função para resgatar um aluno de um arquivo binário a partir da matrícula
Aluno *resgatarAluno(char *matricula)
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); // Nome do arquivo binário dos alunos
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo\n");
        return NULL;
    }
    
    Aluno *aluno = NULL;
    while (1)
    {
        aluno = (Aluno *)malloc(sizeof(Aluno));
        if (!aluno)
        {
            perror("Não há memória disponível. Encerrando\n\n");
            return NULL;
        }
        
        if (fread(aluno, sizeof(Aluno), 1, arquivo) != 1)
        {
            free(aluno);
            break; // Finaliza o loop quando não houver mais alunos para ler
        }
        
        if (strcmp(aluno->matricula, matricula) == 0)
        {
            fclose(arquivo);
            return aluno; // Retorna o aluno encontrado
        }
        
        free(aluno); // Libera a memória alocada para o aluno atual
    }
    
    fclose(arquivo);
    return NULL; // Retorna NULL se o aluno não for encontrado
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
void excluirAluno(const char *matricula)
{
    FILE *arquivo;
    FILE *arquivoTemp;
    Aluno aluno;

    // Abrir o arquivo binário para leitura
    arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Criar um arquivo temporário para escrita
    arquivoTemp = fopen("temp.bin", "wb");
    if (arquivoTemp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Ler cada aluno do arquivo original e copiar para o arquivo temporário,
    // exceto o aluno com a matrícula fornecida
    int alunoEncontrado = 0;
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (strcmp(aluno.matricula, matricula) == 0) {
            alunoEncontrado = 1;
            continue; // Ignorar o aluno a ser excluído
        }
        fwrite(&aluno, sizeof(Aluno), 1, arquivoTemp);
    }

    // Fechar os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);

    if (alunoEncontrado) {
        // Remover o arquivo original
        remove(RELATIVE_PATH_DB);

        // Renomear o arquivo temporário para o nome original
        rename("temp.bin", RELATIVE_PATH_DB);

        printf("Aluno excluído com sucesso.\n");
    } else {
        remove("temp.bin"); // Não foi encontrado, então removemos o arquivo temporário
        printf("Aluno não encontrado.\n");
    }
}