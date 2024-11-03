#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"
#include "aluno.h"
#include "validadores.h"
#include "disciplinas.h"

int cadastrarDisciplina(disciplina baseDeDisciplinas[], int qtdDisciplina, int qtdProfessor, professor baseDeProfessores[]) {
    printf("-----------Cadastrar Disciplina-----------\n");
    if (qtdDisciplina == TAM_DISCIPLINA) {
        printf("Lista de disciplinas cheia!\n\n");
    } else {
        printf("Digite o código da disciplina:\n");
        int cod;
        scanf("%d", &baseDeDisciplinas[qtdDisciplina].codigo);
        getchar();  // Limpa o buffer após scanf
        system("clear");

        if(baseDeDisciplinas[qtdDisciplina].codigo < 0){
            printf("Código inválido!\n\n");
            return qtdDisciplina;
        } else {
            printf("Digite o nome da disciplina:\n");
            fgets(baseDeDisciplinas[qtdDisciplina].nome, sizeof(baseDeDisciplinas[qtdDisciplina].nome ), stdin);
            baseDeDisciplinas[qtdDisciplina].nome [strcspn(baseDeDisciplinas[qtdDisciplina].nome, "\n")] = '\0'; //retirar o \n
            system("clear");

            printf("Informe o semestre dessa disciplina:\n");
            scanf("%d", &baseDeDisciplinas[qtdDisciplina].semestre);
            getchar();
            system("clear");

            printf("Informe a matrícula do professor da disciplina:\n");
            scanf("%d", &baseDeDisciplinas[qtdDisciplina].matProfessor);
            getchar();
            system("clear");

            professor prof = buscarProfessorPorMatricula(qtdProfessor, baseDeProfessores, baseDeDisciplinas[qtdDisciplina].matProfessor);
            if (prof.matricula == baseDeDisciplinas[qtdDisciplina].matProfessor){
                printf("Disciplina Cadastrada com suscesso!\n\n");
                strcpy(baseDeDisciplinas[qtdDisciplina].nomeProfessor, prof.nome);
                return qtdDisciplina + 1;
            } else {
                printf("Professor não encontrado!\n\n");
                return qtdDisciplina;
            }
        }   
    }
    return qtdDisciplina;
 }

        int excluirDisciplina(professor baseDeDisciplina[], int qtdProfessor){
          if(qtdProfessor == 0){
            printf("Lista de professores vazia\n\n");
          } else {
            printf("Digite o Id:\n");
            int idProf;
            scanf("%d", &idProf);
            system("clear");
            int achou = 0;
            if(verificarMatriculaProfessor(idProf, qtdProfessor, baseDeProfessores) == -1){
              printf("Id inválido!\n");
            } else{
              for(int i = 0; i < qtdProfessor; i++){
                if(idProf == baseDeProfessores[i].matricula){
                  achou = 1;
                  for(int j = i; j < qtdProfessor - 1; j++){
                    baseDeProfessores[j] = baseDeProfessores[j + 1];
                  }
                  qtdProfessor--;
                  printf("Professor excluído com sucesso!\n\n");
                  break;
                }
              }
              if(!achou){
                printf("Id inexistente!\n\n");
              }
              return qtdProfessor;
            }
          }
          return qtdProfessor;
        }
