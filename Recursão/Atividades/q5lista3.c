/* Q5 Crie uma função recursiva que receba um número inteiro positivo N e calcule o
somatório dos números de 1 a N. */
#include <stdio.h>
#include <stdlib.h>

//Primeiro de tudo eu tenho que definir quando vai ser a parada da recursão. Nessa questão vai ser quando n for igual a 1

int n;
int somatoriodenumeros;

int somatorio(int n){
if (n ==1){
  return 1;
  } else {
    return n + somatorio(n-1);
  }  
}

int main(){
  int n;
    printf("Digite um valor positivo e inteiro:  ");
    scanf("%d",&n);
  int resultado= somatorio(n);
    printf("O somatório dos números de 1 a %d é : %d \n", n, resultado);
  return 0;
}