#include "dados.h" //Essa linha inclui o arquivo de cabecalho chamado "dados.h" no codigo-fonte atual.
#include <stdlib.h> //Essa linha inclui o arquivo de cabecalho padrao "stdlib.h
#include <string.h> //ssa linha inclui o arquivo de cabecalho padrao "string.h".
#include <stdio.h> //Essa linha inclui o arquivo de cabecalho padrao "stdio.h"

//Função chamada "CriarAluno" que retorna um ponteiro para a estrutura "Aluno" e os parametros 
Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno)); //Essa linha aloca memoria dinamicamente para a estrutura Aluno usando a função malloc
    if (aluno) //Essa linha verifica se a alocacao de memoria foi bem sucedida. Se o ponteiro aluno nao for nulo, significa que a alocação foi bem-sucedida e há memoria disponivel.
    {
        strcpy(aluno->matricula, matricula); // Copia matricula para aluno->matricula
        strcpy(aluno->cpf, cpf);//Copia cpt para aluno->cpr
        strcpy(aluno->nome, nome);//Copia nome para aluno->nome
        aluno->endereco = end;//Essa linha atribui o valor do ponteiro end ao campo endereco da estrutura Aluno
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");//Se a alocacao de memoria falhar, a funaoo perror imprime uma mensagem de erro informando que não há memoria disponivel.
    }
    return aluno;//A função retorna o ponteiro aluno. Se a alocação de memória falhar, o ponteiro será nulo
}
Professor *criarProfessor(char *matricula,//Essa linha aloca memória dinamicamente para a estrutura Professor usando a função malloc
                          char *cpf,
                          char *nome,
                          Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    if (professor)
    {
        strcpy(professor->matricula, matricula);
        strcpy(professor->cpf, cpf);
        strcpy(professor->nome, nome);
        professor->endereco = end;
}
    else
    {
        perror("Não há memória disponível. Encerrando\n\n"); //Se a alocaaoo de memória falhar, a função perror imprime uma mensagem de erro informando que nao ha memória disponivel.
    }
    return professor; //A funcao retorna o ponteiro professor. Se a alocacao de memoria falhar, o ponteiro será nulo.
}

Endereco *criarEndereco(char *logradouro, // Ela indica que a funaoo retorna um ponteiro para Endereco e recebe como parâmetros ponteiros para as variaveis 
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));//Essa linha aloca memória dinamicamente para a estrutura Endereco usando a funaoo malloc
    if (endereco)
    {
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");//Se a alocação de memória falhar, a função perror imprime uma mensagem de erro informando que não há memória disponível.
    }
    return endereco;
}


void destruirAluno(Aluno *aluno) //Essa função recebe um ponteiro para a estrutura Aluno como parâmetro. Ela é responsável por liberar a memória alocada para o aluno e seu endereço.
{
    if (aluno) //Essa linha verifica se o ponteiro aluno não é nulo. Isso é importante para garantir que o ponteiro seja válido antes de acessar seus campos ou liberar memória.
    {
        Endereco *end = aluno->endereco; //Essa linha atribui o valor do campo endereco da estrutura Aluno ao ponteiro end. Isso é feito para ter acesso ao endereço associado ao aluno e liberar sua memória posteriormente.
        destruirEndereco(end); //Essa linha chama a função destruirEndereco, passando o ponteiro end como argumento. Essa função será responsável por liberar a memória alocada para o endereço do aluno.
        free(aluno); //Essa linha libera a memória alocada para a estrutura Aluno usando a função free. Após essa linha, o ponteiro aluno não deve mais ser utilizado.
    }
}

void destruirEndereco(Endereco *endereco)//Essa função recebe um ponteiro para a estrutura Endereco como parâmetro. Ela é responsável por liberar a memória alocada para o endereço.
{
    if (endereco) //Essa linha verifica se o ponteiro endereco não é nulo. Isso é importante para garantir que o ponteiro seja válido antes de liberar memória.
        free(endereco); //Essa linha libera a memória alocada para a estrutura Endereco usando a função free.
}