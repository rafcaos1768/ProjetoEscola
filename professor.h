#ifndef professor_h
#define professor_h

#define TAM_PROFESSOR 2

typedef struct professor {
  char nome[100];
  char sexo;
  int idade; 
  char cpf[100];
  char dataDeNascimento[100];
  int matricula;
  int ativo;
} professor;

int cadastrarProfessor(int qtdProfessor, professor baseDeProfessores[TAM_PROFESSOR]);
void listarProfessores(professor baseDeProfessores[TAM_PROFESSOR], int qtdProfessor);
int excluirProfessor(professor baseDeProfessores[TAM_PROFESSOR], int qtdProfessor);
professor buscarProfessorPorMatricula(int qtdProfessor, professor baseDeProfessores[], int mat);

#endif