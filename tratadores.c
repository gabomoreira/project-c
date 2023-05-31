/*Inclui arquivos de cabeçalho necessários para a compilação do programa*/
#include "tratadores.h"
#include "./repository/Aluno/AlunoRepository.h"
#include "./repository/Professor/ProfessorRepository.h"
#include "./repository/Turma/TurmaRepository.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>
#include <stdlib.h>


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
        
        char matricula[10];

        printf("Digite a matrícula do aluno a ser excluído: ");
        fgets(matricula, sizeof(matricula), stdin);
        matricula[strcspn(matricula, "\n")] = '\0';

        verificarMatricula(matricula);

        excluirAluno(matricula);
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}


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
            salvarProfessorRepository(construir_professor());
        }
        break;
    case 2:
    {   
        Professor *professor = resgatarProfessorRepository();
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
        atualizarProfessorRepository(construir_professor());
    }

    break;
    case 4:
    {
        excluirProfessorRepository();
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_turma() // opções do menu relacionadas a turma
{
    int opcao = menu_crud_turma(); // exibe um menu específico para as operações de criação, leitura, atualização e exclusão de turmas
    Turma *turma = NULL;//inicializa um ponteiro turma para NULL
    
    int quantidadeTurmas = obterQuantidadeTurmasRepository(); //essa linha chama a função obterQuantidadeTurmasRepository

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

        if (quantidadeTurmas >= MAX_TURMA) //verificado se a quantidade de turmas atingiu o limite maximo 
        {
             printf("Número máximo de turmas atingido\n");
         }
         else
         {
            cadastrarTurma();
         }
         break;
    case 2:
    {
       exibirTurmas(); //chamada para mostrar as turmas existentes.

    }
    break;
    case 3: //chamada para permitir a atualizacao de uma turma existente.
    {
        atualizarTurma();
    }

    break;
    case 4:
    {
        excluirTurma(); // chamada para permitir a exclusao de uma turma existente.
    }

    break;
    default: //exibida uma mensagem informando que o usuario esta retornando ao menu principal.
        printf("Retornando ao menu principal\n");
        break;
    }
}

// Função que lida com o menu estatística 
void tratador_menu_estatistica()

{   // Criação do menu de estatística 
    int opcao = menu_crud_estatistica();

    // Estrutura switch para menu Estatística
    switch (opcao)
    {
    case 1:
    {   // Chamada da função para listar nomes de professores
        listarNomesProfessores();
    }
    break;

    case 2:
    {   //  Chamada da função para listar professores sem turma
       printAllTeachesNoClass();
    }
    break;
    case 3:
    {   // Cálculo da média das turmas
        calcularMediaTurmas();
    }
    break;
    case 4:
    {

    }
    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

//  Função que imprime os professores não vinculados a nenhuma turma
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

// Função para construir professor 

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

// Função para construir endereço
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

// Função para construir aluno
Aluno *construir_aluno()
{
    Aluno aluno;

    printf("Matricula\t> ");
    fgets(aluno.matricula, 20, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 20, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 50, stdin);
    
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, construir_endereco());
}

// Função para buscar aluno 
Aluno *buscar_aluno() 
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return resgatarAluno(matricula);
}

// Função para atualizar aluno 
void atualizar_aluno(Aluno *aluno)
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return atualizarAluno(aluno);
}


// Funções de impressão  de aluno
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

// Funções de impressão  de professor
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

// Funções de impressão  de endereço
void imprimir_endereco(Endereco *endereco)
{
    }

// Funções de impressão  não relacionados a nenhuma turma
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

