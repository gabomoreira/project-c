#ifndef _DADOS_H_
#define _DADOS_H_
/*
Esse código é um arquivo de cabeçalho (header file) chamado "dados.h" que contém a definição das estruturas Endereco, Aluno, Professor e Turma, 
além da declaração de várias funções relacionadas a essas estruturas*/
typedef struct /*Essa parte define a estrutura Endereco, que contém campos para armazenar informações relacionadas a um endereço, como logradouro, bairro, cidade, estado e número.*/
{
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco;

typedef struct /*Essa parte define a estrutura Aluno, que contém campos para armazenar informações relacionadas a um aluno, como matrícula, CPF, nome e um ponteiro para a estrutura Endereco, que representa o endereço do aluno.*/
{
    char matricula[20];
    char cpf[20];
    char nome[50];
    Endereco *endereco;
} Aluno;

typedef struct /*Essa parte define a estrutura Professor, que é similar à estrutura Aluno, mas destinada a armazenar informações relacionadas a um professor.*/
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;
} Professor;

typedef struct { /*Essa parte define a estrutura Turma, que contém campos para armazenar informações relacionadas a uma turma, como código, disciplina, professor da turma, lista de alunos e média da turma.*/
    char codigo[50];
    char disciplina[50];
    char professor_turma[50];
    char lista_alunos[200];
    float media_turma;
} Turma;

Endereco *criarEndereco(char *logradouro, /*Essa linha declara a função criarEndereco que cria e retorna um ponteiro para a estrutura Endereco. Ela recebe como parâmetros os valores dos campos do endereço.*/
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero);

Aluno *criarAluno(char *matricula, /*Essa linha declara a função criarAluno que cria e retorna um ponteiro para a estrutura Aluno. Ela recebe como parâmetros os valores dos campos do aluno e um ponteiro para a estrutura Endereco.*/
                  char *cpf,
                  char *nome,
                  Endereco *end);

Professor *criarProfessor(char *matricula,/*Essa linha declara a função criarProfessor que cria e retorna um ponteiro para a estrutura Professor. Ela recebe como parâmetros os valores dos campos do professor e um ponteiro para a estrutura Endereco.*/
                  char *cpf,
                  char *nome,
                  Endereco *end);

/*Essas linhas declaram as funções destruirAluno e destruirEndereco que recebem ponteiros para as estruturas Aluno e Endereco, respectivamente, e são responsáveis por liberar a memória alocada para essas estruturas.*/
void destruirAluno(Aluno *aluno); 
void destruirEndereco(Endereco *);

#endif /*Essa diretiva indica o final do bloco condicional iniciado pela diretiva #ifndef _DADOS_H_. Ela garante que o conteúdo do arquivo de cabeçalho seja incluído apenas uma vez durante a compilação.*/