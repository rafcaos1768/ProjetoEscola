// usar verbos para declarar variaveis.
//Seguir Formatacao de variaveis ex: listarAluno, mostrarCadastro.

#include <stdlib.h> 
#include <string.h>
#include <stdio.h> 
#include "aluno.h"
#include "validadores.h"
#include "professor.h"
#include "disciplinas.h"

int main(void){
  system("clear");
  
  aluno baseDeAlunos[TAM_ALUNO];
  professor baseDeProfessores[TAM_PROFESSOR];
  disciplina baseDeDisciplinas[TAM_DISCIPLINA];
  int opcao; 
  int sair= 0; 
  int qtdAluno =0; 
  int qtdProfessor =0; 
  int qtdDisciplina=0; 

  while(sair == 0){ 
    printf("-----------Projeto Escola-----------\n");
    printf("0- Sair\n");
    printf("1- Aluno\n");
    printf("2- Professor\n"); 
    printf("3- Discplina\n"); 
    printf("Digite sua opção: \n");
    scanf("%d", &opcao); 
    system("clear");

    switch (opcao){
      case 0: {
        sair=-1; 
        break;
      }
      case 1: {
        int cadastrarResultado=-1;
        int sairAluno=0;
        int opcaoAluno; 
        while(sairAluno==0){ 
        
          printf("-----------Modulo aluno-----------\n");
          printf("0- Voltar\n");
          printf("1- Cadastrar Aluno\n");
          printf("2- Excluir Aluno\n"); 
          printf("3- Atualizar Cadastro\n");
          printf("4- Listar Alunos\n");
          printf("Digite sua opção: \n");
          scanf("%d", &opcaoAluno);
          system("clear");
          
          switch(opcaoAluno){          
            case 0 :{
              sairAluno = -1; 
              break;
            }
            case 1 :{
              qtdAluno = cadastrarAluno(qtdAluno, baseDeAlunos);
              break;
            }
            case 2 :{
              qtdAluno = excluirAluno(baseDeAlunos, qtdAluno);              
              break;
            }
            case 3 :{
              printf("Atualizar Cadastro\n");
              break;
            }
            case 4 :{
              printf("-----------Lista de Alunos-----------\n");
              listarAlunos(baseDeAlunos,qtdAluno);
              break;
            } 
            default: {
              printf("Opcao Invalida\n");
              break;
            }
          }
          
        }
        break;
      }
      case 2: {
        int sairProfesor=0;
        int opcaoProfessor; 
        while(sairProfesor==0){ 

          printf("-----------Modulo Professor-----------\n");
          printf("0- Voltar\n");
          printf("1- Cadastrar Professor\n");
          printf("2- Excluir Professor\n"); 
          printf("3- Atualizar Cadastro\n");
          printf("4- Listar Professor\n");
          scanf("%d", &opcaoProfessor);
          system("clear");

          switch(opcaoProfessor){

            case 0 :{
                sairProfesor = -1; 
              break;
            }
            case 1 :{
              qtdProfessor = cadastrarProfessor(qtdProfessor, baseDeProfessores);
              break;
            }
            case 2 :{
              qtdProfessor = excluirProfessor(baseDeProfessores, qtdProfessor); 
              break;
            }
            case 3 :{
              printf("Atualizar Cadastro\n");
              break;
            }
            case 4 :{
              printf("-----------Lista de Professores-----------\n");
              listarProfessores(baseDeProfessores, qtdProfessor);
              break;
            } 
            default: {
              printf("Opcao Invalida\n");
              break;
            }
          }

        }
        break;
      }
      case 3: {
      
        int sairDisciplina=0;
        int opcaoDisciplina; 
        while(sairDisciplina==0){ 

          printf("-----------Modulo Disciplina-----------\n");
          printf("0- Voltar\n");
          printf("1- Cadastrar Disciplina\n");
          printf("2- Excluir Disciplina\n"); 
          printf("3- Atualizar Disciplina\n");
          printf("4- Listar Disciplina\n");
          scanf("%d", &opcaoDisciplina);
          system("clear");

          switch(opcaoDisciplina){

            case 0 :{
                sairDisciplina = -1; 
              break;
            }
            case 1 :{
               qtdDisciplina = cadastrarDisciplina(baseDeDisciplinas, qtdDisciplina, qtdProfessor, baseDeProfessores);
              break;
            }
            case 2 :{
              printf("-----------Excluir Disciplina-----------\n"); 
              break;
            }
            case 3 :{
              printf("-----------Atualizar Disciplina-----------\n");
              break;
            }
            case 4 :{
              printf("-----------Listar Disciplina-----------\n");
              break;
            } 
            default: {
              printf("Opcao Invalida\n");
              break;
            }
          }

        }
        break;

      }
      default:{
        printf("Opcao invalida\n");
      }
    }
  }
  return 0; 
}
