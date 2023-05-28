#include "./TurmaRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do db de turma
static const char* RELATIVE_PATH_DB = "db/turma.bin";

// Função para obter a quantidade de turmas armazenados em um arquivo binário
int obterQuantidadeTurmasRepository()
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo)
    {
        // Definir o tamanho do registro da turma no arquivo binário
        long tamanhoRegistro = sizeof(Turma);

        // Mover o cursor do arquivo para o final
        fseek(arquivo, 0, SEEK_END);

        // Obter o tamanho total do arquivo
        long tamanhoArquivo = ftell(arquivo);

        // Calcular a quantidade de registros de turmas
        int quantidadeTurmas = tamanhoArquivo / tamanhoRegistro;

        fclose(arquivo);

        return quantidadeTurmas;
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n");
        return -1; // Valor de erro, se necessário
    }
}

// Função para adicionar uma turma a um arquivo binário existente
void salvarTurmaRepository(Turma *turma) {
     // Verificar se já existe uma turma com o mesmo código
    FILE* arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo) {
        Turma turmaExistente;
        while (fread(&turmaExistente, sizeof(Turma), 1, arquivo) == 1) {
            if (strcmp(turmaExistente.codigo, turma->codigo) == 0) {
                printf("Já existe uma turma com o mesmo código.\n");
                fclose(arquivo);
                return;
            }
        }
        fclose(arquivo);
    }

    // Abrir o arquivo para escrita em modo binário (append)
    arquivo = fopen(RELATIVE_PATH_DB, "ab");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escrever a turma no arquivo
    fwrite(turma, sizeof(Turma), 1, arquivo);
    fclose(arquivo);

    
    free(turma);
    free(turma->lista_alunos);

    printf("Turma criada e armazenada no arquivo com sucesso.\n");
}

// Função para resgatar uma turma de um arquivo binário a partir da matrícula
Turma *resgatarTurmaRepository(char *codigo)
{
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); // Nome do arquivo binário das turmas
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo\n");
        return NULL;
    }
    
    Turma *turma = NULL;
    while (1)
    {
        turma = (Turma *)malloc(sizeof(Turma));
        if (!turma)
        {
            perror("Não há memória disponível. Encerrando\n\n");
            return NULL;
        }
        
        if (fread(turma, sizeof(Turma), 1, arquivo) != 1)
        {
            free(turma);
            break; // Finaliza o loop quando não houver mais turma para ler
        }
        
        if (strcmp(turma->codigo, codigo) == 0)
        {
            fclose(arquivo);
            return turma; // Retorna a turma encontrada
        }
        
        free(turma); // Libera a memória alocada para a turma atual
    }
    
    fclose(arquivo);
    return NULL; // Retorna NULL se a turma não for encontrada
}


// Função para atualizar uma turma de um arquivo binário
void atualizarTurmaRepository(Turma *turma) {
    // FILE *arquivo;
    // FILE *temporario;
    // Turma turmaAtualizado;

    // // Abre o arquivo binário para leitura
    // arquivo = fopen(RELATIVE_PATH_DB, "rb");
    // if (arquivo == NULL) {
    //     printf("Erro ao abrir o arquivo.\n");
    //     return;
    // }

    // // Abre um arquivo temporário para escrita
    // temporario = fopen("temp.bin", "wb");
    // if (temporario == NULL) {
    //     printf("Erro ao abrir o arquivo temporário.\n");
    //     fclose(arquivo);
    //     return;
    // }

    // // Lê cada registro do arquivo, atualiza os dados de turma se encontrar o código correspondente
    // while (fread(&turmaAtualizado, sizeof(Turma), 1, arquivo) == 1) {
    //     if (strcmp(turmaAtualizado.codigo, turma->codigo) == 0) {
    //         // Atualiza os dados da turma
    //         strcpy(turmaAtualizado.disciplina, turma->disciplina);
    //         strcpy(turmaAtualizado.professor_turma, turma->professor_turma);
    //         strcpy(turmaAtualizado.lista_alunos, turma->lista_alunos);
    //         strcpy(turmaAtualizado.media_turma, turma->media_turma);        

    //     }
    //     // Escreve o registro atualizado no arquivo temporário
    //     fwrite(&turmaAtualizado, sizeof(Turma), 1, temporario);
    // }

    // // Fecha os arquivos
    // fclose(arquivo);
    // fclose(temporario);

    // // Remove o arquivo original
    // remove(RELATIVE_PATH_DB);

    // // Renomeia o arquivo temporário para o nome original
    // rename("temp.bin", RELATIVE_PATH_DB);

    // printf("Dados da turma atualizados com sucesso!\n");
}

// Função para remover uma turma de um arquivo binário
void excluirTurmaRepository(char *codigo) {
    FILE *arquivo;
    FILE *temporario;
    Turma turma;
    int encontrado = 0;

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

    // Lê cada registro do arquivo, excluindo a turma com o código correspondente
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigo) != 0) {
            // Escreve o registro no arquivo temporário, exceto se for a turma a ser excluída
            fwrite(&turma, sizeof(Turma), 1, temporario);
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
        printf("Turma excluída com sucesso!\n");
    } else {
        printf("Turma não encontrada!!\n");
    }
}