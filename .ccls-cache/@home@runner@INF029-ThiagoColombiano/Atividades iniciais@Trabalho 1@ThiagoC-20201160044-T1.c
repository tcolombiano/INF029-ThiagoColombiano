//Trabalho 1 da disciplina Laboratório de programação
//
//
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ThiagoC-20201160044-T1.h"

typedef struct  {
  int iDia;
  int iMes;
  int iAno;
  int valido;
}dataQuebrada;

int pot(int n, int p)
    {
        int cont = 0;
        int r = n;
        if(p != 0){
            
          while(cont <  (p - 1)){
              r *= n;
              cont++;}
         }else
            r = 1;
    return r;
    }

int ajudaQ2(int ano,int mes, int dia){

  int meses30[]={4,6,9,11};
  int meses31[] ={1,3,5,7,8,10,12};
  return 0;
}
/*## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
    int soma;
    soma = x + y;
    return soma;
}
/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
 int fatorial(int x){ //função utilizada para testes
    int fat = x;
    int i;
    int resultado = x; 

    if (fat <= 0)
      return 0;
    else
      for(i = fat; i >= 1;i--){
          if ((i - 1) > 0)  
            resultado*= (i-1);}

    return resultado;
}

/*
Q1: Fazer um programa que valide uma data*/

dataQuebrada quebradata(char data[20]){

  int i;
  char sdias[3],smes[3],sanos[5];
  dataQuebrada dt;
  dt.valido =-1;

 for(i =0;data[i] != '/';i++){
   sdias[i] = data[i];
 }
 if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sdias[i] = '\0';  // coloca o barra zero no final
	}else 
		dt.valido= 0;
 // printf("%s\n",sdias);

  
  int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		smes[i] = data[j];
		i++;
	}
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		smes[i] = '\0';  // coloca o barra zero no final
	}else
		dt.valido =0;
  //printf("%s\n",smes);

  j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sanos[i] = data[j];
	 	i++;
	}
  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sanos[i] = '\0';  // coloca o barra zero no final
  }else
    dt.valido =0;

  // printf("%s\n",sanos);

           //// Conversão para Int////
  //int iDia,iMes,iAno;
  dt.iDia = atoi(sdias);
  dt.iMes = atoi(smes);
  dt.iAno = atoi(sanos);
 /* int iAno = atoi(sanos);
  int iMes = atoi(smes);
  int iDia = atoi(sdias);*/
  
  //printf("int :%d/ %d / %d\n",dt.iDia,dt.iMes,dt.iAno);

    return dt;
 }


int q1(char *data)
{
    int datavalida = 1;
    dataQuebrada dt;
    //quebrar a string data em strings sDia, sMes, sAno
    dt  = quebradata(data);
    dt.valido=-1;

    //DataQuebrada dataQuebrada = quebraData(data);
    if (dt.valido == 0) 
      return 0;

    //converter sDia, sMes e sAno em inteiros (ex: atoi)

    //criar as variáveis iDia, iMes, iAno
    //int iAno = atoi(dataQuebrada.sAno);
    int eBissexto,i;
  if ((dt.iAno % 4 == 0 && dt.iAno % 100 != 0) || dt.iAno % 400 == 0)
      eBissexto = 1;
    else
      eBissexto = 0;

    //printf("%d\n",eBissexto);

    int mes30[] ={4,6,9,11};
    int tMes;// 30 = mes com 30, 31 =mes com 31 e 2 = fevereiro
    if(dt.iMes > 0 && dt.iMes<= 12){
        for(i=0;i<4;i++){
          if(dt.iMes == mes30[i]){
             //printf("valida");
             tMes = 30;
             break;
          }else if(dt.iMes == 2){
                tMes =2;
                break;}
            else
              tMes = 31;
              
        } 
    }else
      return 0;

    if(tMes == 30 && (dt.iDia > 30 || dt.iDia < 1)){
      // printf("erro30");
      return 0;
     
    }
    else if (tMes == 31 && (dt.iDia > 31 || dt.iDia < 1)){
      //printf("erro31");
      return 0;}
    else if (tMes == 2 ){
      if(eBissexto == 0 && (dt.iDia< 1 || dt.iDia > 28)){
        //printf("erro2");
        return 0;}
      else if (eBissexto == 1 && (dt.iDia< 1 || dt.iDia > 29)){
      //printf("erro2 bi");
      return 0;
      }
    }
    //printf("%s\n", data);

    //if (datavalida)
        return 1;
   
}