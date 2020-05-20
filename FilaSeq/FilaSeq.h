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

int insereFila(Fila *ptrFila);

int consultaFila(Fila *ptrFila);

int removeFila(Fila *ptrFila);

void liberaFila(Fila *ptrFila);







