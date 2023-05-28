#include "tratadores.h"
#include "./repository/Aluno/AlunoRepository.h"
#include "./repository/Professor/ProfessorRepository.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>

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
            printf("Número máximo de professores atingido\n");
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
    int opcao = menu_crud_aluno();
    // Aluno *aluno = NULL;
    
    // int quantidadeAlunos = obterQuantidadeAlunos();

    // if (quantidadeAlunos != -1)
    // {
    //     printf("Quantidade de alunos armazenados: %d\n", quantidadeAlunos);
    // } else {
    //     printf("Erro no banco");
    // }

    switch (opcao)
    {
    case 1:
        // funcao para o case 1

        // if (quantidadeAlunos >= MAX_ALUNO)
        // {
        //     printf("Número máximo de alunos atingido\n");
        // }
        // else
        // {
        //     salvarAlunoBinario(construir_aluno());
        // }
        // break;
    case 2:
    {
         // funcao para o case 2

        // Aluno *aluno = buscar_aluno();
        // if (aluno == NULL)
        // {
        //     printf("Aluno não encontrado.\n");
        //     return;
        // }

        // printf("Dados do Aluno:\n");
        // imprimir_aluno(aluno);

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

void tratador_menu_estatistica()
{
    int opcao = menu_crud_aluno();
    // Aluno *aluno = NULL;
    
    // int quantidadeAlunos = obterQuantidadeAlunos();

    // if (quantidadeAlunos != -1)
    // {
    //     printf("Quantidade de alunos armazenados: %d\n", quantidadeAlunos);
    // } else {
    //     printf("Erro no banco");
    // }

    switch (opcao)
    {
    case 1:
        // funcao para o case 1

        // if (quantidadeAlunos >= MAX_ALUNO)
        // {
        //     printf("Número máximo de alunos atingido\n");
        // }
        // else
        // {
        //     salvarAlunoBinario(construir_aluno());
        // }
        // break;
    case 2:
    {
         // funcao para o case 2

        // Aluno *aluno = buscar_aluno();
        // if (aluno == NULL)
        // {
        //     printf("Aluno não encontrado.\n");
        //     return;
        // }

        // printf("Dados do Aluno:\n");
        // imprimir_aluno(aluno);

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
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    putchar('\n');

    return excluirProfessorRepository(matricula);
}





// constructors

Professor *construir_professor()
{
    Professor professor;

    printf("Matricula\t> ");
    fgets(professor.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(professor.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 49, stdin);
    
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
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    
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


void imprimir_endereco(Endereco *endereco)
{
    
}