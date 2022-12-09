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
            printf("Finalizando app...\n\n");
        }
    } while (op_menu_principal != 2);
    return 0;
}
