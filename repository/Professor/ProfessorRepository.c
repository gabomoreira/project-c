//  Inclusão dos arquivos de cabeçalho e das bibliotecas necessárias para o código 
#include "./ProfessorRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do banco de dados de professor
static const char* RELATIVE_PATH_DB = "db/professor.bin";

// Função para obter a quantidade de professores armazenados em um arquivo binário
int obterQuantidadeProfessoresRepository()
{   // Abre o arquivo no modo de leitura binária
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); 
    if (arquivo)
    {
        // Definir o tamanho do registro de professor no arquivo binário
        long tamanhoRegistro = sizeof(Professor);

        // Mover o cursor do arquivo para o final
        fseek(arquivo, 0, SEEK_END);

        // Obter o tamanho total do arquivo
        long tamanhoArquivo = ftell(arquivo);

        // Calcular a quantidade de registros de alunos
        int quantidadeProfessores = tamanhoArquivo / tamanhoRegistro;
        
        // Fecha o arquivo 
        fclose(arquivo);

        // Retorna o número de registros de professores no arquivo binário 
        return quantidadeProfessores;
    }
    else
    {
        perror("Erro ao abrir o arquivo.\n"); // Imprime uma mensagem de erro
        return -1; // Valor de erro, se o arquivo não puder ser aberto
    }
}

// Função para adicionar um professor a um arquivo binário existente
void salvarProfessorRepository(Professor *professor)
{   // Abre o arquivo em modo de leitura e escrita binária ("ab+")
     FILE *arquivo = fopen(RELATIVE_PATH_DB, "ab+");
    
    // Imprimir mensagem de erro caso não haja arquivo 
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Retorna ao começo do arquivo 
    rewind(arquivo);
    
    // Declaração de variável 
    Professor professorExistente;

    /* Percorre os registros existentes para verificar se existe professor
    com a mesma mattrícula*/
    while (fread(&professorExistente, sizeof(Professor), 1, arquivo) == 1)
    {
        if (strcmp(professorExistente.matricula, professor->matricula) == 0)
        {   // Imprime mensagem caso haja professor relacionado a matrícula
            printf("Ja existe um professor com essa matricula.\n");
            // Fecha o arquivo 
            fclose(arquivo);
            return;
        }
    }

    // Retorna ao começo do arquivo 
    rewind(arquivo);
    /* Percorre os registros existentes para verificar se existe professor
    com o mesmo CPF*/
    while (fread(&professorExistente, sizeof(Professor), 1, arquivo) == 1)
    {
        if (strcmp(professorExistente.cpf, professor->cpf) == 0)
        {   // Imprime mensagem caso haja CPF relacionado a matrícula
            printf("Ja existe um professor com esse CPF.\n");
            // Fecha o arquivo
            fclose(arquivo);
            return;
        }
    }

    // Escreve o aluno no arquivo
    fwrite(professor, sizeof(Professor), 1, arquivo);
    // Imprime mensagem de cadastro com sucesso
    printf("Professor cadastrado com sucesso!\n");
    // Fecha o arquivo
    fclose(arquivo);
}

// Função para resgatar um professor de um arquivo binário a partir da matrícula
Professor *resgatarProfessorRepository()
{   // Captura a matrícula digitada pelo usuário
    char matricula[50]; // Declaração da variável do tipo caractere para armazenar a matrícula
    printf("Matricula > "); // Exibe a mensagem solicitando a matrícula ao usuário
    fgets(matricula, 49, stdin); // Lê a matrícula digitada pelo usuário e armazena na variável 'matricula'
    putchar('\n'); // Imprime uma nova linha 

    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); // Nome do arquivo binário dos alunos
    if (!arquivo) // Verifica se ocorreu um erro ao abrir o arquivo 
    {
        perror("Erro ao abrir o arquivo\n"); // Imprime uma mensagem de erro
        return NULL; // Retorna NULL para indicar uma falha na abertura do arquivo
    }
    // Declaração da variável professor do tipo ponteiro
    Professor *professor = NULL;
    // Inicia um loop infinito para percorrer os registros de aluno no arquivo 
    while (1)
    {   // Aloca a memória para um novo aluno
        professor = (Professor *)malloc(sizeof(Professor));
        // Condicional para exibir um erro, caso a alocação de memória falhe
        if (!professor)
        {   // Imprime mensagem de erro 
            perror("Não há memória disponível. Encerrando\n\n");
            return NULL;
        }
        // Verifica se não há mais registros para ler 
        if (fread(professor, sizeof(Professor), 1, arquivo) != 1)
        {   // Libera memória alocada para professor
            free(professor);
            break; // Finaliza o loop quando não houver mais professor para ler
        }
        // Verifica se a matrícula do professor lido corresponde à matrícula fornecida
        if (strcmp(professor->matricula, matricula) == 0)
        {   // Fecha o arquivo
            fclose(arquivo);
            return professor; // Retorna o professor encontrado
        }
        
        free(professor); // Libera a memória alocada para o professor atual
    }
    
    fclose(arquivo);
    return NULL; // Retorna NULL se o professor não for encontrado
}


