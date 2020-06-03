#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "PilhaSeq.h"

struct pilha{
	int qtd;
	Aluno dados[5];
};



Pilha *criaPilha(){
	
	Pilha *ptrPilha;
	ptrPilha = (Pilha*) malloc (sizeof(struct pilha));

	if(ptrPilha != NULL)
		ptrPilha->qtd = 0;
	
	return ptrPilha;
}

int tamanhoPilha(Pilha *ptrPilha){
	if(ptrPilha == NULL)
		return -1;
	 else
	 return ptrPilha->qtd;
}

int pilhaCheia(Pilha *ptrPilha){
	if(ptrPilha == NULL)
		return -1;
	else
		return (ptrPilha->qtd == 5);
}


int pilhaVazia(Pilha *ptrPilha){
	if(ptrPilha == NULL)
		return -1;
	else
		return (ptrPilha->qtd == 0);
}


int inserePilha(Pilha *ptrPilha, Aluno regAluno){
	if(ptrPilha == NULL)
		return -1;
	else if(pilhaCheia(ptrPilha))
		return -1; //Pilha cheia
	else
		ptrPilha->dados[ptrPilha->qtd] = regAluno;
		ptrPilha->qtd++;
	return 1;
}

int acessaTopo(Pilha *ptrPilha, Aluno *ptrAluno){
	if(ptrPilha == NULL)
		return -1;
	else if(pilhaVazia(ptrPilha))
		return -1;
	else
	*ptrAluno = ptrPilha->dados[(ptrPilha->qtd-1)];
	return 1; // Elemento acessado
		
}

int removePilhaInicio(Pilha *ptrPilha, Aluno *ptrAluno){
	if(ptrPilha == NULL)
		return -1;
	else if(ptrPilha->qtd == 0)
		return -1;
	else
	 {
	 	*ptrAluno = ptrPilha->dados[ptrPilha->qtd-1];
	 	ptrPilha->qtd--;
	 	
	 	return 1;
	 }
	 
}

Pilha* liberaPilha(Pilha *ptrPilha){
	free(ptrPilha);
	
	return ptrPilha = NULL;
}




