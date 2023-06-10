typedef struct{
  char nome [30];
  char professor[30];
  char codigo [30];
  int semestre;
  cad matriculados [5];
  int qtd_matriculados;
  int id;
}dpn;  

void listarDisciplinas(dpn Ldisciplinas[],int qtd_disciplinas);

int cadastrarDisciplina(dpn Ldisciplinas[],int qtd_disciplinas){

    getchar();
    printf("\n********** F I C H A ****************\n");

    printf("Digite o nome : ");
    fgets(Ldisciplinas[qtd_disciplinas].nome,30,stdin);

    size_t ln = strlen(Ldisciplinas[qtd_disciplinas].nome) - 1;
    if (Ldisciplinas[qtd_disciplinas].nome[ln] == '\n')
     Ldisciplinas[qtd_disciplinas].nome[ln] = '\0';

    int numCarateres= 0;
    while (Ldisciplinas[qtd_disciplinas].nome[numCarateres] != '\0'){
      numCarateres++;}
    if(numCarateres > 20)
      printf("Erro\n");
    else
      printf("Sucesso \n");
    //numCarateres--;


    printf("Digite o nome do professor: ");
    fgets(Ldisciplinas[qtd_disciplinas].professor,30,stdin);

    ln = strlen(Ldisciplinas[qtd_disciplinas].professor) - 1;
    if (Ldisciplinas[qtd_disciplinas].professor[ln] == '\n')
     Ldisciplinas[qtd_disciplinas].professor[ln] = '\0';

     numCarateres= 0;
    while (Ldisciplinas[qtd_disciplinas].nome[numCarateres] != '\0'){
      numCarateres++;}
    if(numCarateres > 20)
      printf("Erro\n");
    else
      printf("Sucesso \n");
    //numCarateres--;
    
    printf("Digite o código: ");
    fgets(Ldisciplinas[qtd_disciplinas].codigo,30,stdin); 

    ln = strlen(Ldisciplinas[qtd_disciplinas].codigo) - 1;
    if (Ldisciplinas[qtd_disciplinas].codigo[ln] == '\n')
     Ldisciplinas[qtd_disciplinas].codigo[ln] = '\0';

     numCarateres= 0;
    while (Ldisciplinas[qtd_disciplinas].codigo[numCarateres] != '\0'){
      numCarateres++;}
    if(numCarateres > 5)
      printf("Erro\n");
    else
      printf("Sucesso \n");
    //numCarateres--;

   printf("Digite o semestre: ");
   scanf("%d",&Ldisciplinas[qtd_disciplinas].semestre);
  
  Ldisciplinas[qtd_disciplinas].id = qtd_disciplinas;

  return Sucesso_Cadastro;
}

void listarDisciplinas(dpn Ldisciplinas[],int qtd_disciplinas){
  int i;
  for(i = 0; i < qtd_disciplinas;i++){
          printf("*********************\n");
          printf("Id: %d\n",Ldisciplinas[i].id);
          printf("Nome: %s\n",Ldisciplinas[i].nome);
          printf("Professor: %s\n",Ldisciplinas[i].professor);
          printf("Código: %s\n",Ldisciplinas[i].codigo);
          printf("Semestre: %d°\n",Ldisciplinas[i].semestre);
  }     

}
void cadastrarAlunoDisplina(dpn Ldisciplinas[],cad Lalunos[],int qtd_disciplinas,int qtd_alunos){

  int pos_disciplina,pos_aluno,i;
  int idDisciplina,matricula;
  int qtd_matriculados;

  listarDisciplinas(Ldisciplinas,qtd_disciplinas);

  printf("Digite o Id da disciplina: ");
  scanf("%d",&idDisciplina);

  for(i = 0; i < qtd_disciplinas;i++){
    if(idDisciplina == Ldisciplinas[i].id)
      pos_disciplina = i;
  }


  listar(Lalunos,qtd_alunos);

  printf("Digite a matricula do aluno: ");
  scanf("%d",&matricula);

  for(i = 0; i < qtd_alunos; i++){
    if(matricula == Lalunos[i].matricula)
      pos_aluno = i ;
  }
  qtd_matriculados = Ldisciplinas[pos_disciplina].qtd_matriculados;
  Ldisciplinas[pos_disciplina].matriculados[qtd_matriculados] = Lalunos[pos_aluno];
  
  Ldisciplinas[pos_disciplina].qtd_matriculados++;


}

void listarMatriculados(dpn Ldisciplinas[],int qtd_disciplinas){
  int i;
  int idDisciplina,pos_disciplina;
  
  listarDisciplinas(Ldisciplinas,qtd_disciplinas);

  printf("Digite o Id da disciplina: ");
  scanf("%d",&idDisciplina);
  
  //Busca a posição da disciplina escolhoda
  for(i = 0; i < qtd_disciplinas;i++){
    if(idDisciplina == Ldisciplinas[i].id)
      pos_disciplina = i;
  }
    printf("******Matrículados em %s*******\n",Ldisciplinas[pos_disciplina].nome);
  for(i = 0; i < Ldisciplinas[pos_disciplina].qtd_matriculados;i++){
        printf("Aluno(a) %d: %s\n",i,Ldisciplinas[pos_disciplina].matriculados[i].nome);    
    }

}

void excluirMatriculado (dpn Ldisciplinas[],int qtd_disciplinas){

  int i,qtd_matriculados,pos_aluno;
  int idDisciplina,pos_disciplina;

  listarDisciplinas(Ldisciplinas,qtd_disciplinas);
  printf("Digite o Id da disciplina: ");
  scanf("%d",&idDisciplina);

  //Busca a posição da disciplina escolhoda
  for(i = 0; i < qtd_disciplinas;i++){
    if(idDisciplina == Ldisciplinas[i].id)
      pos_disciplina = i;
  }

  printf("******Matrículados em %s*******\n",Ldisciplinas[pos_disciplina].nome);
  for(i = 0; i < Ldisciplinas[pos_disciplina].qtd_matriculados;i++){
        printf("Aluno(a) %d: %s\n",i,Ldisciplinas[pos_disciplina].matriculados[i].nome);}
    
  printf("Digite o número do Aluno: ");
  scanf("%d",&pos_aluno);

  qtd_matriculados = Ldisciplinas[pos_disciplina].qtd_matriculados;

  for(i = pos_aluno; i < qtd_matriculados;i++){
    Ldisciplinas[pos_disciplina].matriculados[i] = Ldisciplinas[pos_disciplina].matriculados[i + 1];
      }
  
   Ldisciplinas[pos_disciplina].qtd_matriculados--; 
  }  