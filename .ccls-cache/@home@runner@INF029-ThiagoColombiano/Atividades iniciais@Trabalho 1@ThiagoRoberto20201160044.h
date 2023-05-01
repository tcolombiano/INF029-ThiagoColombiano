//  ----- Dados do Aluno -----
//  Nome: Thiago Roberto
//  email: tcolombiano@hotmail.com
//  Matrícula:20201160044
//  Semestre: 2°

typedef struct{
  int sDia;
	int sMes;
	int sAno;
  int valido;
}Data;

int q1(char *data);
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

