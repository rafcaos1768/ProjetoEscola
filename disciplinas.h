#ifndef disciplinas_h
#define disciplinas_h
#include "professor.h"

#define TAM_DISCIPLINA 2

typedef struct disciplina{
  char nome[100];
  int codigo;
  int semestre;
  int matProfessor;
  char nomeProfessor[100];
  int ativo; 
} disciplina;

int cadastrarDisciplina(disciplina baseDeDisciplinas[TAM_DISCIPLINA], int qtdDisciplina, int qtdProfessor, professor baseDeProfessores[]);

#endif