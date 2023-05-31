//  Inclusão dos arquivos de cabeçalho e das bibliotecas necessárias para o código 
#include "./TurmaRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do banco de dados de turma
static const char* RELATIVE_PATH_DB = "db/turma.bin";

// Função para obter a quantidade de turmas armazenados em um arquivo binário
int obterQuantidadeTurmasRepository()
{   // Abre o arquivo no modo de leitura binária
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
        
        // Fecha o arquivo 
        fclose(arquivo);

        // Retorna a quantidade de turmas
        return quantidadeTurmas;
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n"); // Imprime uma mensagem de erro
        return -1; // Valor de erro, se o arquivo não puder ser aberto
    }
}


// Função para exibir as informações de uma turma
void exibirTurma(const Turma* turma) {
    printf("Código da Turma: %s\n", turma->codigo);
    printf("Disciplina: %s\n", turma->disciplina);
    printf("Professor: %s\n", turma->professor_turma);
    printf("Lista de Alunos: %s\n", turma->lista_alunos);
    printf("Média da Turma: %.2f\n", turma->media_turma);
    printf("\n");
}

// Função para exibir todas as turmas cadastradas
void exibirTurmas() {
    // Abra o arquivo no modo de leitura binária
    FILE* arquivo = fopen("db/turma.bin", "rb");
    // Imprimir mensagem de erro caso não haja arquivo 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Declaração de variáveis
    Turma turma;
    char codigoBuscado[50];
    
    // Pedir ao usuário o código a ser buscado
    printf("Digite o código da turma a ser buscada: ");
    scanf("%s", codigoBuscado);

    // Leia cada turma do arquivo e exiba suas informações
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigoBuscado) == 0) {
            exibirTurma(&turma);
            break;
        }
    }
    // Fechar o arquivo
    fclose(arquivo);
}

// Função para atualizar as informações de uma turma
void atualizarTurma() {
    // Declaração da variável codigo
    char codigo[50];
    
    // Exibir mensagem na tela 
    printf("Digite o código da turma que deseja atualizar: ");
    
    // Ler uma linha de texto e armazena na variávle código 
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    // Abra o arquivo no modo de leitura e escrita binária
    FILE* arquivo = fopen("db/turma.bin", "r+b");
    
    // Imprimir mensagem de erro caso não haja arquivo 

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Declaração de variável 
    Turma turma;

    // Pesquise pela turma com o código informado
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigo) == 0) {
            // Solicite ao usuário as novas informações da turma
            printf("Digite o novo código da turma: ");
            fgets(turma.codigo, sizeof(turma.codigo), stdin);
            turma.codigo[strcspn(turma.codigo, "\n")] = '\0';

            printf("Digite a nova disciplina: ");
            fgets(turma.disciplina, sizeof(turma.disciplina), stdin);
            turma.disciplina[strcspn(turma.disciplina, "\n")] = '\0';

            printf("Digite o novo professor da turma: ");
            fgets(turma.professor_turma, sizeof(turma.professor_turma), stdin);
            turma.professor_turma[strcspn(turma.professor_turma, "\n")] = '\0';

            printf("Digite a nova lista de alunos (separados por vírgula): ");
            fgets(turma.lista_alunos, sizeof(turma.lista_alunos), stdin);
            turma.lista_alunos[strcspn(turma.lista_alunos, "\n")] = '\0';

            printf("Digite a nova média da turma: ");
            scanf("%f", &turma.media_turma);
            getchar(); // Limpar o buffer do enter

            // Retorne para a posição do arquivo onde a turma está localizada
            fseek(arquivo, -sizeof(Turma), SEEK_CUR);

            // Escreva as novas informações da turma no arquivo
            fwrite(&turma, sizeof(Turma), 1, arquivo);

            printf("Turma atualizada com sucesso.\n");
            break;
        }
    }
    // Fecha o arquivo 
    fclose(arquivo);
}

// Função para excluir uma turma
void excluirTurma() {
    // Declara a variável código
    char codigo[50];
    
    // Solicite ao usuário o código da turma que ele deseja excluir
    printf("Digite o código da turma que deseja excluir: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    // Abre o arquivo no modo de leitura e escrita binária
    FILE* arquivo = fopen("db/turma.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Declaração de variável
    Turma turma;

    //Criação de arquivo binário temporário de escrita 
    FILE* arquivoTemp = fopen("temp.bin", "wb");
    
    // Imprime mensagem caso haja erro na criação do arquivo
    if (arquivoTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Copie todas as turmas que não têm o código informado para o arquivo temporário
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigo) != 0) {
            fwrite(&turma, sizeof(Turma), 1, arquivoTemp);
        }
    }

    // Fecha os arquivos 
    fclose(arquivo);
    fclose(arquivoTemp);

    // Remova o arquivo original
    remove("db/turma.bin");

    // Renomeie o arquivo temporário para o nome original
    rename("temp.bin", "db/turma.bin");

    printf("Turma excluída com sucesso.\n");
}

//Criação da função para imprimir turmas 

