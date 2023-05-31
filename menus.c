#include "menus.h"
#include <stdio.h>

int menu_principal() // Essa função exube o menu principal e solicita ao usuario que selecione uma opcao.
{
    int opcao = 0;
    do
    { //exibe um menu de opções utilizando a função printf para imprimir texto na tela
        printf("== Menu principal==\n\n");
        printf("1 - Menu aluno\n"); 
        printf("2 - Menu professor\n");
        printf("3 - Menu turma\n");                
        printf("4 - Estatistica\n");
        printf("5 - Sair\n");        
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)  
        {
            return opcao;
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}

int menu_crud_aluno() //Essa funcao exibe o menu de operacoes relacionados aos alunos (criar, ler, atualizar, deletar. O usuario seleciona a opcao e a funcao retorna essa opcao.
{
    int opcao = 0;
    do
    { //exibe um menu de opções utilizando a função printf para imprimir texto na tela
        printf("== Menu aluno==\n\n");
        printf("1 - Criar aluno\n");
        printf("2 - Ler aluno\n");
        printf("3 - Atualizar aluno\n");
        printf("4 - Deletar aluno\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}

int menu_crud_professor() //Essa função exibe o menu de operações relacionadas aos professores.
{
    int opcao = 0;
    do
    { //exibe um menu de opções utilizando a função printf para imprimir texto na tela
        printf("== Menu professor==\n\n");
        printf("1 - Criar professor\n");
        printf("2 - Ler professor\n");
        printf("3 - Atualizar professor\n");
        printf("4 - Deletar professor\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}

int menu_crud_turma() // Essa funcao exibe o menu de operações relacionadas as turmas.
{
    int opcao = 0; //declarada uma variável chamada "opcao" do tipo inteiro e é inicializada com o valor 0.
    do
    { //exibe um menu de opções utilizando a função printf para imprimir texto na tela
        printf("== Menu turma==\n\n");
        printf("1 - Criar turma\n");
        printf("2 - Ler turma\n");
        printf("3 - Atualizar turma\n");
        printf("4 - Deletar turma\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao); //função scanf para ler a opcao inserida pelo usuário e armazena na variável "opcao".
        getchar();
        if (opcao > 0 && opcao < 6) //verica a opcao inserida pelo usuario, se é valida ou não.
        {
            return opcao; 
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}

int menu_crud_estatistica() //Essa funcao exibe o menu de operações relacionadas as estatísticas. As opcoes incluem listar nomes de professores, listar matriculas de professores sem turma, calcular a média de todas as turmas.
{
    int opcao = 0;
    do
    { //exibe um menu de opções utilizando a função printf para imprimir texto na tela
        printf("== Menu Estatística==\n\n");
        printf("1 - Listar nome dos Professores\n");
        printf("2 - Listar Matricula dos Professores sem Turma\n");
        printf("3 - Calcular Média de Todas as Turmas\n");
        printf("4- Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 5)
        {
            return opcao;
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}

