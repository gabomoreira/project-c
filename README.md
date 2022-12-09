# exemplo-app-c

## O que a aplicação já implementa?
* Menu inicial com opção de aluno
* Menu de aluno com opções de:
  * Criação de aluno
  * Busca de aluno
  * Deleção de aluno
## Próximos passos
* Implementar a atualização de um aluno
* Criar modelo de dados de Professor e Turmas
* Implementar menus de Professor e Turma para realização das operações de CRUD (Criação, recuperação, atualização e deleção)
* Adicionar um menu denominado "Estatística" no menu principal com as seguintes opções:
    * Imprimir nome dos professores
    * Imprimir matrículas dos professores que não estão em nenhuma turma
    * Calcular nota média de todas as turmas

### Restrições
* O sistema não deve permitir a inserção de dois alunos com matrículas ouo cpf iguais
* O sistema não deve permitir a inserção de dois professores com matrículas ouo cpf iguais
* O sistema não deve permitir a inserção de duas turmas com códigos iguais
* O sistema não deve permitir que um aluno seja deletado caso esteja associado a alguma turma
* O sistema não deve permitir que um professor seja deletado caso ele esteja associado a uma turma





## Modelos de dados

```
Professor:
  * matricula
  * nome
  * cpf
  * endereco

Turma:
  * codigo
  * nome_disciplina
  * professor
  * lista_alunos
  * media_turma
```

## Sobre a entrega
* Grupos de 3 alunos
* Data de entrega: 22/12
* Forma de entrega: apresentação em sala
