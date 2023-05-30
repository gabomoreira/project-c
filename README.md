# Projeto de C

> Este repositório contém o código para a resolução do projeto de C realizado no curso de graduação em Sistemas de Informação do Instituto Federal de Alagoas, com o objetivo de obtenção da nota parcial para a disciplina de Linguagem de Programação solicitado pelo professor Ivo Calado.

## 📋 Detalhes do Projeto

- Menu de aluno com opções de:

  - Criação de aluno
  - Busca de aluno
  - Deleção de aluno
  - Atualização de um aluno

- Menu de Professor com opções de:

  - Criação de professor
  - Busca de professor
  - Deleção de professor
  - Atualização de um professor

- Menu de turma com opções de:

  - Criação de turma
  - Busca de turma
  - Deleção de turma
  - Atualização de um turma

- Menu de Estatística com opções de:

  - Imprimir nome dos professores
  - Imprimir matrículas dos professores que não estão em nenhuma turma
  - Calcular nota média de todas as turmas

- Persistência de dados da aplicação utilizando arquivos binários

### Restrições

- O sistema não deve permitir a inserção de dois alunos com matrículas ouo cpf iguais
- O sistema não deve permitir a inserção de dois professores com matrículas ouo cpf iguais
- O sistema não deve permitir a inserção de duas turmas com códigos iguais
- O sistema não deve permitir que um aluno seja deletado caso esteja associado a alguma turma
- O sistema não deve permitir que um professor seja deletado caso ele esteja associado a uma turma

## ⚙️ Rodando o código

- É necesário ter instalado em sua máquina o compilador gcc, caso não possua acesse o link abaixo para assitir um tutorial de como instalá-lo.
  [![tutorial](https://img.shields.io/badge/tutorial_instalar_gcc-000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/watch?v=RJ4ta9mjrWc)

* Faça uma clone deste repositório, inserindo em seu terminal o código abaixo:

```bash
git clone https://github.com/gabomoreira/project-c
```

- Após isso, compile o código inserindo no terminal o seguinte comando:

```bash
gcc dados.c main.c menus.c tratadores.c ./repository/Aluno/AlunoRepository.c ./repository/Professor/ProfessorRepository.c ./repository/Turma/TurmaRepository.c -o c
```

- Agora é só executar o programa com o comando abaixo:

```bash
./c
```

## 🤝 Colaboradores

> Agradecemos às seguintes pessoas que contribuíram para este projeto:

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Analarie">
        <img src="https://github.com/Analarie.png" width="100px;" alt="Foto de perfil da Ana Larissa Dos Santos Gomes Da Silva no GitHub"/><br>
        <sub>
          <b>Ana Larissa Dos Santos Gomes Da Silva</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/gabomoreira">
        <img src="https://github.com/gabomoreira.png" width="100px;" alt="Foto de perfil do Gabriel dos Santos Moreira no GitHub"/><br>
        <sub>
          <b>Gabriel dos Santos Moreira</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/robertoferreira7">
        <img src="https://github.com/robertoferreira7.png" width="100px;" alt="Foto de perfil do Roberto Ferreira de Assis Filho no GitHub"/><br>
        <sub>
          <b>Roberto Ferreira de Assis Filho</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/rodrigo-farias10">
        <img src="https://github.com/rodrigo-farias10.png" width="100px;" alt="Foto de perfil do Rodrigo de Oliveira Farias no GitHub"/><br>
        <sub>
          <b>Rodrigo de Oliveira Farias</b>
        </sub>
      </a>
    </td>
  </tr>
</table>
