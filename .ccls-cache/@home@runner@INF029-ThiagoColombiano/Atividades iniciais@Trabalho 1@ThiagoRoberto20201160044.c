//Trabalho 1 da disciplina Laboratório de programação
//
//
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ThiagoRoberto20201160044.h"

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


/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

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

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
    dataQuebrada iDataInicial;
    dataQuebrada iDataFinal;
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;
    
    if (q1(datafinal) == 0)
        return 3;

    iDataInicial =quebradata(datainicial);
    iDataFinal  = quebradata(datafinal);

    printf("%d\n",iDataInicial.iAno);

    if(iDataInicial.iAno > iDataFinal.iAno){
    printf("ano maior");
     return 4;}
    else if(iDataInicial.iAno == iDataFinal.iAno){
          if(iDataInicial.iMes >iDataFinal.iMes){
            printf("mês maior");
            return 4;}
          else if(iDataInicial.iMes  == iDataFinal.iMes)
                if(iDataInicial.iDia  > iDataFinal.iDia){
                     printf("dias maior");
                      return 4;}
    }
    
    nAnos = iDataFinal.iAno - iDataInicial.iAno;
    nMeses = iDataFinal.iMes - iDataInicial.iMes;
    nDias = iDataFinal.iDia - iDataInicial.iDia;
   
   printf("%d dias %d meses %d anos",nDias,nMeses,nAnos );
    

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
    int i;
    char cInvertido;

    if(isCaseSensitive == 1){
      for(i = 0; i < strlen(texto);i++){
        if(texto[i] == c)
          qtdOcorrencias++;
      }
    }else{
      if(c > 90){
       // printf("minuscula");
        cInvertido = c - 32;}
      else{
        cInvertido = c + 32;
        //printf("maiuscula");
        }

        //printf("\n%c",cInvertido);
      for(i = 0; i < strlen(texto);i++){
        if(texto[i] == c|| texto[i] == cInvertido)
          qtdOcorrencias++;}
      
      }


  
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int i,j,cont,k = 0;
    int tamTexto = strlen(strTexto);
    int tamStrBusca = strlen(strBusca);
    char palavra[20];
    int ok =0;
    int posInicial =0;
    int posfinal =0;
      //printf("%d",tamTexto);

    for(cont=0;cont<30;cont++){
          posicoes[cont] = 0;
    }

    for(i = 0;i < tamTexto;i++){
      ok = 0;
      if(strTexto[i] == strBusca[0]){
        cont = i;
        for(j=0;j < tamStrBusca;j++){
            if(strTexto[cont] == strBusca[j]){
            palavra[j] = strTexto[cont]; 
            cont++;
            ok++;}
            }
      
          }
            for(cont=0;cont<30;cont++)
              if(posicoes[cont] == 0 && ok * 1 == tamStrBusca){
                qtdOcorrencias++;
                posicoes[cont] = i+1;
                posicoes[cont + 1] = i + (tamStrBusca);
                break;
              }

            
     
      }
    
     //imprime as posições 
    for(cont=0;cont<30;cont++)
          printf(" %d ",posicoes[cont]);
  
   printf("\nqtd: %d \n",qtdOcorrencias);
   return qtdOcorrencias;
   
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int n = 123;
    int cont=0,i= 0;
    int algs[6];
    int resultado = 0;
    
    for(i =0;i<6;i++)
        algs[i] = 0;

    while(num > 0){
        algs[cont] = num%10;
        num /= 10;
        cont++;
        }
    
    int p = cont;
    for (i =0;i<cont;i++){
        algs[i] = algs[i] * pot(10,p-1);
        p--;
       }

    for (i =0;i<cont;i++)
        resultado += algs[i];

    //printf("\n%d\n",resultado);

    
    return resultado;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0;
    int algs[6];
    int cont=0,i= 0;
    int aux = numerobusca;
    int algsBusca[6];


    while(aux> 0){
         algsBusca[i] = aux%10;
         i++;
        aux/= 10;
        }


    while(numerobase > 0){
         algs[cont] = numerobase% pot(10,i);
         if(algs[cont] == numerobusca)
         qtdOcorrencias++;
        numerobase /= 10;
        cont++;
        }
    //printf("qtd = %d ",qtdOcorrencias);

    return qtdOcorrencias;
}