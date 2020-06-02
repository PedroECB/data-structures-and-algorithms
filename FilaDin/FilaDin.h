#include<stdio.h>
#include<stdlib.h>
#include<locale.h>



struct aluno{
	int matricula;
	char nome[30];
	float nota;
};



typedef struct aluno Aluno;
typedef struct fila Fila;

Fila *cria_fila();

int tamanhoFila(Fila *ptrFila);

int filaCheia(Fila *ptrFila);

int filaVazia(Fila *ptrFila);

int insereFila(Fila *ptrFila, Aluno regAluno);

int consultaFila(Fila *ptrFila, Aluno *ptrAluno);

int removeFila(Fila *ptrFila, Aluno *ptrAluno);

void liberaFila(Fila *ptrFila);




void exibeElementos(Fila *ptrFila);
