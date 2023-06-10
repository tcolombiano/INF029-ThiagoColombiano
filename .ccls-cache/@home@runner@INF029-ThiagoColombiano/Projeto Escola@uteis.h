#define Sucesso_Cadastro 0
#define Erro_Cadastro_Matricula -1
#define Erro_Cadastro_Nome -2
#define Erro_Cadastro_Cpf -3
#define Erro_Cadastro_Sexo -4
#define Erro_Cadastro_Data -5
#define TAM 5


typedef struct{
  char nome [30];
  char cpf[11];
  char sexo;
  int dia;
  int mes;
  int ano;
  int matricula; 
}cad;  

  int buscarCad(cad lista[],int qtd_cadastros);
  

int cadastrar(cad pessoas[],int qtd_cadastros){

    getchar();
   printf("\n********** F I C H A ****************\n");
    
    printf("Digite o nome : ");
    fgets(pessoas[qtd_cadastros].nome,30,stdin);
    
   
    
    size_t ln = strlen(pessoas[qtd_cadastros].nome) - 1;
    if (pessoas[qtd_cadastros].nome[ln] == '\n')
     pessoas[qtd_cadastros].nome[ln] = '\0';
     
     //Validação do nome
    int numCarateres= 0;
    while (pessoas[qtd_cadastros].nome[numCarateres] != '\0'){
      numCarateres++;}
    printf("%d carateres\n",numCarateres); //para teste
    if(numCarateres > 20)
      return Erro_Cadastro_Nome;

    //-------------------------
    printf("Digite o CPF : ");
    fgets(pessoas[qtd_cadastros].cpf,20,stdin);

    ln = strlen(pessoas[qtd_cadastros].cpf) - 1;
    if (pessoas[qtd_cadastros].cpf[ln] == '\n')
        pessoas[qtd_cadastros].cpf[ln] = '\0';

    // Validação do CPF
    numCarateres= 0;
    while (pessoas[qtd_cadastros].cpf[numCarateres] != '\0'){
      numCarateres++;}
    
    printf("%d carateres\n",numCarateres); //para teste
    if(numCarateres != 11  ){
      return Erro_Cadastro_Cpf;}

    //----------------------
    printf("Digite o sexo: ");
    scanf("%c",&pessoas[qtd_cadastros].sexo);

    pessoas[qtd_cadastros].sexo = toupper(pessoas[qtd_cadastros].sexo);
    if (pessoas[qtd_cadastros].sexo != 'M' && pessoas[qtd_cadastros].sexo != 'F')
    {
        return Erro_Cadastro_Sexo;
    }
    
    //---------------------
    printf("Digite o dia do seu nascimento: ");
    scanf("%d",&pessoas[qtd_cadastros].dia);

    if(pessoas[qtd_cadastros].dia > 31 ||pessoas[qtd_cadastros].dia < 1)
      return Erro_Cadastro_Data;

    printf("Digite o mês do seu nascimento: ");
    scanf("%d",&pessoas[qtd_cadastros].mes);
    
    if(pessoas[qtd_cadastros].mes > 12 ||pessoas[qtd_cadastros].mes < 1)
      return Erro_Cadastro_Data;

    printf("Digite o ano do seu nascimento: ");
    scanf("%d",&pessoas[qtd_cadastros].ano);

    if(pessoas[qtd_cadastros].ano >2007  ||pessoas[qtd_cadastros].ano < 1921)
      return Erro_Cadastro_Data;

    //-------------
    pessoas[qtd_cadastros].matricula = qtd_cadastros + 1;
    
    return Sucesso_Cadastro;
}



void listar(cad pessoa[],int qtd_cadastros){
  int i ;
  for(i = 0; i < qtd_cadastros; i++){
        printf("*********************\n");
        printf("Nome: %s\n",pessoa[i].nome);
        printf("CPF: %s",pessoa[i].cpf);
        printf("\nSexo: %c \n",pessoa[i].sexo);
        printf("Dia: %d/%d/%d \n",pessoa[i].dia,pessoa[i].mes,pessoa[i].ano);
        printf("Matrícula: %d\n",pessoa[i].matricula);
  }
}

  int atulizarCad(cad pessoa[], int qtd_cadastros){
  int pos,conf;
    printf("Veja a lista e digite a matricula de quem deseja atualizar. ");
  listar(pessoa ,qtd_cadastros);
  pos = buscarCad(pessoa,qtd_cadastros);

  conf = cadastrar(pessoa,pos);
  return conf;
}

int excluirCad (cad pessoa[], int qtd_cadastros){
  int pos,i;
  printf("Veja a lista e digite a matricula de quem deseja atualizar. ");
  listar(pessoa ,qtd_cadastros);
  pos = buscarCad(pessoa,qtd_cadastros);

  for(i = pos; i < qtd_cadastros; i++){
      pessoa[i] = pessoa[i + 1];
  }
  qtd_cadastros--;
  return qtd_cadastros;
}

int buscarCad(cad lista[],int qtd_cadastros){
  int matricula, i;
  printf("Digite a matricula: ");
  scanf("%d",&matricula);

  for(i = 0; i < qtd_cadastros; i++){
    if(matricula == lista[i].matricula)
      return i ;
  }
  printf("Não encontrado");
  
  return 0;
}