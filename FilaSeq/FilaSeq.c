#include<stdio.h>
#include<stdlib.h>
#include "FilaSeq.h"

struct fila{
	int qtd;
	int inicio;
	int final;
	Aluno dados[MAX];
};



Fila *criaFila(){
	
	Fila *ptrFila;
	ptrFila =  (Fila *) malloc(sizeof(struct fila));
	
	if(ptrFila != NULL)
	{
		ptrFila->inicio = 0;
		ptrFila->final = 0;
		ptrFila->qtd = 0;
	}
	
	return ptrFila;
}

int tamanhoFila(Fila *ptrFila)
{
	if(ptrFila == NULL)
	{
		return -1;
	}else{
		return ptrFila->qtd;
	}
}


int filaCheia(Fila *ptrFila)
{
	if(ptrFila == NULL)
		return -1;
	
	else if(ptrFila->qtd == MAX)
		return 1; //Fila cheia
	
	else
		return 0; //Fila não cheia
}


int filaVazia(Fila *ptrFila)
{
	if(ptrFila == NULL)
		return -1;
	else if(ptrFila->qtd == 0)
		return 1; //Fila vazia
	else 
		return 0; //Fila não está vazia
}

int insereFila(Fila *ptrFila, Aluno regAluno)
{
	if(ptrFila == NULL)
		return -1;
	else{
		ptrFila->dados[ptrFila->final] = regAluno;
		ptrFila->final = (ptrFila->final+1)%MAX;
		ptrFila->qtd++;
	}
	
	return 1;
		
}

int removeFila(Fila *ptrFila)
{
	if(ptrFila == NULL)
		return -1;
	
	else{
		ptrFila->inicio = (ptrFila->inicio+1)%MAX;
		ptrFila->qtd--;
	}
	
	return 1;
}


int consultaFila(Fila *ptrFila, Aluno *regAluno)
{
	if(ptrFila == NULL)
		return -1;
	else if(ptrFila->qtd == 0)
		return 0;
	else
	 *regAluno = ptrFila->dados[ptrFila->inicio];
	 
	 return 1;
}


void liberaFila(Fila *ptrFila)
{
	ptrFila = NULL;
	free(ptrFila);
}



void exibeElementos(Fila *ptrFila)
{
	int i;
	
	printf("------------------- Exibindo elementos da lista ----------------- \n");
	for(i = 0; i < ptrFila->qtd; i++)
	{
		printf("Elemento [%d] da fila -- %s \n", i, ptrFila->dados[i].nome);
	}
	
}

