#include "menus.h"
#include "tratadores.h"
#include "dados.h"
#include <stdio.h>
#include "constantes.h"

int main(int argc, char const *argv[])
{
    int op_menu_principal = 0;
    Aluno *alunos[MAX_ALUNO] = {NULL}; // cria um array alunos para a estrutura Aluno e inicializa com ponteiros nulos
    Professor *professores[MAX_PROFESSOR] = {NULL}; // cria um array professores para a estrutura Professor e inicializa com ponteiros nulos
    Turma *turmas[MAX_TURMA] = {NULL}; // cria um array turmas para a estrutura Turma e inicializa com ponteiros nulos
    
    int qtd_atual_aluno = 0;
    int qtd_atual_professor = 0;
    int qtd_atual_turma = 0;

    do
    {
        op_menu_principal = menu_principal();
        switch (op_menu_principal)
        {
        case 1:
            tratador_menu_aluno(alunos, &qtd_atual_aluno);
            break;
        case 2:
            tratador_menu_professor(professores, &qtd_atual_professor);
            break;
        case 3:
            tratador_menu_turma(turmas, &qtd_atual_turma);
            break;                        
        case 4:
            tratador_menu_estatistica();
            break;        
        case 5:
            printf("Finalizando app...\n\n");
        }

    } while (op_menu_principal != 5);
    return 0;
}
