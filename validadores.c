#include <stdio.h> 
#include <stdlib.h>
#include "aluno.h"
#include "professor.h"

int verificarMatriculaAluno(int matricula, int qtdPessoa, aluno baseDeDados[]){
  if(matricula < 0){
    return -1; //matricula invalida
    }

    for(int i =0; i < qtdPessoa; i++){
        if(matricula == baseDeDados[i].matricula){
            return -1; // MATRICULA IGUAL 
        }
    }
    
    return 0;
} 

int verificarMatriculaProfessor(int matricula, int qtdPessoa, professor baseDeDados[]){
  if(matricula < 0){
    return -1; //matricula invalida
    }

    for(int i =0; i < qtdPessoa; i++){
        if(matricula == baseDeDados[i].matricula){
            return -1; // MATRICULA IGUAL 
        }
    }

    return 0;
} 



int validate_cpf(char CPF[], int size){

    if (size != 14) {
        return 0 ; // false
    }

    for(int i=0; i<size; i++){

        if(i==3){
            if ( CPF[i] != '.'){
            return 0; //noa eh necessario break pois o return ja encerra a funcao 
            }
        } 
        else if (i==7){
           if ( CPF[i] != '.'){
            return 0; 
           }
        } 
        else if (i==11){
            if (CPF[i] != '-'){
            return 0;
            }
        } 
        else if (CPF[i] < '0' || CPF[i] > '9') {
            return 0;
        }



    }
    return 1;
}


int validar_nome(char name[], int size_name){

    for(int i=0; i< size_name; i++){ 


        if(name[i] < 'A' || name[i] >'Z'){ //Verifica se o caracter nao eh maisculo 
            if(name[i] < 'a' || name[i] >'z'){ //verifica se o caracter nao eh minusculo
                if(name [i] != ' '){  //verifica se  nao eh espaco 
                    return 0; // Caso nao seja nada do que eu quero, entao esta errado !
                }

            } 


        } 
        // else if(name[i] < '' || name[i] >'Z')

    }

    return 1;
}


int validarSexo(char sexo){
    if (sexo != 'f' && sexo != 'F' && sexo != 'm' && sexo != 'M') {
        return 0;
    }
    return 1;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validarLogica(int *dia, int *mes, int *ano){
    int ano1 = *ano; // passando o valor para o qual ano aponta para a variavel ano1
    int mes1= *mes;
    int dia1= *dia;

   // Verificar datas irreais
    if (ano1 > 2024 || ano1 < 1900 || mes1 < 1 || mes1 > 12 || dia1 < 1 || dia1 > 31) {
        return 0;
    }

    // Verificar o mês de fevereiro considerando ano bissexto e não bissexto
    if (mes1 == 2) {
        int bissexto = (ano1 % 4 == 0 && (ano1 % 100 != 0 || ano1 % 400 == 0));
        if ((bissexto && dia1 > 29) || (!bissexto && dia1 > 28)) {
            return 0;
        }
    }

    // Verificar meses com 30 dias (abril, junho, setembro e novembro)
    if ((mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11) && dia1 > 30) {
        return 0;
    }

    // Se todas as condições forem satisfeitas, a data é válida
    return 1;
}


int validadorDeDataDeNascimento(char dataDeNascimento[], int size, int* dia, int* mes,int *ano){

    if(size > 10){
        return 0;
    }

    for(int i=0; i<size; i++){

        if (i == 2 || i == 5) {  // Verifica se o 3º e 6º caracteres são '/'
            if (dataDeNascimento[i] != '/') {
                return 0;
            }
        } else {  // Verifica se os outros caracteres são dígitos
            if (dataDeNascimento[i] < '0' || dataDeNascimento[i] > '9') {
                return 0;
            }
        }
    }


    char diaStr[3] = { dataDeNascimento[0], dataDeNascimento[1], '\0' };
    char mesStr[3] = { dataDeNascimento[3], dataDeNascimento[4], '\0' };
    char anoStr[5] = { dataDeNascimento[6], dataDeNascimento[7], dataDeNascimento[8], dataDeNascimento[9], '\0' };

    *dia = atoi(diaStr);   // Converte a string do dia para inteiro
    *mes = atoi(mesStr);   // Converte a string do mês para inteiro
    *ano = atoi(anoStr);   // Converte a string do ano para inteiro

    int resultado = validarLogica( dia, mes, ano);

    if(resultado ==1){
         return 1;

    } else {
        return 0;
    }



}



