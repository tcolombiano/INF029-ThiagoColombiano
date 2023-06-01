#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

typedef struct vetor{
    int *vaux;
    int tam;
    int pos;
    int posAtual;
}v;

v vetorPrincipal[TAM];

void zerar(int tamanho){
  int i;
  for(i =0 ; i<tamanho;i++){
    vetorPrincipal[i].vaux = NULL;
  }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    posicao--;
    //vetorPrincipal[posicao].vaux = (int*) malloc(sizeof(int)*tamanho);
    int  *novo = NULL;
    int valor;
    int retorno = 0;

    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao].vaux!= NULL)
        retorno =  JA_TEM_ESTRUTURA_AUXILIAR;
        
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 0 || posicao > 9)
        retorno  = POSICAO_INVALIDA;
       
    // o tamanho ser muito grande
    /*(!vetorPrincipal[posicao].vaux)
       retorno =  SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que */
    if(tamanho < 1)
      retorno = TAMANHO_INVALIDO;
     
    // deu tudo certo, crie
    if(retorno == 0)
      retorno = SUCESSO;
    
    if(retorno == SUCESSO)
        novo = (int*) malloc(sizeof(int)*tamanho);
    

    if (novo && retorno == SUCESSO){
      //printf("ok\n");
      vetorPrincipal[posicao].vaux = novo;
      vetorPrincipal[posicao].vaux[0] =JA_TEM_ESTRUTURA_AUXILIAR;
      vetorPrincipal[posicao].tam = tamanho;
      vetorPrincipal[posicao].pos = posicao;
      vetorPrincipal[posicao].posAtual= 0;

      //printf("%d",retorno);
      return retorno;
      }

    
    
    /*vetorPrincipal[posicao].vaux[0] = 5;
    vetorPrincipal[posicao].vaux[1] = 2;
    vetorPrincipal[posicao].vaux[2] = 4;
    vetorPrincipal[posicao].vaux[3] = 9;*/
    
    
      //printf("%d\n",vetorPrincipal[posicao].vaux[2]);
    
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    posicao--;
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 1;
    int posicao_invalida = 0;

    

    if (posicao < 0 || posicao > 9)
        retorno = POSICAO_INVALIDA;

    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].vaux != NULL){
            if (vetorPrincipal[posicao].posAtual < vetorPrincipal[posicao].tam)
            {
                //insere
                vetorPrincipal[posicao].vaux[vetorPrincipal[posicao].posAtual] = valor;
                //printf("O valor %d inserino na posição %d\n",valor,vetorPrincipal[posicao].posAtual);
                retorno = SUCESSO;
                vetorPrincipal[posicao].posAtual++;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
  
    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    int i,j = 0;
    int aux;
    int taux;
    int retorno = 0;


    if(posicao < 0 || posicao > 9){
      retorno = POSICAO_INVALIDA;
      return POSICAO_INVALIDA;
    }

    if(vetorPrincipal[posicao].vaux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;}
      
    
    for(i = 0;i <  vetorPrincipal[posicao].posAtual;i++)
        vetorAux[i] = vetorPrincipal[posicao].vaux[i];

    /*printf("Estrura aux[%d]: ",posicao);
     for(i = 0;i < vetorPrincipal[posicao].posAtual;i++)
      printf("%d ",vetorAux[i]);
    puts(""); */

    if (retorno == 0)
        retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  //ok
    int i,j,k = 0;
    int retorno,vazio = 0;
    
    for(i= 0; i < TAM ; i++){
      if(vetorPrincipal[i].vaux == NULL || vetorPrincipal[i].posAtual == 0)
      vazio++;}

    if(vazio == TAM){
      retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
      return retorno;}

    for(i = 0;i < TAM;i++){
      if(vetorPrincipal[i].vaux != NULL){
        //printf("\nvetor da posião %d\n",i);
       // printf("Tamanho: %d\n",vetorPrincipal[i].tam);
       // printf("Números: ");
         for(j = 0;j < vetorPrincipal[i].posAtual  ;j++){
              //printf("%d ",vetorPrincipal[i].vaux[j]);
              vetorAux[k]= vetorPrincipal[i].vaux[j];
              k++;}
        //printf("\n");
      }/*else
        printf("Posição %d estar vazia \n",i);*/
    }
    
    if(i > 0 )
      retorno =SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  //ok
    posicao--;
    int retorno,i,j = 0;
    int aux;

    if(posicao < 0 || posicao > 9){
      retorno = POSICAO_INVALIDA;
      return POSICAO_INVALIDA;
    }

    if(vetorPrincipal[posicao].vaux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;}


    if( vetorPrincipal[posicao].vaux[0] == JA_TEM_ESTRUTURA_AUXILIAR || vetorPrincipal[posicao].posAtual == 0 ){
      retorno = ESTRUTURA_AUXILIAR_VAZIA;//-8 
      return ESTRUTURA_AUXILIAR_VAZIA;}

    
    for(i = 0;i < vetorPrincipal[posicao].posAtual;i++)
        vetorAux[i] = vetorPrincipal[posicao].vaux[i];

    for(i = 0; i < vetorPrincipal[posicao].posAtual;i++)
      for(j = i;j < vetorPrincipal[posicao].posAtual;j++)
          if(vetorAux[i] > vetorAux[j]){
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = aux;}

   
    /*for(i = 0;i < vetorPrincipal[posicao].posAtual;i++)
      printf("%d ", vetorAux[i]);
    puts("");*/

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  // ok
    int i,j,k;
    int aux;
    int retorno,vazio,Taux = 0;

    for(i= 0; i < TAM ; i++){
      if(vetorPrincipal[i].vaux == NULL|| vetorPrincipal[i].posAtual == 0)
      vazio++;}

    if(vazio == TAM){
      retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
      return retorno;}
    k = 0;
    for(i = 0;i < TAM;i++)
      if(vetorPrincipal[i].vaux != NULL){
         for(j = 0;j < vetorPrincipal[i].posAtual;j++){
              vetorAux[k] = vetorPrincipal[i].vaux[j];
              k++;}
         Taux += vetorPrincipal[i].posAtual;}
    

    for(i = 0; i < Taux;i++)
      for(j = i;j < Taux;j++)
          if(vetorAux[i] > vetorAux[j]){
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = aux;}
    
    /*for(i = 0; i < Taux;i++)
        printf("%d ",vetorAux[i]);
    puts("");*/
    retorno = SUCESSO;
    return retorno;
}
/*
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  //printf("vetor[1] = %d ",vetorPrincipal[1].vaux[0]);
 int retorno = SUCESSO;
  posicao--;
  if(posicao < 0 || posicao > 9){
      retorno = POSICAO_INVALIDA; // -5
      return  POSICAO_INVALIDA;}

  if( vetorPrincipal[posicao].vaux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;//-3
      return SEM_ESTRUTURA_AUXILIAR; }

  if( vetorPrincipal[posicao].vaux[0] == JA_TEM_ESTRUTURA_AUXILIAR || vetorPrincipal[posicao].posAtual == 0){
      retorno = ESTRUTURA_AUXILIAR_VAZIA;//-8 
      return ESTRUTURA_AUXILIAR_VAZIA;}

    
    vetorPrincipal[posicao].posAtual--;
    if( vetorPrincipal[posicao].posAtual == 0)
         vetorPrincipal[posicao].vaux[0] = JA_TEM_ESTRUTURA_AUXILIAR;
    //printf("qtd: %d ",vetorPrincipal[posicao].posAtual);

    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  //ok
    posicao--;
    int retorno,i = 0;
    int posEx,ok = 0;
  
    
    if(posicao < 0 || posicao > 9){
      retorno = POSICAO_INVALIDA; // -5
      return  POSICAO_INVALIDA;}

    if( vetorPrincipal[posicao].vaux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;//-3
      return SEM_ESTRUTURA_AUXILIAR; }

    if( vetorPrincipal[posicao].vaux[0] == JA_TEM_ESTRUTURA_AUXILIAR || vetorPrincipal[posicao].posAtual == 0){
      retorno = ESTRUTURA_AUXILIAR_VAZIA;//-8 
      return ESTRUTURA_AUXILIAR_VAZIA;}
    
    for(i=0;i<vetorPrincipal[posicao].posAtual;i++){
        if(vetorPrincipal[posicao].vaux[i] == valor){
            posEx = i;
            vetorPrincipal[posicao].posAtual--;
            ok = 1;}
    }

    if(ok == 0){
      retorno = NUMERO_INEXISTENTE;//-9
      return NUMERO_INEXISTENTE; 
    }

    for(i=posEx;i<vetorPrincipal[posicao].posAtual;i++)
        vetorPrincipal[posicao].vaux[i] =vetorPrincipal[posicao].vaux[i + 1];

    /*for(i=0;i <vetorPrincipal[posicao].posAtual;i++)
        printf("%d ",vetorPrincipal[posicao].vaux[i]);
    puts("");*/
     retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao--;
    int retorno = 0;

    int qtdRemovidos= 0;

    if (novoTamanho < 0) // vai remover elementos
        qtdRemovidos = novoTamanho;
    

    novoTamanho = vetorPrincipal[posicao].tam + novoTamanho;
    
    if(posicao < 0 || posicao > 9){
      retorno = POSICAO_INVALIDA; // -5
      return  POSICAO_INVALIDA;}
    
    if(novoTamanho < 1){
      retorno = NOVO_TAMANHO_INVALIDO; // -10
      return NOVO_TAMANHO_INVALIDO;}

    if( vetorPrincipal[posicao].vaux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;//-9
      return SEM_ESTRUTURA_AUXILIAR; }

    

   
    vetorPrincipal[posicao].vaux = realloc(vetorPrincipal[posicao].vaux,novoTamanho);
    vetorPrincipal[posicao].tam = novoTamanho;
    if(qtdRemovidos != 0)
      vetorPrincipal[posicao].posAtual += qtdRemovidos; 

    printf("Novo tamanho da estrutura: %d\n",vetorPrincipal[posicao].tam);
    if(vetorPrincipal[posicao].vaux)
        retorno = SUCESSO;

    return retorno;
}


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/
void inicializar()
{
  printf("***Inicializou\n");
  zerar(TAM);
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  printf("***Finalizou\n");
}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
  posicao--;
  int qtd;
  int retorno = 0;

  if(vetorPrincipal[posicao].vaux == NULL){
    retorno = SEM_ESTRUTURA_AUXILIAR;
    return retorno;}
  
  if(vetorPrincipal[posicao].vaux[0] == JA_TEM_ESTRUTURA_AUXILIAR){
      retorno = ESTRUTURA_AUXILIAR_VAZIA;
      return retorno;}

  qtd = vetorPrincipal[posicao].posAtual;

  return qtd;
}