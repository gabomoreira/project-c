/*Essas linhas incluem os arquivos de cabeçalho necessários para o programa. Os arquivos "menus.h", "tratadores.h" e "dados.h" contêm as declarações de funções e estruturas utilizadas no programa. O arquivo "stdio.h" é necessário para utilizar funções de entrada e saída padrão, como printf. O arquivo "constantes.h" define constantes utilizadas no programa.*/
#include "menus.h"
#include "tratadores.h"
#include "dados.h"
#include <stdio.h>
#include "constantes.h"

int main(int argc, char const *argv[]) /*Essa é a função principal do programa, onde a execução do programa começa. Ela recebe os argumentos da linha de comando, mas nesse caso, não os utiliza.*/
{
    int op_menu_principal = 0;
    Aluno *alunos[MAX_ALUNO] = {NULL}; // cria um array alunos para a estrutura Aluno e inicializa com ponteiros nulos
    Professor *professores[MAX_PROFESSOR] = {NULL}; // cria um array professores para a estrutura Professor e inicializa com ponteiros nulos
    Turma *turmas[MAX_TURMA] = {NULL}; // cria um array turmas para a estrutura Turma e inicializa com ponteiros nulos
    /*Essas linhas declaram três variáveis inteiras (qtd_atual_aluno, qtd_atual_professor e qtd_atual_turma) e as inicializam com o valor 0. Essas variáveis serão usadas para armazenar a quantidade atual de alunos, professores e turmas, respectivamente.*/
    int qtd_atual_aluno = 0;
    int qtd_atual_professor = 0;
    int qtd_atual_turma = 0;

    do /*Essa é uma estrutura de repetição do-while que executa um bloco de código enquanto a variável op_menu_principal for diferente de 5. */
    {
        op_menu_principal = menu_principal();
        switch (op_menu_principal) // retorna a opção selecionada pelo usuário no menu principal. O valor retornado é atribuído à variável op_menu_principal.
        {
        case 1:
            tratador_menu_aluno(alunos, &qtd_atual_aluno); /*Chama a funcao tratador_menu_aluno passando os arrays de alunos e a referencia para a variavel qtd_atual_aluno.
             * Essa função trata as opções relacionadas a alunos no menu e realiza as operações correspondentes. */
            break;

            break;
        case 2:
            tratador_menu_professor(professores, &qtd_atual_professor); /*Chama a funcao tratador_menu_professor passando os arrays de professores e a referencia para a variável qtd_atual_professor.
             * Essa funcaoo trata as opções relacionadas a professores no menu e realiza as operaoses correspondentes. */
            break;
        case 3:
            tratador_menu_turma(turmas, &qtd_atual_turma); /*/* Chama a funcao tratador_menu_turma passando os arrays de turmas e a referência para a variável qtd_atual_turma.
             * Essa função trata as opções relacionadas a turmas no menu e realiza as operações correspondentes. */
            break;                        
        case 4:
            tratador_menu_estatistica(); /*Chama a função tratador_menu_estatistica.
             * Essa função trata a opção relacionada a estatísticas no menu e realiza as operações correspondentes. */
            break;        
        case 5:
            printf("Finalizando app...\n\n"); /*Exibe uma mensagem indicando que o aplicativo está sendo finalizado. */
        }

    } while (op_menu_principal != 5);
    return 0;
}
