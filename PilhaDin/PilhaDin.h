#include<stdio.h>
#include<stdlib.h>


struct aluno{
	int matricula;
	char nome[30];
	float nota;	
};


typedef struct aluno Aluno;
typedef struct elemento *Pilha; //Ponteiro para ponteiro

Pilha *criaPilha();

int tamanhoPilha(Pilha *ptrPilha);

int pilhaVazia(Pilha *ptrPilha);

int pilhaCheia(Pilha *ptrPilha);



int inserePilha(Pilha *ptrPilha, Aluno regAluno);

int acessaTopoPilha(Pilha *ptrPilha, Aluno *ptrAluno);

int removePilhaInicio(Pilha *ptrPilha, Aluno *ptrAluno);

Pilha* liberaPilha(Pilha *ptrPilha);

