#ifndef aluno_h
#define aluno_h

#define TAM_ALUNO 2

typedef struct aluno {
  char nome[100];
  char sexo;
  int idade; 
  char cpf[100];
  char dataDeNascimento[100];
  int matricula;
  int ativo;
} aluno;

int cadastrarAluno(int qtdAluno, aluno baseDeAlunos[TAM_ALUNO]);
int excluirAluno(aluno baseDeAlunos[TAM_ALUNO], int qtdAluno);
void listarAlunos(aluno baseDeAlunos[TAM_ALUNO], int qtdAluno);

#endif