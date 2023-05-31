//  Inclusão dos arquivos de cabeçalho e das bibliotecas necessárias para o código 
#include "./AlunoRepository.h"
#include "../../dados.h"
#include "../../constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaração de uma constante para o caminho do banco de dados de alunos (arquivo binário)
static const char* RELATIVE_PATH_DB = "db/aluno.bin";

// Função para obter a quantidade de alunos armazenados em um arquivo binário
int obterQuantidadeAlunos()
{   // Abre o arquivo no modo de leitura binária
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); // Abre o arquivo no modo de leitura binária
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

        // Fecha o arquivo
        fclose(arquivo);

        // Retorna o número de registros de alunos no arquivo binário 
        return quantidadeAlunos;
    }
    else
    {   
        perror("Erro ao abrir o arquivo.\n"); // Imprime uma mensagem de erro 
        return -1; // Valor de erro, se o arquivo não puder ser aberto 
    }
}

// Função para adicionar um aluno a um arquivo binário existente
void salvarAlunoBinario(Aluno* aluno)
{   // Abre o arquivo em modo de leitura e escrita binária ("ab+")
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "ab+"); 

    // Imprimir mensagem de erro caso não haja arquivo     
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    rewind(arquivo);
    Aluno alunoExistente;
    
    /* Percorre os registros existentes para verificar se existe aluno
    com a mesma mattrícula*/
    while (fread(&alunoExistente, sizeof(Aluno), 1, arquivo) == 1)
    {      
        if (strcmp(alunoExistente.matricula, aluno->matricula) == 0)
        {   // Imprime mensagem caso haja aluno relacionado a matrícula
            printf("Ja existe um aluno com essa matricula.\n");
            // Fecha o arquivo
            fclose(arquivo);
            return;
        }
    }

    // Retorna ao começo do arquivo 
    rewind(arquivo);
    /* Percorre os registros existentes para verificar se existe aluno
    com o mesmo CPF*/
    while (fread(&alunoExistente, sizeof(Aluno), 1, arquivo) == 1)
    {       
        if (strcmp(alunoExistente.cpf, aluno->cpf) == 0)
        {   // Imprime mensagem caso haja CPF relacionado a matrícula
            printf("Ja existe um aluno com esse CPF.\n");
            // Fecha o arquivo 
            fclose(arquivo);
            return;
        }
    }

    // Escreve o aluno no arquivo
    fwrite(aluno, sizeof(Aluno), 1, arquivo);
    // Imprime mensagem de cadastro com sucesso
    printf("Aluno cadastrado com sucesso!\n");
    // Fecha o arquivo 
    fclose(arquivo);
}

// Função para resgatar um aluno de um arquivo binário a partir da matrícula
Aluno *resgatarAluno(char *matricula)
{   // Abre o arquivo no modo de leitura binária ("rb")
    FILE *arquivo = fopen(RELATIVE_PATH_DB, "rb"); // Nome do arquivo binário dos alunos
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo\n");
        return NULL;
    }
    // Declaração da variável aluno do tipo ponteiro
    Aluno *aluno = NULL;
    // Inicia um loop infinito para percorrer os registros de aluno no arquivo 
    while (1)
    {   // Aloca a memória para um novo aluno 
        aluno = (Aluno *)malloc(sizeof(Aluno));
        // Condicional para exibir um erro, caso a alocação de memória falhe
        if (!aluno)
        {   // Imprime mensagem de erro 
            perror("Não há memória disponível. Encerrando\n\n");
            return NULL;
        }
        // Verifica se não há mais registros para ler 
        if (fread(aluno, sizeof(Aluno), 1, arquivo) != 1)
        {   // Libera memória alocada para aluno 
            free(aluno);
            break; // Finaliza o loop quando não houver mais alunos para ler
        }
        // Verifica se a matrícula do aluno lido corresponde à matrícula fornecida 
        if (strcmp(aluno->matricula, matricula) == 0)
        {   // Fecha o arquivo 
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
     // Declaração das variáveis / ponteiros
    FILE *arquivo;
    FILE *temporario;
    Aluno alunoAtualizado;

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
    // Imprime mensagem quando os arquivos são atualizados 
    printf("Dados do aluno atualizados com sucesso!\n");
}

// Função para remover um aluno de um arquivo binário
void excluirAluno(const char *matricula)
{
    // Declaração das variáveis / ponteiros
    FILE *arquivo;
    FILE *arquivoTemp;
    Aluno aluno;

    // Abrir o arquivo binário para leitura
    arquivo = fopen(RELATIVE_PATH_DB, "rb");
    // Imprime mensagem caso haja erro ao abrir o arquivo 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Criar um arquivo temporário para escrita
    arquivoTemp = fopen("temp.bin", "wb");
    // Imprime mensagem caso haja erro ao abrir o arquivo
    if (arquivoTemp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    /* Lê cada aluno do arquivo original e copia para o arquivo temporário,
     exceto o aluno com a matrícula fornecida*/
    int alunoEncontrado = 0;

    // Loop para lê os registros de aluno do arquivo 
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        // Verifica se a matrícula do aluno lido corresponde a fornecida
        if (strcmp(aluno.matricula, matricula) == 0) {
            alunoEncontrado = 1;
            continue; // Ignorar o aluno a ser excluído
        }
        // Escreve o registro no arquivo temporário
        fwrite(&aluno, sizeof(Aluno), 1, arquivoTemp);
    }

    // Fechar os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);
    
    // Condicional para verificar se o aluno foi encontrado 
    if (alunoEncontrado) {
    
        // Remover o arquivo original
        remove(RELATIVE_PATH_DB);
    
        // Renomear o arquivo temporário para o nome original
        rename("temp.bin", RELATIVE_PATH_DB);
    
        // Imprime mensagem caso a exclusão seja realizada com sucesso 
        printf("Aluno excluído com sucesso.\n");

    } else {
 
        // Remove o arquivo temporário caso o aluno não seja excluído
        remove("temp.bin"); // Não foi encontrado, então removemos o arquivo temporário
        printf("Aluno não encontrado.\n");
    }
}