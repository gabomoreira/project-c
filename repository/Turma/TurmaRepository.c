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


int verificarProfessorTurma(char *matricula) {
    FILE *arquivo;
    arquivo = fopen(RELATIVE_PATH_DB, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int encontrado = 0;
    char professorTurma[50];

    while (fread(professorTurma, sizeof(professorTurma), 1, arquivo) == 1) {
        if (strcmp(professorTurma, matricula) == 0) {
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    return encontrado;
}
// Função para calcular a média das notas presentes na lista de alunos da turma
 float lerMediaTurma() {
    FILE* arquivo = fopen( RELATIVE_PATH_DB , "rb"); // Abrir o arquivo binário em modo de leitura binária

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0.0;
    }

    Turma turma;

    // Ler a estrutura Turma diretamente do arquivo binário
    fread(&turma, sizeof(Turma), 1, arquivo);

    // Acessar a média da turma
    float media = turma.media_turma;

    printf("Média da turma: %.2f\n", media);

    fclose(arquivo); // Fechar o arquivo

    return media;
}