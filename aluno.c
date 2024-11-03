#include "aluno.h"
#include "validadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cadastrarAluno(int qtdAluno, aluno baseDeAlunos[]) { 
   int tamanhoTemp =-1; //incializacao da variavel de tamanho das strings 

  
    printf("-----------Cadastrar Aluno-----------\n");
    if (qtdAluno == TAM_ALUNO) {
        printf("Lista de alunos cheia!\n\n");
    } else {
        printf("Digite a matrícula:\n");
        scanf("%d", &baseDeAlunos[qtdAluno].matricula);
        getchar();  // Limpa o buffer após scanf
        system("clear");

        if (verificarMatriculaAluno(baseDeAlunos[qtdAluno].matricula, qtdAluno, baseDeAlunos) == -1) { //verificar se a matricula segue os padroes
            printf("Matrícula inválida\n");
           return qtdAluno;
        } else if (verificarMatriculaAluno(baseDeAlunos[qtdAluno].matricula, qtdAluno, baseDeAlunos) == 0) {
          
           ////////////////////////////////////////////////////////////////////////////
            printf("Digite o nome do aluno:\n");
            fgets(baseDeAlunos[qtdAluno].nome, sizeof(baseDeAlunos[qtdAluno].nome), stdin);
            baseDeAlunos[qtdAluno].nome[strcspn(baseDeAlunos[qtdAluno].nome, "\n")] = '\0'; //retirar o \n
            system("clear");
            tamanhoTemp = strlen(baseDeAlunos[qtdAluno].nome); //Tamanho do nome
            if(validar_nome(baseDeAlunos[qtdAluno].nome, tamanhoTemp)==0){
                printf("Nome inválido\n");
                return qtdAluno;
            }
            

            // limparBuffer();
            ////////////////////////////////////////////////////////////////////////////
            printf("Informe o CPF no formato 000.000.000-00:\n");
            fgets(baseDeAlunos[qtdAluno].cpf, sizeof(baseDeAlunos[qtdAluno].cpf), stdin);
            baseDeAlunos[qtdAluno].cpf[strcspn(baseDeAlunos[qtdAluno].cpf, "\n")] = '\0';
            system("clear");
            tamanhoTemp = strlen(baseDeAlunos[qtdAluno].cpf); 
            if(validate_cpf(baseDeAlunos[qtdAluno].cpf, tamanhoTemp)==0){
                printf("Cpf inválido\n");
                return qtdAluno;
            }
              
            // limparBuffer();
            ////////////////////////////////////////////////////////////////////////////
            printf("Informe a data de nascimento no formato dd/mm/aaaa:\n");
            fgets(baseDeAlunos[qtdAluno].dataDeNascimento, sizeof(baseDeAlunos[qtdAluno].dataDeNascimento), stdin);
            baseDeAlunos[qtdAluno].dataDeNascimento[strcspn(baseDeAlunos[qtdAluno].dataDeNascimento, "\n")] = '\0';
            system("clear");
           int dia, mes, ano;
            tamanhoTemp = strlen(baseDeAlunos[qtdAluno].dataDeNascimento); 
            if(validadorDeDataDeNascimento(baseDeAlunos[qtdAluno].dataDeNascimento, tamanhoTemp,  &dia, &mes,&ano)==0){
                printf("data inválida\n");
                return qtdAluno;
            }

          
            // limparBuffer();
            ////////////////////////////////////////////////////////////////////////////
            printf("Informe o sexo do estudante - F ou M:\n");
            scanf(" %c", &baseDeAlunos[qtdAluno].sexo);
            getchar();  // Limpa o buffer após leitura do sexo
            system("clear");
            if(validarSexo(baseDeAlunos[qtdAluno].sexo)==0){
                printf("Sexo inválido\n");
                return qtdAluno;
            }
          // limparBuffer();
          ////////////////////////////////////////////////////////////////////////////
          
            baseDeAlunos[qtdAluno].ativo = 1; //Operador logico de atividade 

           ////////////////////////////////////////////////////////////////////////////
            printf("Aluno cadastrado com sucesso!\n\n");
            return qtdAluno + 1; //cadastrado
        } else {
            printf("Não foi possível realizar o cadastro!\n\n");
            return qtdAluno; //retorna ao numero atual 
        }
    }
    return qtdAluno; // retorna ao numero atual 
}

void listarAlunos(aluno baseDeAlunos[TAM_ALUNO], int qtdAluno){
  if(qtdAluno == 0){
    printf("Lista de alunos vazia\n\n");
  } else {
        for (int i = 0; i < qtdAluno; i++) {
          if(baseDeAlunos[i].ativo == 1){
            printf("\nFicha do Aluno %d\n", i + 1);
            printf("Matricula: %d\n", baseDeAlunos[i].matricula);
            printf("Nome: %s\n", baseDeAlunos[i].nome);
            printf("Sexo: %c\n", baseDeAlunos[i].sexo);
            printf("CPF : %s\n", baseDeAlunos[i].cpf);
            printf("Data de Nascimento: %s\n", baseDeAlunos[i].dataDeNascimento);
          }
        }
  }
}

int excluirAluno(aluno baseDeAlunos[TAM_ALUNO], int qtdAluno){
  if(qtdAluno == 0){
    printf("Lista de alunos vazia\n\n");
  } else {
    printf("Digite a matrícula:\n");
    int matAluno;
    scanf("%d", &matAluno);
    system("clear");
    int achou = 0;
    if(verificarMatriculaAluno(matAluno, qtdAluno, baseDeAlunos) == -1){
      printf("Matrícula inválida!\n");
    } else{
      for(int i = 0; i < qtdAluno; i++){
        if(matAluno == baseDeAlunos[i].matricula){
          achou = 1;
          for(int j = i; j < qtdAluno - 1; j++){
            baseDeAlunos[j] = baseDeAlunos[j + 1];
          }
          qtdAluno--;
          printf("Aluno excluído com sucesso!\n\n");
          break;
        }
      }
      if(!achou){
        printf("Matrícula inexistente!\n\n");
      }
      return qtdAluno;
    }
  }
  return qtdAluno;
}