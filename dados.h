#ifndef _DADOS_H_
#define _DADOS_H_
/*
Esse código é um arquivo de cabeçalho (header file) chamado "dados.h" que contém a definição das estruturas Endereco, Aluno, Professor e Turma, 
além da declaração de várias funções relacionadas a essas estruturas*/
typedef struct /*Essa parte define a estrutura Endereco, que contém campos para armazenar informações relacionadas a um endereço, como logradouro, bairro, cidade, estado e número.*/
{
    char logradouro[50];//rray de caracteres com tamanho máximo de 50, utilizado para armazenar o nome do logradouro
    char bairro[50]; // array de caracteres com tamanho máximo de 50, utilizado para armazenar o nome do bairro do endereço.
    char cidade[50]; //array de caracteres com tamanho máximo de 50, utilizado para armazenar o nome da cidade do endereço.
    char estado[10]; //array de caracteres com tamanho máximo de 10, utilizado para armazenar a sigla do estado do endereço.
    char numero[10]; //array de caracteres com tamanho máximo de 10, utilizado para armazenar o número do endereço.
} Endereco;//definicao da estrutura Professor utilizando typedef permite criar um novo tipo de dado chamado Professor

typedef struct /*Essa parte define a estrutura Aluno, que contém campos para armazenar informações relacionadas a um aluno, como matrícula, CPF, nome e um ponteiro para a estrutura Endereco, que representa o endereço do aluno.*/
{
    char matricula[20];//array de caracteres com tamanho máximo de 20, utilizado para armazenar a matrícula do aluno.
    char cpf[20]; //array de caracteres com tamanho máximo de 20, utilizado para armazenar o CPF do aluno.
    char nome[50]; //array de caracteres com tamanho máximo de 50, utilizado para armazenar o nome do aluno.
    Endereco *endereco; //ponteiro para a estrutura Endereco, que representa o endereço do aluno. Esse campo permite que cada instância da estrutura 
} Aluno;//A definicao da estrutura Aluno utilizando typedef permite criar um novo tipo de dado chamado Aluno

typedef struct /*Essa parte define a estrutura Professor, que é similar à estrutura Aluno, mas destinada a armazenar informações relacionadas a um professor.*/
{
    char matricula[10];//array de caracteres com tamanho máximo de 10, utilizado para armazenar a matrícula do professor.
    char cpf[12]; //array de caracteres com tamanho máximo de 12, utilizado para armazenar o CPF do professor.
    char nome[50]; //rray de caracteres com tamanho máximo de 50, utilizado para armazenar o nome do professor.
    Endereco *endereco; //ponteiro para a estrutura Endereco, que representa o endereço do professor. 
} Professor; //A definicao da estrutura Professor utilizando typedef permite criar um novo tipo de dado chamado Professor

typedef struct { /*Essa parte define a estrutura Turma, que contém campos para armazenar informações relacionadas a uma turma, como código, disciplina, professor da turma, lista de alunos e média da turma.*/
    char codigo[50]; //array de caracteres com tamanho máximo de 50. Ele é utilizado para armazenar o codigo da turma.
    char disciplina[50];//array de caracteres com tamanho máximo de 50. Ele é utilizado para armazenar o nome da disciplina da turma.
    char professor_turma[50];//array de caracteres com tamanho máximo de 50. Ele é utilizado para armazenar o nome do professor responsável pela turma.
    char lista_alunos[200];//array de caracteres com tamanho máximo de 200. Ele é utilizado para armazenar a lista de alunos matriculados na turma.
    float media_turma;//É um valor de ponto flutuante (float) que representa a média da turma.
} Turma;

Endereco *criarEndereco(char *logradouro, //ponteiro para uma sequência de caracteres (string) que representa o logradouro do endereço.
                        char *bairro, //ponteiro para uma sequência de caracteres (string) que representa o bairro do endereco.
                        char *cidade, //ponteiro para uma sequência de caracteres (string) que representa a cidade do endereco.
                        char *estado, //ponteiro para uma sequência de caracteres (string) que representa o estado do endereco.
                        char *numero); //ponteiro para uma sequência de caracteres (string) que representa o número do endereco.



Aluno *criarAluno(char *matricula, /*Essa linha declara a função criarAluno que cria e retorna um ponteiro para a estrutura Aluno. Ela recebe como parâmetros os valores dos campos do aluno e um ponteiro para a estrutura Endereco.*/
                    //matricula: É um ponteiro para uma sequência de caracteres (string) que representa a matricula do aluno.
                  char *cpf, //ponteiro para uma sequência de caracteres (string) que representa o CPF do aluno.
                  char *nome, //ponteiro para uma sequência de caracteres (string) que representa o nome do aluno.
                  Endereco *end); //ponteiro para a estrutura Endereco que representa o endereço do aluno.

Professor *criarProfessor(char *matricula,/*Essa linha declara a função criarProfessor que cria e retorna um ponteiro para a estrutura Professor.*/
                  char *cpf, //ponteiro para uma sequência de caracteres (string) que representa o CPF do aluno.
                  char *nome, //ponteiro para uma sequência de caracteres (string) que representa o nome do aluno.
                  Endereco *end); //onteiro para a estrutura Endereco que representa o endereço do aluno.

/*Essas linhas declaram as funções destruirAluno e destruirEndereco que recebem ponteiros para as estruturas Aluno e Endereco, respectivamente, e são responsáveis por liberar a memória alocada para essas estruturas.*/
void destruirAluno(Aluno *aluno); 
void destruirEndereco(Endereco *);

#endif /*Essa diretiva indica o final do bloco condicional iniciado pela diretiva #ifndef _DADOS_H_. Ela garante que o conteúdo do arquivo de cabeçalho seja incluído apenas uma vez durante a compilação.*/