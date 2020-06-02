#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "FilaDin.h"


typedef struct elemento{
	struct aluno dados;
	struct elemento *prox;
};


typedef struct elemento Elemento;

typedef struct fila{
	
	struct elemento *inicio;
	struct elemento *final;
	int qtd;
};



Fila *cria_fila(){
	
	Fila *ptrFila;
	
	ptrFila = (Fila*) malloc (sizeof(struct fila));
	
	if(ptrFila != NULL)
	{
		ptrFila->inicio = NULL;
		ptrFila->final = NULL;
		ptrFila->qtd = 0;
	} 
	
	return ptrFila;
}


int tamanhoFila(Fila *ptrFila){
	
	if(ptrFila == NULL)
		return -1;
	else
		return ptrFila->qtd;
}


int filaCheia(Fila *ptrFila){
	
	return 0;
}


int filaVazia(Fila *ptrFila){
	if(ptrFila == NULL)
		return -1;
	else if(ptrFila->qtd == 0)
		return 1; // Fila Vazia
	else 
		return 0; // Fila não vazia
}

int insereFila(Fila *ptrFila, Aluno regAluno){
	
	if(ptrFila == NULL)
		return -1; 
	
	Elemento *no = (Elemento*) malloc (sizeof(Elemento));
	if(no == NULL)
		return 0; //Fila Cheia
	else
	{
		no->dados = regAluno;
		no->prox = NULL;
		
		if(ptrFila->final == NULL){
			ptrFila->inicio = no; //Fila vazia
		
		}else
			ptrFila->final->prox = no;
			ptrFila->final = no;
			ptrFila->qtd++;
			
			return 1;  //Elemento inserido na fila
	}
}

int consultaFila(Fila *ptrFila, Aluno *ptrAluno){
	if(ptrFila == NULL){
		return -1;
	
	}else if(ptrFila->inicio == NULL){
		*ptrAluno = ptrFila->inicio->dados;
		return 1; 	// Elemento acessado
	}
}


int removeFila(Fila *ptrFila, Aluno *ptrAluno){
	if(ptrFila == NULL){
		return -1;
	
	}else if(ptrFila->inicio == NULL){
		return 0;
	
	}else{
		printf("Entrou no else \n");
		
		Elemento *no = ptrFila->inicio;
		ptrFila->inicio = ptrFila->inicio->prox;
		
		*ptrAluno = no->dados; //Acessando os dados excluídos
		
		free(no);
		
		if(ptrFila->inicio == NULL) //Fila ficou vazia
		
			ptrFila->final = NULL;
			ptrFila->qtd--;
			return 1;
		
	}
}

void liberaFila(Fila *ptrFila){
	if(ptrFila != NULL){
		
	Elemento *no;
	
		while(ptrFila->inicio != NULL)
		{
			no = ptrFila->inicio;
			ptrFila->inicio = ptrFila->inicio->prox;
			free(no);
		}	
	
		free(ptrFila);
		printf("Fila removida \n");
	}
}









//void exibeElementos(Fila *ptrFila){
//	int i;
//	
//	Elemento *no = ptrFila->inicio;
//	
//	printf("-------------------------- Exibindo elementos da fila ---------------------------- \n");
//	for(i = 0; i< ptrFila->qtd; i++)
//	{
//		
//		printf("- %s - Elemento[%d] \n", no->dados.nome, i);
//		no = ptrFila->inicio->prox;
//	}
//}
