#include "menus.h"
#include "tratadores.h"
#include "dados.h"
#include <stdio.h>
#include "constantes.h"

int main(int argc, char const *argv[])
{
    int op_menu_principal = 0;
    Aluno *alunos[MAX_ALUNO] = {NULL};

    int qtd_atual_aluno = 0;

    do
    {
        op_menu_principal = menu_principal();
        switch (op_menu_principal)
        {
        case 1:
            tratador_menu_aluno(alunos, &qtd_atual_aluno);
            break;
        case 2:
            menu_crud_professor();
            break;
        case 3:
            menu_crud_turma();
            break;
        case 4:
            menu_crud_estatistica();
            break;
        case 5:
            printf("Finalizando o programa...\n\n");
        }
    } while (op_menu_principal != 5);
    return 0;
}