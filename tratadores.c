#include "tratadores.h"
#include "./repository/Aluno/AlunoRepository.h"
#include "./repository/Professor/ProfessorRepository.h"
#include "./repository/Turma/TurmaRepository.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>
#include <stdlib.h>

// funcionando aparentemente
void tratador_menu_aluno()
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    
    int quantidadeAlunos = obterQuantidadeAlunos();

    if (quantidadeAlunos != -1)
    {
        printf("Quantidade de alunos armazenados: %d\n", quantidadeAlunos);
    } else {
        printf("Erro no banco");
    }

    switch (opcao)
    {
    case 1:
        if (quantidadeAlunos >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            salvarAlunoBinario(construir_aluno());
        }
        break;
    case 2:
    {
        Aluno *aluno = buscar_aluno();
        if (aluno == NULL)
        {
            printf("Aluno não encontrado.\n");
            return;
        }

        printf("Dados do Aluno:\n");
        imprimir_aluno(aluno);

    }
    break;
    case 3:
    {
        atualizarAluno(construir_aluno());
    }

    break;
    case 4:
    {
        remover_aluno();
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

// ja implementado
void tratador_menu_professor()
{
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    
    int quantidadeProfessores = obterQuantidadeProfessoresRepository();

    if (quantidadeProfessores != -1)
    {
        printf("Quantidade de professores armazenados: %d\n", quantidadeProfessores);
    } else {
        printf("Erro no banco");
    }

    switch (opcao)
    {
    case 1:
        if (quantidadeProfessores >= MAX_PROFESSOR)
        {
            printf("Numero maximo de professores atingido\n");
        }
        else
        {
            salvar_professor_service();
        }
        break;
    case 2:
    {   
        Professor *professor = buscar_professor_service();
        if (professor == NULL)
        {
            printf("Professor não encontrado.\n");
            return;
        }

        printf("Dados do Professor:\n");
        imprimir_professor(professor);
    }
    break;
    case 3:
    {
        atualizar_professor_service(construir_professor());
    }

    break;
    case 4:
    {
        remover_professor_service();
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_turma()
{
    int opcao = menu_crud_turma();
    Turma *turma = NULL;
    
    int quantidadeTurmas = obterQuantidadeTurmasRepository();

    if (quantidadeTurmas != -1)
    {
        printf("Quantidade de turmas armazenadas: %d\n", quantidadeTurmas);
    } else {
         printf("Erro no banco");
     }

    switch (opcao)
    {
    case 1:
        // funcao para o case 1

        if (quantidadeTurmas >= MAX_TURMA)
        {
             printf("Número máximo de turmas atingido\n");
         }
         else
         {
            salvar_turma_service();
         }
         break;
    case 2:
    {
         // funcao para o case 2

        buscar_turma_service();

    }
    break;
    case 3:
    {
         // funcao para o case 3

        // atualizar_turma_service(construir_turma());
    }

    break;
    case 4:
    {
         // funcao para o case 4

        remover_turma_service();
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_estatistica()
{
    int opcao = menu_crud_estatistica();

    switch (opcao)
    {
    case 1:
    {
        listarNomesProfessores();
    }
    break;

    case 2:
    {
        printAllTeachesNoClass();
        return;

    }
    break;
    case 3:
    {
         // funcao para o case 3

        // atualizarAluno(construir_aluno());
    }

    break;
    case 4:
    {
         // funcao para o case 4

        // remover_aluno();
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}


// professor services

void salvar_professor_service() {

    return salvarProfessorRepository(construir_professor());
}

Professor *buscar_professor_service() {
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return resgatarProfessorRepository(matricula);
}

void atualizar_professor_service(Professor *professor)
{
    return atualizarProfessorRepository(professor);
}

void remover_professor_service() {

    char matricula[50];
    int professorExiste = 0;
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');
    professorExiste = verificarProfessorTurma(matricula);
    printf("%o\n", professorExiste);
    if (professorExiste){
        printf("Erro ao deletar professor\n");
        printf("Professor esta relacionado a turma\n");

    }else{
        excluirProfessorRepository(matricula);
    }

    return;
}

// turma services

void salvar_turma_service() {

    return cadastrarTurma();
}

void buscar_turma_service() {
     char codigo[50];

    printf("Digite o código da turma: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    return imprimirTurma(codigo);
}

void atualizar_turma_service(Turma *turma)
{
    return atualizarTurmaRepository(turma);
}

void remover_turma_service() {

    char codigo[50];
    printf("Codigo > ");
    fgets(codigo, 50, stdin);
    putchar('\n');

    return excluirTurmaRepository(codigo);
}

int printAllTeachesNoClass() {
    int numTurmas;
    Turma* turmas = buscarTurmasRepository(&numTurmas);

    if (!turmas) {
        printf("Erro ao buscar as turmas.\n");
        return 1;
    }

    int numProfessores;
    Professor* professores = buscarProfessoresRepository(&numProfessores);

    if (!professores) {
        printf("Erro ao buscar os professores.\n");
        free(turmas);
        return 1;
    }

    imprimirProfessoresNaoRelacionados(turmas, numTurmas, professores, numProfessores);

    free(turmas);
    free(professores);
}




// constructors

Professor *construir_professor()
{
    Professor professor;

    printf("Matricula\t> ");
    fgets(professor.matricula, 100, stdin);
    printf("CPF\t> ");
    fgets(professor.cpf, 100, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 100, stdin);
    
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, construir_endereco());
}

Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Numero\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

Aluno *construir_aluno()
{
    Aluno aluno;

    printf("Matricula\t> ");
    fgets(aluno.matricula, 100, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 100, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 100, stdin);
    
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, construir_endereco());
}

Aluno *buscar_aluno()
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return resgatarAluno(matricula);
}

void atualizar_aluno(Aluno *aluno)
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return atualizarAluno(aluno);
}

void remover_aluno()
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return excluirAluno(matricula);
}




// PARTE DE OUTPUT DO PROMPT OKAY

void imprimir_aluno(Aluno *aluno)
{
    printf("Matricula: %s", aluno->matricula);
    printf("CPF: %s", aluno->cpf);
    printf("Nome: %s", aluno->nome);
    printf("Endereco: %s, %s, %s, %s, %s\n",
           aluno->endereco->logradouro,
           aluno->endereco->bairro,
           aluno->endereco->cidade,
           aluno->endereco->estado,
           aluno->endereco->numero);
}

void imprimir_professor(Professor *professor)
{
    printf("Matricula: %s", professor->matricula);
    printf("CPF: %s", professor->cpf);
    printf("Nome: %s", professor->nome);
    printf("Endereco: %s, %s, %s, %s, %s\n",
           professor->endereco->logradouro,
           professor->endereco->bairro,
           professor->endereco->cidade,
           professor->endereco->estado,
           professor->endereco->numero);
}

void imprimir_turma(Turma *turma)
{
    printf("Codigo: %s\n", turma->codigo);
    printf("Disciplina: %s\n", turma->disciplina);
    printf("Professor: %s\n", turma->professor_turma);
    printf("Lista de alunos: %s\n", turma->lista_alunos);
    printf("Media da turma: %s\n", turma->media_turma);
}


void imprimir_endereco(Endereco *endereco)
{
    
}

void imprimirProfessoresNaoRelacionados(Turma* turmas, int numTurmas, Professor* professores, int numProfessores) {
    int i, j;
    int professorRelacionado;

    printf("Professores nao relacionados a nenhuma turma:\n");
    for (i = 0; i < numProfessores; i++) {
        professorRelacionado = 0;
        for (j = 0; j < numTurmas; j++) {
            if (strcmp(professores[i].matricula, turmas[j].professor_turma) == 0) {
                professorRelacionado = 1;
                break;
            }
        }
        if (!professorRelacionado) {
            printf("Matricula: %s", professores[i].matricula);
        }
    }
}



void cadastrarTurma() {
    Turma turma;

    printf("Digite o código da turma: ");
    fgets(turma.codigo, sizeof(turma.codigo), stdin);
    turma.codigo[strcspn(turma.codigo, "\n")] = '\0';

    printf("Digite a disciplina: ");
    fgets(turma.disciplina, sizeof(turma.disciplina), stdin);
    turma.disciplina[strcspn(turma.disciplina, "\n")] = '\0';

    printf("Digite o professor da turma: ");
    fgets(turma.professor_turma, sizeof(turma.professor_turma), stdin);
    turma.professor_turma[strcspn(turma.professor_turma, "\n")] = '\0';

    printf("Digite a média da turma: ");
    scanf("%f", &turma.media_turma);
    getchar(); // Limpar o buffer do enter

    printf("Digite a lista de alunos (separados por vírgula): ");
    fgets(turma.lista_alunos, sizeof(turma.lista_alunos), stdin);
    turma.lista_alunos[strcspn(turma.lista_alunos, "\n")] = '\0';

    FILE* arquivo = fopen("db/turma.bin", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escrever a estrutura Turma no arquivo binário
    fwrite(&turma, sizeof(Turma), 1, arquivo);

    fclose(arquivo);

    printf("Turma cadastrada com sucesso.\n");
}

void imprimirTurma(const char* codigo) {
    FILE* arquivo = fopen("db/turma.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Turma turma;

    while (fread(&turma, sizeof(Turma), 1, arquivo) == 1) {
        if (strcmp(turma.codigo, codigo) == 0) {
            printf("Código da Turma: %s\n", turma.codigo);
            printf("Disciplina: %s\n", turma.disciplina);
            printf("Professor: %s\n", turma.professor_turma);
            printf("Lista de Alunos: %s\n", turma.lista_alunos);
            printf("Média da Turma: %.2f\n", turma.media_turma);
            printf("\n");
            break;
        }
    }

    fclose(arquivo);
}