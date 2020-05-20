#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "ListaDinEncad.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};


typedef struct elemento Elemento;


Lista *criaLista(){
	Lista *ptrLi;
	
	ptrLi = (Lista * ) malloc (sizeof(Lista));
	
	if(ptrLi == NULL){
		printf("Não foi possível criar a lista \n");
		return 0;
	
	}else{
		*ptrLi = NULL;
		return ptrLi;
	}
	
	
}

int tamanhoLista(Lista *ptrLi){
	int cont = 0;
	
	if(ptrLi == NULL){
		return -1;
	}
	
	Elemento *no = *ptrLi;
	
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	
	return cont;
}


int listaCheia(Lista *ptrLi){
	return 0;
}

int listaVazia(Lista *ptrLi){
	if(ptrLi == NULL){
		return -1;
	
	}else if(*ptrLi == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

int insereInicioLista(Lista *ptrLi, Aluno regAluno){
	if(ptrLi == NULL){
		printf("Lista inexistente");
		return -1;
	}
	
	Elemento* no = (Elemento*) malloc(sizeof(Elemento));
	
	if(no == NULL)
		return 0;
	
	no->dados = regAluno;
	no->prox = *ptrLi;
	*ptrLi = no;
	
	
	return 1;
}


int insereFinalLista(Lista *ptrLi, Aluno regAluno){
	
	Elemento* no = (Elemento*) malloc(sizeof(Elemento));
	
	if(ptrLi == NULL){
		printf("Lista inexistente");
		return -1;
	}else{
		
		
		no->dados = regAluno;
		no->prox = NULL;
		
		if(*ptrLi == NULL){
			*ptrLi = no;
		
		}else{
			
			Elemento* aux;
			aux = *ptrLi;
				
				while(aux->prox != NULL){
					aux = aux->prox;
				}
			aux->prox = no;
		}
		
		
		return 1;
		
	}
}


int insereOrdenada(Lista *ptrLi, Aluno regAluno){
	
	if(ptrLi == NULL){
		return -1;
	}

	Elemento *no;
	no = (Elemento*) malloc(sizeof(Elemento));
	
	no->dados = regAluno;
	
	
	//Lista vazia insere no ínicio
	if(*ptrLi == NULL)
	{
		no->prox = NULL;
		*ptrLi = no;
		return 1;
		
		printf("Lista vazia - inserindo no início da lista\n");
	
	}
	else
	{
		Elemento *ant, *atual = *ptrLi;
		
		while(atual != NULL && atual->dados.matricula < regAluno.matricula)
		{
			ant = atual;
			atual = atual->prox;
		}
		
		if(atual == *ptrLi)
		{	//Insere no início
			no->prox = *ptrLi;
			*ptrLi = no;
		
		}else
		{	//Insere entre os elementos
			no->prox = atual;
			ant->prox = no;
		}
		
		return 1;	
	}
	
}

int exibeElementos(Lista *ptrLi){
	if(ptrLi == NULL){
		printf("Não foi possível exibir os elementos da lista \n");
		return 0;
	}else{
		printf("-------------- Exibindo elementos na lista -----------------\n");
		
		int cont = 0;
		Elemento *no;
		
		no = *ptrLi;
		
		while(no != NULL)
		{	
			printf("Elemento [%d] da lista - %s - Matrícula: %d \n", cont, no->dados.nome, no->dados.matricula);
			cont++;
			no = no->prox;		
		}
	}
}


int buscaElementoPos(Lista *ptrLi, int pos, Aluno *ptrAluno){
	if(ptrLi == NULL || pos < 0){
		return -1;
	}
	
	Elemento *no = *ptrLi;
	
	int i = 0;
	
	while(no != NULL && i < pos){
		no = no->prox;
		i++;
	}
	
	//Elemento não encontrado
	if(no == NULL){
		return 0;
	
	}else{
		*ptrAluno = no->dados;
		return 1;
	}
}


int buscaElementoMat(Lista *ptrLi, int mat, Aluno *ptrAluno){
	if(ptrLi == NULL){
		return -1;
	}
	
	Elemento *no = *ptrLi;
	
	while(no !=NULL && no->dados.matricula != mat){
		no = no->prox;
	}
	
	if(no == NULL){
		printf("Elemento não encontrado na lista \n");
	
	}else{
		*ptrAluno = no->dados;
		return 1;
	}
	
}

int removeListaInicio(Lista *ptrLi, Aluno *ptrAluno){
	if(ptrLi == NULL){
		return -1;
	}
	
	Elemento *no = *ptrLi;
	
	*ptrLi = no->prox;
	*ptrAluno = no->dados;
	
	free(no);
	return 1;
}

int removeListaFinal(Lista *ptrLi, Aluno *ptrAluno){
	if(ptrLi == NULL){
		return -1;
	}
	
	Elemento *ant, *no = *ptrLi;
	
	while(no->prox != NULL)
	{
		ant = no;
		no = no->prox;
	}
	
	//Remove o primeiro elemento?
   if(no == *ptrLi){
   		*ptrLi = no->prox;
   
   }else{
   	
	   ant->prox = no->prox;
   	   *ptrAluno = no->dados;	
   	   free(no);
   }
   
   return 1;
}

int removeLista(Lista *ptrLi, int mat){
	if(ptrLi == NULL){
		return -1;
	}
	
	Elemento *ant, *no = *ptrLi;
	
	while(no != NULL && no->dados.matricula != mat)
	{
		ant = no;
		no = no->prox;
	}
	
	if(no == *ptrLi)
	{
		*ptrLi = no->prox;
	
	}else{
		ant->prox = no->prox;
		free(no);
	}
	
	return 1;
}

Lista *liberaLista(Lista *ptrLi){
	Elemento *no;
	
	if(ptrLi != NULL)
	{
		while((*ptrLi) != NULL)
	{
		no = *ptrLi;
		*ptrLi = (*ptrLi)->prox;
		free(no);
	}
	
		free(ptrLi);
		ptrLi = NULL;	
	}
	
	return ptrLi;
}
