// ThiagoRoberto20201160044
// Versão Final!!!!!
//  #################################################
//   Instituto Federal da Bahia
//   Salvador - BA
//   Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//   Disciplina: INF029 - Laboratório de Programação
//   Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
/*Nome: Thiago Roberto ~~Email: thiagocolombiano32@gmail.com ~~  Matrícula:
 * 20201160044 ~~  Semestre: 2 */
// Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016
// #################################################

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ThiagoRoberto20201160044.h"

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {

  int soma = 0;

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
int fatorial(int x) { // função utilizada para testes

  int fat = 0;

  if (x < 0) {
    fat = 0;
  } else if (x == 0 || x == 1) {
    fat = 1;
  } else {
    for (fat = 1; x > 1; x = x - 1) {
      fat *= x;
    }
  }

  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data) {

  int datavalida = 0;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int diaI;
  int mesI;
  int anoI;
  int tamanhoAno;

  quebrarData(data, sDia, sMes, sAno);

  diaI = atoi(sDia);
  mesI = atoi(sMes);
  anoI = atoi(sAno);

  if (strlen(sAno) == 2) {
    anoI += 2000;
    tamanhoAno = 4;
  }
  if ((strlen(sAno) == 4 || tamanhoAno == 4) && anoI > 1000) {

    if ((strlen(sMes) > 0 && strlen(sMes) <= 2) &&
        (strlen(sDia) > 0 && strlen(sDia) <= 2)) {

      if (mesI == 1 || mesI == 3 || mesI == 5 || mesI == 7 || mesI == 8 ||
          mesI == 10 || mesI == 12) {
        if (diaI <= 0 || diaI > 31) {
          datavalida = 0;
        } else {
          datavalida = 1;
        }

      } else if (mesI == 2) {
        if (anoBissexto(anoI) == 1) {
          if (diaI <= 0 || diaI > 29) {
            datavalida = 0;
          } else {
            datavalida = 1;
          }
        } else {
          if (diaI <= 0 || diaI > 28) {
            datavalida = 0;
          } else {
            datavalida = 1;
          }
        }

      } else if (mesI == 4 || mesI == 6 || mesI == 9 || mesI == 11) {
        if (diaI <= 0 || diaI > 30) {
          datavalida = 0;
        } else {
          datavalida = 1;
        }

      } else {
        datavalida = 0;
      }
    } else {
      datavalida = 0;
    }
  } else {
    datavalida = 0;
  }

  return datavalida;
}

void quebrarData(char data[], char sDia[], char sMes[], char sAno[]) {

  int i, y;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  sDia[i] = '\0';

  for (i = i + 1, y = 0; data[i] != '/'; i++, y++) {
    sMes[y] = data[i];
  }
  sMes[y] = '\0';

  for (i = i + 1, y = 0; data[i] != '\0'; i++, y++) {
    sAno[y] = data[i];
  }
  sAno[y] = '\0';
}

int anoBissexto(int ano) {

  int retorno = 0;
  int contador = 0;

  if (ano % 4 == 0) {
    contador++;
  }
  if (ano % 100 == 0) {
    contador--;
  }
  if (ano % 400 == 0) {
    contador++;
  }

  if (contador > 0) {
    retorno = 1;
  } else {
    retorno = 0;
  }

  return retorno;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três
 parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser
 utilizados para guardar os resultados dos cálculos. Na chamada da função deve
 passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses,
       int *qtdAnos) {

  int retorno = 0;

  // calcule os dados e armazene nas três variáveis a seguir
  int nDias, nMeses, nAnos;

  // Variáveis da data inicial
  char sDiaIni[3], sMesIni[3], sAnoIni[5];
  int iDia1, iMes1, iAno1;

  // Variáveis da data final
  char sDiaFinal[3], sMesFinal[3], sAnoFinal[5];
  int iDia2, iMes2, iAno2;

  int diferencaDia, diferencaMes, diferencaAno;

  // Verificações iniciais
  if (q1(datainicial) == 0)
    retorno = 2;
  else if (q1(datafinal) == 0)
    retorno = 3;
  else if (dataMaiorMenor(datainicial, datafinal) == -1)
    retorno = 4;
  else
    retorno = 1;

  quebrarData(datainicial, sDiaIni, sMesIni, sAnoIni);
  iDia1 = atoi(sDiaIni);
  iMes1 = atoi(sMesIni);
  iAno1 = atoi(sAnoIni);

  quebrarData(datafinal, sDiaFinal, sMesFinal, sAnoFinal);
  iDia2 = atoi(sDiaFinal);
  iMes2 = atoi(sMesFinal);
  iAno2 = atoi(sAnoFinal);

  // Transforma o ano com 2 caracteres em um ano com 4 caracteres
  if (strlen(sDiaIni) == 2)
    iAno1 += 2000;
  if (strlen(sDiaFinal) == 2)
    iAno2 += 2000;

  // Diferença entre dias, meses e anos
  if (iAno1 == iAno2)
    diferencaAno = 0;
  else
    diferencaAno = 1;

  if (iMes1 == iMes2)
    diferencaMes = 0;
  else
    diferencaMes = 1;

  if (iDia1 == iDia2)
    diferencaDia = 0;
  else
    diferencaDia = 1;

  // Calculo do Ano
  if (diferencaAno == 0) {
    nAnos = 0;
  } else {

    if (iAno1 > iAno2)
      nAnos = iAno1 - iAno2;
    else
      nAnos = iAno2 - iAno1;

    if (diferencaMes == 0 && iDia1 > iDia2)
      nAnos -= 1;
    else if (diferencaMes == 0 && iDia2 > iDia1)
      nAnos -= 1;

    if (iMes1 == 2 && iMes1 == 2) {
      if (anoBissexto(iAno1) && anoBissexto(iAno2) && iDia1 == iDia2) {
        if (iAno1 > iAno2)
          nAnos = iAno1 - iAno2;
        else
          nAnos = iAno2 - iAno1;

      } else if (anoBissexto(iAno1) && !anoBissexto(iAno2) && iDia1 == 29 &&
                 iDia2 == 28) {
        if (iAno1 > iAno2)
          nAnos = iAno1 - iAno2;
        else
          nAnos = iAno2 - iAno1;

      } else if (!anoBissexto(iAno1) && anoBissexto(iAno2) && iDia1 == 28 &&
                 iDia2 == 29) {
        if (iAno1 > iAno2)
          nAnos = iAno1 - iAno2;
        else
          nAnos = iAno2 - iAno1;
      }
    }
  }

  // Calculo do Mes
  if (diferencaMes == 0) {

    if (iDia1 == iDia2)
      nMeses = 0;
    else if (iDia1 > iDia2)
      nMeses = (12 - iMes1) + iMes2 - 1;
    else
      nMeses = (12 - iMes2) + iMes1 - 1;

    if (iMes1 == 2 && iMes2 == 2) {
      if (anoBissexto(iAno1) && anoBissexto(iAno2) && iDia1 == 29 &&
          iDia2 == 29)
        nMeses = 0;
      else if (!anoBissexto(iAno1) && anoBissexto(iAno2) && iDia1 == 28 &&
               iDia2 == 29)
        nMeses = 0;
      else if (anoBissexto(iAno1) && !anoBissexto(iAno2) && iDia1 == 29 &&
               iDia2 == 28)
        nMeses = 0;
    }

  } else {

    if (iMes1 > iMes2 && iDia1 > iDia2)
      nMeses = (12 - iMes1) - iMes2;
    else if (iMes2 > iMes1 && iDia2 > iDia1)
      nMeses = iMes2 - iMes1;
    else if (iMes1 > iMes2 && iDia1 == iDia2)
      nMeses = iMes1 - iMes2;
    else if (iMes2 > iMes1 && iDia2 == iDia1)
      nMeses = iMes2 - iMes1;

    if (nMeses < 0)
      nMeses *= -1;
  }

  // Diferenciando meses
  int iMes1_31 = 0;
  int iMes1_30 = 0;
  int iMes1_28 = 0;
  int iMes1_29 = 0;

  int iMes2_31 = 0;
  int iMes2_30 = 0;
  int iMes2_28 = 0;
  int iMes2_29 = 0;

  // Calculo do Dia
  if (diferencaDia == 0)
    nDias = 0;
  else {

    // Descobre a quantidade de dias do primeiro mês
    if (iMes1 == 1 || iMes1 == 3 || iMes1 == 5 || iMes1 == 7 || iMes1 == 8 ||
        iMes1 == 10 || iMes1 == 12) {
      iMes1_31 = 1;
    }
    if (iMes1 == 2 && !anoBissexto(iAno1)) {
      iMes1_28 = 1;
    }
    if (iMes1 == 2 && anoBissexto(iAno1)) {
      iMes1_29 = 1;
    }
    if (iMes1 == 4 || iMes1 == 6 || iMes1 == 9 || iMes1 == 11) {
      iMes1_30 = 1;
    }
    // Descobre a quantidade de dias do segundo mês
    if (iMes2 == 1 || iMes2 == 3 || iMes2 == 5 || iMes2 == 7 || iMes2 == 8 ||
        iMes2 == 10 || iMes2 == 12) {
      iMes2_31 = 1;
    }
    if (iMes2 == 2 && !anoBissexto(iAno2)) {
      iMes2_28 = 1;
    }
    if (iMes2 == 2 && anoBissexto(iAno2)) {
      iMes2_29 = 1;
    }
    if (iMes2 == 4 || iMes2 == 6 || iMes2 == 9 || iMes2 == 11) {
      iMes2_30 = 1;
    }

    nDias = iDia1 - iDia2;

    if (iDia1 > iDia2) {
      if (iMes1_30 == 1)
        nDias = (30 - iDia1) + iDia2;
      if (iMes1_31 == 1)
        nDias = (31 - iDia1) + iDia2;
      if (iMes1_28 == 1)
        nDias = (28 - iDia1) + iDia2;
      if (iMes1_29 == 1)
        nDias = (29 - iDia1) + iDia2;
      if ((iMes1_29 == 1) && (iMes2_28 == 1))
        nDias = iDia1 - iDia2 - 1;
    }

    if (nDias < 0)
      nDias *= -1;
  }

  /* mantenha o código abaixo, para salvar os dados em
  nos parâmetros da funcao */
  *qtdDias = nDias;
  *qtdAnos = nAnos;
  *qtdMeses = nMeses;

  // coloque o retorno correto
  return retorno;
}

int dataMaiorMenor(char dataInicial[], char dataFinal[]) {

  int retorno = 0;

  // Variáveis da data inicial, string e inteiro
  char diaIni[3];
  char mesIni[3];
  char anoIni[5];
  int iDiaIni;
  int iMesIni;
  int iAnoIni;
  quebrarData(dataInicial, diaIni, mesIni, anoIni);
  iDiaIni = atoi(diaIni);
  iMesIni = atoi(mesIni);
  iAnoIni = atoi(anoIni);

  // Variáveis da data final, string e inteiro
  char diaFinal[3];
  char mesFinal[3];
  char anoFinal[5];
  int iDiaFinal;
  int iMesFinal;
  int iAnoFinal;
  quebrarData(dataFinal, diaFinal, mesFinal, anoFinal);
  iDiaFinal = atoi(diaFinal);
  iMesFinal = atoi(mesFinal);
  iAnoFinal = atoi(anoFinal);

  if (iAnoIni > iAnoFinal) {
    retorno = -1;
  } else {
    retorno = 1;
    if (iMesIni > iMesFinal) {
      retorno = -1;
    } else {
      retorno = 1;
      if (iDiaIni > iDiaFinal) {
        retorno = -1;
      } else {
        retorno = 1;
      }
    }
  }

  return retorno;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {

  int qtdOcorrencias = 0;
  int i;
  char textoAux[250];
  char cAux;
  int contador = 0;

  if (isCaseSensitive == 1) {
    for (i = 0; texto[i] != '\0'; i++) {
      if (texto[i] == c) {
        contador++;
      }
    }
  } else {
    for (i = 0; texto[i] != '\0'; i++) {
      textoAux[i] = tolower(texto[i]);
      cAux = tolower(c);
      if (textoAux[i] == cAux) {
        contador++;
      }
    }
  }

  qtdOcorrencias = contador;
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {

  int qtdOcorrencias = 0;
  int i, y, j, x, z;
  int aux;
  int acentos = 0;
  int c = 0;
  int vetorAux[250];
  int tamStrTexto = strlen(strTexto);
  int tamStrBusca = strlen(strBusca);

  for (x = 0; x < 250; x++) {
    vetorAux[0] = 999;
    vetorAux[x] = 999;
  }

  for (i = 0; i < tamStrTexto; i++) {
    if (strTexto[i] == -61) {
      acentos++;
    }
    if (strBusca[0] == strTexto[i]) {
      vetorAux[i] = i + 1 - acentos;
      c++;
      for (y = 1, j = i + 1; y < tamStrBusca; y++, j++) {
        if (strBusca[y] == strTexto[j]) {
          c++;
          if (strBusca[tamStrBusca - 1] == strTexto[j]) {
            vetorAux[i + 1] = j + 1 - acentos;
          }
        } else {
          vetorAux[i] = 999;
          y = tamStrBusca;
        }
      }
    }
    if (c == tamStrBusca) {
      qtdOcorrencias++;
    }
    c = 0;
  }
  for (x = 0; x < 250; x++) {
    for (z = x + 1; z < 250; z++) {
      if (vetorAux[x] > vetorAux[z]) {
        aux = vetorAux[x];
        vetorAux[x] = vetorAux[z];
        vetorAux[z] = aux;
      }
    }
  }
  for (x = 0; x < 30; x++) {
    posicoes[x] = vetorAux[x];
  }

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
int q5(int num) {

  char strNum[100];
  int tamNum = 0;
  int numInvertido;

  sprintf(strNum, "%d", num);
  tamNum = strlen(strNum);

  for (int i = 0; i < tamNum / 2; i++) {
    char aux = strNum[i];
    strNum[i] = strNum[tamNum - i - 1];
    strNum[tamNum - i - 1] = aux;
  }

  numInvertido = atoi(strNum);

  num = numInvertido;
  return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca) {

  int qtdOcorrencias = 0;
  int multiplicador = 1;
  int numAux = numerobusca;

  while (numAux != 0) {
    multiplicador *= 10;
    numAux /= 10;
  }
  numAux = numerobase;

  while (numAux != 0) {
    if (numAux % multiplicador == numerobusca) {
      qtdOcorrencias++;
      numAux /= multiplicador;
    } else {
      numAux /= 10;
    }
  }

  return qtdOcorrencias;
}
// Commit Versão Final R02