#include "professor.h"
#include "validadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastrarProfessor(int qtdProfessor, professor baseDeProfessores[]){ 
    int tamanhoTemp =-1;

  
    printf("-----------Cadastrar Professor-----------\n");
    if (qtdProfessor == TAM_PROFESSOR) {
        printf("Lista de professores cheia!\n\n");
    } else {
        printf("Digite o id:\n");
        scanf("%d", &baseDeProfessores[qtdProfessor].matricula);
        getchar();  // Limpa o buffer após scanf
        system("clear");

        if (verificarMatriculaProfessor(baseDeProfessores[qtdProfessor].matricula, qtdProfessor, baseDeProfessores) == -1) {
            printf("Id inválido!\n");
        } else if (verificarMatriculaProfessor(baseDeProfessores[qtdProfessor].matricula, qtdProfessor, baseDeProfessores) == 0){

            ////////////////////////////////////////////////////////////////////////////
            printf("Digite o nome do professor:\n");
            fgets(baseDeProfessores[qtdProfessor].nome, sizeof(baseDeProfessores[qtdProfessor].nome), stdin);
            baseDeProfessores[qtdProfessor].nome[strcspn(baseDeProfessores[qtdProfessor].nome, "\n")] = '\0'; //reitirar o \n
            system("clear");
            tamanhoTemp = strlen(baseDeProfessores[qtdProfessor].nome); //Tamanho do nome
            if(validar_nome(baseDeProfessores[qtdProfessor].nome, tamanhoTemp)==0){
                printf("Nome inválido\n");
                return qtdProfessor;
            }



          ////////////////////////////////////////////////////////////////////////////
            printf("Informe o CPF no formato 000.000.000-00:\n");
            fgets(baseDeProfessores[qtdProfessor].cpf, sizeof(baseDeProfessores[qtdProfessor].cpf), stdin);
            baseDeProfessores[qtdProfessor].cpf[strcspn(baseDeProfessores[qtdProfessor].cpf, "\n")] = '\0';
            system("clear");
            tamanhoTemp = strlen(baseDeProfessores[qtdProfessor].cpf); 
            if(validate_cpf(baseDeProfessores[qtdProfessor].cpf, tamanhoTemp)==0){
                printf("Cpf inválido\n");
                return qtdProfessor;
            }

            // limparBuffer();

          ////////////////////////////////////////////////////////////////////////////
            printf("Informe a data de nascimento no formato dd/mm/aaaa:\n");
            fgets(baseDeProfessores[qtdProfessor].dataDeNascimento, sizeof(baseDeProfessores[qtdProfessor].dataDeNascimento), stdin);
            baseDeProfessores[qtdProfessor].dataDeNascimento[strcspn(baseDeProfessores[qtdProfessor].dataDeNascimento, "\n")] = '\0';
            system("clear");

            int dia, mes, ano;
            tamanhoTemp = strlen(baseDeProfessores[qtdProfessor].dataDeNascimento); 
            if(validadorDeDataDeNascimento(baseDeProfessores[qtdProfessor].dataDeNascimento, tamanhoTemp,  &dia, &mes,&ano)==0){
                printf("data inválida\n");
                return qtdProfessor;
            }


          // limparBuffer();
          ////////////////////////////////////////////////////////////////////////////
            printf("Informe o sexo do professor - f ou m:\n");
            scanf(" %c", &baseDeProfessores[qtdProfessor].sexo);
            getchar();  // Limpa o buffer após leitura do sexo
            system("clear");
            if(validarSexo(baseDeProfessores[qtdProfessor].sexo)==0){
                printf("Sexo inválido\n");
                return qtdProfessor;
            }

          ////////////////////////////////////////////////////////////////////////////

            baseDeProfessores[qtdProfessor].ativo = 1;

          ////////////////////////////////////////////////////////////////////////////

            printf("Professor cadastrado com sucesso!\n\n");
            return qtdProfessor + 1;
        } else {
            printf("Não foi possível realizar o cadastro!\n\n");
            return qtdProfessor;
        }
    }
    return qtdProfessor;
}
//Função buscar a matricula do professor
professor buscarProfessorPorMatricula(int qtdProfessor, professor baseDeProfessores[], int mat){
   professor  p;
   p.matricula = -1;
  
    for(int i=0; i<qtdProfessor; i++){
        if(baseDeProfessores[i].matricula == mat){
            return baseDeProfessores[i];
        }
    }
  return p ;
}

void listarProfessores(professor baseDeProfessores[], int qtdProfessor){
  if(qtdProfessor == 0){
    printf("Lista de professores vazia\n\n");
  } else {
        for (int i = 0; i < qtdProfessor; i++) {
          if(baseDeProfessores[i].ativo == 1){
            printf("Ficha do Professor %d\n", i + 1);
            printf("Matricula: %d\n", baseDeProfessores[i].matricula);
            printf("Nome: %s\n", baseDeProfessores[i].nome);
            printf("Sexo: %c\n", baseDeProfessores[i].sexo);
            printf("CPF : %s\n", baseDeProfessores[i].cpf);
            printf("Data de Nascimento: %s\n", baseDeProfessores[i].dataDeNascimento);
          }
        }
  }
}

int excluirProfessor(professor baseDeProfessores[], int qtdProfessor){
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