// Função para atualizar um professor de um arquivo binário
void atualizarProfessorRepository(Professor *professor) {
    // Declaração das variáveis / ponteiros
    FILE *arquivo;
    FILE *temporario;
    Professor professorAtualizado;

    // Abre o arquivo binário para leitura
    arquivo = fopen(RELATIVE_PATH_DB, "rb");
        //Imprime a mensagem caso ocorra um erro 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Abre um arquivo temporário para escrita
    temporario = fopen("temp.bin", "wb");
    //Imprime a mensagem caso ocorra um erro
    if (temporario == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Lê cada registro do arquivo, atualiza os dados do professor se encontrar a matrícula correspondente
    while (fread(&professorAtualizado, sizeof(Professor), 1, arquivo) == 1) {
        if (strcmp(professorAtualizado.matricula, professor->matricula) == 0) {
            // Atualiza os dados do professor
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
    // Imprime mensagem quando os arquivos são atualizados 
    printf("Dados do professor atualizados com sucesso!\n");
}
// Função para remover um professor de um arquivo binário
void excluirProfessorRepository() {
    // Declaração de matrícuula 
    char matricula[10];
    
    // Entrada de dados na variável "matricula"
    printf("Digite a matrícula do professor que deseja excluir: ");
    scanf("%9s", matricula);
    
    // Abrir o arquivo binário para leitura
    FILE* fileTurmas = fopen("db/turma.bin", "rb+");
    // Imprime mensagem caso haja erro ao abrir o arquivo 
    if (fileTurmas == NULL) {
        printf("Erro ao abrir o arquivo de turmas.\n");
        return;
    }
    // Declaração de turma
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

   // Abre um arquivo temporário para escrita
    FILE* fileTemp = fopen("temp.bin", "wb");
    //Imprime a mensagem caso ocorra um erro
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

    // Fecha os arquivos
    fclose(fileProfessores);
    fclose(fileTemp);
    fclose(fileTurmas);

    // Remove o arquivo de professores original
    remove(RELATIVE_PATH_DB);
    
    // Renomeia o arquivo temporário para o nome original
    rename("temp.bin", RELATIVE_PATH_DB);
    // Imprime mensagem quando os arquivos são atualizados 
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
         // Imprime mensagem quando não há registros de professores  
        printf("não há registros de professores ");
    }
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

    // Declaração das variáveis / ponteiros 
    Professor* professores = NULL;
    Professor professor;
    *numProfessores = 0;


    while (fread(&professor, sizeof(Professor), 1, arquivo) == 1) {
        // Realocação de memória para o vetor de professores
        professores = realloc(professores, (*numProfessores + 1) * sizeof(Professor));
        
        // Tratamento de erro em caso de falha na alocação de memória
        if (!professores) {
            perror("Erro ao alocar memória para os professores.\n");
            fclose(arquivo);
            return NULL;
        }
        
        // Armazena o professor lido no vetor de professores
        professores[*numProfessores] = professor;
        
        // Incrementr o contador de professores
        (*numProfessores)++;
    }
    // Fecha o arquivo
    fclose(arquivo);
    // Retorna a variável "professores"
    return professores;
}
