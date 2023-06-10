#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "uteis.h"
#include "disciplina.h"

//Referência a funções
void listarCadastros(cad pessoa[],int qtd_cadastros);
int menuAluno();
int menuDisciplina();
int menuProfessor();
void mostrarErro(int conf);

  int main(void) {
  //**listas**
  cad Lalunos[TAM];
  cad Lprofessores[TAM];
  dpn Ldisciplinas[TAM];

  //**Contadores**
  int qtd_disciplinas = 0;
  int qtd_alunos = 0; 
  int qtd_professores = 0;

  //**auxiliares**
  int conf = 0; 
  int menu1 = 0;
  int posicao;

  
  while(!menu1){

    int opcao;
    int opcaoAluno;
    int opcaoDisciplina;
    int opcaoProfessor;
    printf("\n========Menu Principal=========\n");
    printf("\nSair.............[ 0 ]\n");
    printf("Aluno............[ 1 ]\n");
    printf("Disciplina.......[ 2 ]\n");
    printf("Professor........[ 3 ]\n");
    printf("Digite: ");
    scanf("%d",&opcao);

    //Menu principal
      switch(opcao){
      
      case 0:
        printf("Finalizando programa");
        menu1 = 1;
        break;

      case 1:
        //Menu aluno
        //opcaoAluno =
        qtd_alunos = menuAluno(conf,Lalunos,qtd_alunos);
        printf("%d alunos",qtd_alunos);
        break;// do case 1 menu aluno


      case 3:
          //Menu Professor
          //opcaoProfessor =
          qtd_professores = menuProfessor(conf,Ldisciplinas,qtd_professores);
          printf("%d professores",qtd_professores);
          break;


      case 2:
        // menu disciplinas
          opcaoDisciplina = menuDisciplina();
          switch(opcaoDisciplina){
            case 0:
              opcaoDisciplina = 0;
              break;

            case 1:
              cadastrarDisciplina(Ldisciplinas,qtd_disciplinas);
              if(conf == Sucesso_Cadastro){
              printf("Sucesso no cadastro\n");
              qtd_disciplinas++; }
              break;

            case 2:
              listarDisciplinas(Ldisciplinas,qtd_disciplinas);
              break;

            case 3:
              cadastrarAlunoDisplina(Ldisciplinas,Lalunos,qtd_disciplinas,qtd_alunos);
              break;

            case 4:
              listarMatriculados(Ldisciplinas,qtd_disciplinas);
              break; 

            case 5:
              excluirMatriculado(Ldisciplinas,qtd_disciplinas);
              break;
            
            default :
            printf ("Valor invalido!\n");
            break;
            
          } 
          break; //break do case 2 menu disciplina
          
      default :
            printf ("\n|Valor invalido!|\n");
            break;
          
      }// switch menu principal
  
  }//while
  return 0;
}

int menuAluno( int conf,cad Lalunos[],int qtd_alunos){
  int opcaoAluno;
  printf("\n========Menu Alunos=========\n");
  printf("Voltar...........[ 0 ]\n");
  printf("Cadastrar aluno..[ 1 ]\n");
  printf("Listar alunos....[ 2 ]\n");
  printf("Atualizar aluno..[ 3 ]\n");
  printf("Excluir aluno....[ 4 ]\n");
  printf("Digite: ");
  scanf("%d",&opcaoAluno);

  switch(opcaoAluno){

          case 0:
              opcaoAluno = 0;
            break;

          case 1:
              conf = cadastrar(Lalunos,qtd_alunos);
              if(conf == Sucesso_Cadastro){
              qtd_alunos++; }
              mostrarErro(conf);
            break;  

          case 2:
              listar(Lalunos,qtd_alunos);
              break;

          case 3:
           conf = atulizarCad(Lalunos,qtd_alunos);
           mostrarErro(conf);
            break;
            
          case 4:
              qtd_alunos = excluirCad(Lalunos,qtd_alunos);
              break;

            
          default :
            printf ("Valor invalido!\n");
            break;
            
          }
 
  return qtd_alunos;
}

int menuDisciplina(){
  int opcaoDisciplina;
  printf("\n========Menu Disciplinas=========\n");
  printf("Voltar........................[ 0 ]\n");
  printf("Cadastrar Disciplina......... [ 1 ]\n");
  printf("Listar disciplinas............[ 2 ]\n");
  printf("Cadastrar aluno na disciplina [ 3 ]\n");
  printf("Listar Alunos na disciplina...[ 4 ]\n");
  printf("Excluir aluno da disciplina...[ 5 ]\n");
  printf("Digite: ");
  scanf("%d",&opcaoDisciplina);
  return opcaoDisciplina;
}

int menuProfessor(int conf,cad Lprofessores[],int qtd_professores){
  int opcaoProfessor;
  printf("\n========Menu Professores=========\n");
  printf("Voltar..................[ 0 ]\n");
  printf("Cadastrar Professor(a)..[ 1 ]\n");
  printf("Listar Professor(a).....[ 2 ]\n");
  printf("Atualizar Professor(a)..[ 3 ]\n");
  printf("Excluir Professor(a)....[ 4 ]\n");
  printf("Digite: ");
  scanf("%d",&opcaoProfessor);

  switch(opcaoProfessor){

            case 0:
              opcaoProfessor = 0;
              break;

            case 1:
                conf = cadastrar(Lprofessores,qtd_professores);
                if(conf == Sucesso_Cadastro){
                qtd_professores++; }
                 mostrarErro(conf);
              break;  

            case 2:
                listar(Lprofessores,qtd_professores);
                break;

            case 3:
              conf = atulizarCad(Lprofessores,qtd_professores);
              mostrarErro(conf);
              break;
              
            case 4:
                qtd_professores = excluirCad(Lprofessores,qtd_professores);
                break;

              
            default :
              printf ("Valor invalido!\n");
              break;
            
          } 
 
  
  return qtd_professores;
}

void mostrarErro(int conf){
    switch(conf){
      case Sucesso_Cadastro:
      printf("Cadastrado com Sucesso\n");
      break;

      case Erro_Cadastro_Nome:
      printf("Erro no nome\n");
      break;

      case  Erro_Cadastro_Cpf:
      printf("Erro no CPF\n");
      break;

      case Erro_Cadastro_Sexo:
      printf("Erro no sexo\n");
      break;
      
      case Erro_Cadastro_Data:
      printf("Erro na data\n");
      break;
    }
}