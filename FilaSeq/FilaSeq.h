#include<stdio.h>
#include<stdlib.h>

#define MAX 5

 struct aluno {
 	int codigo;
 	float media;
 	char nome[30];
 }; 


typedef struct aluno Aluno;
typedef struct fila Fila;



Fila *criaFila();

int tamanhoFila(Fila *ptrFila);

int filaCheia(Fila *ptrFila);

int filaVazia(Fila *ptrFila);

int insereFila(Fila *ptrFila, Aluno regAluno);

int removeFila(Fila *ptrFila);

int consultaFila(Fila *ptrFila, Aluno *regAluno);

void liberaFila(Fila *ptrFila);


void exibeElementos(Fila *ptrFila);






