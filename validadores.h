#ifndef validadores_h
#define validadores_h
#include "aluno.h"
#include "professor.h"


int validate_cpf(char CPF[100], int size);
int verificarMatriculaAluno(int matricula, int qtdAluno, aluno baseDeDados[]);
int verificarMatriculaProfessor(int matricula, int qtdAluno, professor baseDeDados[]);
int validar_nome(char name[100], int size_name);
int validarSexo(char sexo);
void limparBuffer();
int validarLogica(int *dia, int *mes, int *ano);
int validadorDeDataDeNascimento(char dataDeNascimento[], int size, int* dia, int* mes,int *ano);

#endif 