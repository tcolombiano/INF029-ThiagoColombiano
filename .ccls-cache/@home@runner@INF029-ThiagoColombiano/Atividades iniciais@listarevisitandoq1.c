//Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha.
#include<stdio.h>
int main()
{
  char nome[61];//string é uma variável que armazena uma cadeira de caracteres.
  int matricula,semestre,validador;
  
  printf("Digite seu nome: ");
  //scanf("%s",nome);//só vai pegar as strings até achar um espaço em branco.
  fgets(nome,61,stdin);//leitura de string pegando espaços e tudo
    printf("Digite sua matrícula -Somente NÚMEROS: ");
    scanf("%d",&matricula);
  
  printf("O nome armazenado foi: %s", nome);
  return 0;
}