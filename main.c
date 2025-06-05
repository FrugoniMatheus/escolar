#include <stdio.h>
#define MAX 5

int alunoAprovado = 0;
int alunoReprovado = 0;

typedef struct{
  char nome[50];
  int idade;
  float notaFinal;
} AlunoEscolar;


AlunoEscolar ae[MAX];

void informarDadosAlunos(AlunoEscolar alunoE[]){
  int i = 0;
  for(i = 0; i < MAX; i++){
    printf("Digite o %d nome: ", i + 1);
    fgets(alunoE[i].nome, 50, stdin);
    // alunoE[i].nome[strspn(alunoE[i].nome, "\n")] = 0;
    printf("Informe a idade: ");
    scanf("%d", &alunoE[i].idade);
    getchar();
    printf("Informe a Nota Final: ");
    scanf("%f", &alunoE[i].notaFinal);
    getchar();
  }
}

void impressaoDadosAluno(AlunoEscolar aEscolar[], int vetorAluno){
  printf("\nNome informado do 1:  %s \n", aEscolar[vetorAluno].nome);
  printf("Idade informado do 1: %d\n", aEscolar[vetorAluno].idade);
  printf("Nota Final informado do 1: %.2f\n", aEscolar[vetorAluno].notaFinal);
}

void impressaoDadosAlunos(AlunoEscolar aE[]){
  int i = 0;
  for(i = 0; i < MAX; i++){
    impressaoDadosAluno(aE, i);
  }
}

void validadorDeStatusAlunos(AlunoEscolar alEs[]){
  int i = 0;
  for(i = 0; i < MAX ; i++){
    if(alEs[i].notaFinal >= 6.0){
      alunoAprovado = alunoAprovado + 1 ;
    } else if(alEs[i].notaFinal < 5.9){
      alunoReprovado = alunoReprovado + 1 ;
    } else{
      printf("Erro");
    }
  }
}

void impressaoStatusAlunos(){
  printf("Alunos Aprovados: %d\n", alunoAprovado);
  printf("Alunos Reprovados: %d", alunoReprovado);
}

void iniciarPrograma(){

  informarDadosAlunos(ae);
  impressaoDadosAlunos(ae);
  validadorDeStatusAlunos(ae);
  impressaoStatusAlunos();
}

int main(){
  iniciarPrograma();
  return 0;
}