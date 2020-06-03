#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 5
 
 
 struct aluno{
 	int matricula;
 	char nome[30];
 	float nota;
 };
 
 
 typedef struct aluno Aluno;
 typedef struct pilha Pilha;
 
 
 Pilha* criaPilha();
 
 int tamanhoPilha(Pilha *ptrPilha);
 
 int pilhaVazia(Pilha *ptrPilha);
 
 int pilhaCheia(Pilha *ptrPilha);
 
 
 
 int inserePilha(Pilha *ptrPilha, Aluno regAluno);
 
 int acessaTopo(Pilha *ptrPilha, Aluno *ptrAluno);
 
 int removePilhaInicio(Pilha *ptrPilha, Aluno *ptrAluno);
 
 
 Pilha* liberaPilha(Pilha *ptrPilha);