void imprimirTurma(const char* codigo) {
    // Abra o arquivo no modo de leitura binária
    FILE* arquivo = fopen("db/turma.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Declaração de variável
    Turma turma;

    // Loop de pesquisa pela turma com o código informado
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigo) == 0) {
            exibirTurma(&turma);
            break;
        }
    }
    // Fecha o arquivo 
    fclose(arquivo);
}
// Função para cadastrar turma 
void cadastrarTurma() {
    // Declaração de turma
    Turma turma;
    
    // Armazena o código da turma digitado pelo usuário 
    printf("Digite o código da turma: ");
    fgets(turma.codigo, sizeof(turma.codigo), stdin);
    turma.codigo[strcspn(turma.codigo, "\n")] = '\0';

    // Verificar se o código da turma já existe
    if (verificarCodigoTurma(turma.codigo)) {
        printf("Já existe uma turma cadastrada com esse código.\n");
        return;
    }

    // Leitura de dados digitados pelo usuário
    printf("Digite a disciplina: ");
    fgets(turma.disciplina, sizeof(turma.disciplina), stdin);
    turma.disciplina[strcspn(turma.disciplina, "\n")] = '\0';

    printf("Digite o professor da turma: ");
    fgets(turma.professor_turma, sizeof(turma.professor_turma), stdin);
    turma.professor_turma[strcspn(turma.professor_turma, "\n")] = '\0';

    printf("Digite a lista de alunos (separados por vírgula): ");
    fgets(turma.lista_alunos, sizeof(turma.lista_alunos), stdin);
    turma.lista_alunos[strcspn(turma.lista_alunos, "\n")] = '\0';

    printf("Digite a média da turma: ");
    scanf("%f", &turma.media_turma);
    getchar(); // Limpa o buffer do enter

    // Abre o arquivo no modo de escrita binária
    FILE* arquivo = fopen("db/turma.bin", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreva a turma no arquivo
    fwrite(&turma, sizeof(Turma), 1, arquivo);
    
    // Fecha o arquivo 
    fclose(arquivo);
    
    // Imprime mensagem de sucesso 
    printf("Turma cadastrada com sucesso.\n");
}

int verificarCodigoTurma(const char* codigo) {
    // Abra o arquivo no modo de leitura binária
    FILE* arquivo = fopen("db/turma.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    // Declaração de turma
    Turma turma;

    // Verifique se há uma turma com o mesmo código
    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigo) == 0) {
            fclose(arquivo);
            return 1; // Já existe uma turma com o mesmo código
        }
    }
    // Fecha o arquivo
    fclose(arquivo);

    return 0; // Retorna 0 caso não há turma com o mesmo código
}

// Função para o cálculo de média 

void calcularMediaTurmas() {

    // Leitura do arquivo binário referente a turma
    FILE* file = fopen("db/turma.bin", "rb");
    //  Imprime mensagem caso haja erro ao abrir o arquivo
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    // Declaração de variavéis 
    Turma turma;
    int count = 0;
    float soma = 0.0;

    // Lê e exibe as informações de todas as turmas presentes no arquivo 
    while (fread(&turma, sizeof(Turma), 1, file) == 1) {
        printf("Código: %s\n", turma.codigo);
        printf("Disciplina: %s\n", turma.disciplina);
        printf("Professor: %s\n", turma.professor_turma);
        printf("Lista de alunos: %s\n", turma.lista_alunos);
        printf("Média da turma: %.2f\n\n", turma.media_turma);
        
        // Calcula a soma das médias
        soma += turma.media_turma;
        // Atualiza contador
        count++;
    }
    // Fecha o arquivo 
    fclose(file);
    
    // Calcula e printa a média das turmas
    if (count > 0) {
        float mediaTotal = soma / count;
        printf("Média total das turmas: %.2f\n", mediaTotal);
    } else {
        printf("Nenhuma turma encontrada.\n");
    }
}

// Função que verifica se uma determinada matrícula está presente em alguma turma do arquivo binário 
void verificarMatricula(char* matricula) {
    FILE* arquivo = fopen("db/turma.bin", "rb");
    // Imprime na tela erro caso não consiga abrir o arquivo
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Declaração de turma
    Turma turma;

    // Percorre cada registro de turma no arquivo e verifica se uma determinada matrícula está presente na lista de alunos da turma
    while (fread(&turma, sizeof(Turma), 1, arquivo)) {
        char* token = strtok(turma.lista_alunos, ",");
        
        while (token != NULL) {
            if (strcmp(token, matricula) == 0) {
                printf("A matrícula '%s' está presente na turma '%s'.\n", matricula, turma.codigo);
                fclose(arquivo);
                return;
            }
            
            token = strtok(NULL, ",");
        }
    }
    // Fecha o arquivo 
    fclose(arquivo);
}

// Busca turmas armazenadas em um arquivo binário e as retorna como um array de estruturas Turma
Turma* buscarTurmasRepository(int* numTurmas) {
    FILE* file = fopen("db/turma.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Obter o número de registros no arquivo
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    *numTurmas = fileSize / sizeof(Turma);

    // Alocar memória para armazenar as turmas
    Turma* turmas = (Turma*)malloc(*numTurmas * sizeof(Turma));
    if (turmas == NULL) {
        printf("Erro de memoria.\n");
        fclose(file);
        return NULL;
    }

    // Ler os registros de turmas do arquivo
    fread(turmas, sizeof(Turma), *numTurmas, file);

    // Fecha o arquivo 
    fclose(file);

    // Retorna turmas
    return turmas;
}


