#include<stdio.h>
#include<stdlib.h>
#include "PilhaDin.h"

struct elemento{
	Aluno dados;
	struct elemento*prox;
};

typedef struct elemento Elemento;

Pilha* criaPilha(){
	Pilha *ptrPilha;
	ptrPilha = (Pilha *) malloc (sizeof(Pilha));
	
	if(ptrPilha != NULL){
		*ptrPilha = NULL;
		return ptrPilha;
	}
}


int tamanhoPilha(Pilha *ptrPilha){
	int cont = 0;
	
	if(ptrPilha == NULL){
		return -1;
	
	}else{
		Elemento *no = *ptrPilha;
		
		while(no != NULL)
		{
			cont++;
			no = no->prox;
		}	
	}
	
	return cont;
}


int pilhaCheia(Pilha *ptrPilha){

	if(ptrPilha == NULL){
		return -1;
	
	}else{
		return 0; 
	}

}

int pilhaVazia(Pilha *ptrPilha){
	if(ptrPilha == NULL)
		return -1;
	else{
		if(*ptrPilha == NULL)
			return 1; //Pilha vazia
		else
			return 0;
	}
}


int inserePilha(Pilha *ptrPilha, Aluno regAluno){
	if(ptrPilha == NULL){
		return -1;
	
	}else
	{
		
		Elemento *no;
		no = (Elemento*) malloc (sizeof(Elemento));
		
		if(no == NULL){
			return 0;
		
		}else{
			no->dados = regAluno;
			no->prox = *ptrPilha;
			*ptrPilha = no;
			
			return 1; // Elemento inserido na pilha
		}	
	}
}


int acessaTopoPilha(Pilha *ptrPilha, Aluno *ptrAluno){
	
	if(ptrPilha == NULL)
		return -1;
	else if(*ptrPilha == NULL)
		return 0;
	
	else
	{
		*ptrAluno = (*ptrPilha)->dados;
		
		return 1;
	}
	
	
}



int removePilhaInicio(Pilha *ptrPilha, Aluno *ptrAluno){
	if( ptrPilha == NULL){
		return -1;
	
	}else if(*ptrPilha == NULL){
		return 0;
	
	}else
	{
		Elemento *no = *ptrPilha;
		*ptrAluno = no->dados;
		*ptrPilha = no->prox;
		
		free(no);
		
		return 1;
			
	}
}

Pilha* liberaPilha(Pilha *ptrPilha){
	
	if(ptrPilha != NULL)
	{
		Elemento *no;
		
		while(*ptrPilha != NULL)
		{
			no = *ptrPilha;
			*ptrPilha = (*ptrPilha)->prox;
			free(no); 
		}
		
		free(ptrPilha);
			
	}
	
	return ptrPilha = NULL;
}
