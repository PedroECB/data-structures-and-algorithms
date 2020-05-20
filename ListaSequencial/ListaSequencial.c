#include<stdio.h>
#include<stdlib.h>
#include "ListaSequencial.h"

struct lista
{
	int qtd;
	Aluno dados[MAX];
};



Lista * criaLista(){
	Lista *ptr;
	ptr = (Lista*) malloc(sizeof(struct lista));
	
	if(ptr == NULL){
			printf("Não foi possível criar a lista");
		return;
	}else{
		ptr->qtd = 0;
			
		return ptr;
	}
		
}

int tamanhoLista(Lista *ptrLista){
	if(ptrLista == NULL){
		return -1;
	
	}else{
		return ptrLista->qtd;	
	}
}

int listaCheia(Lista *ptrLista){
	if(ptrLista == NULL)
		return -1;
	else 
		return (ptrLista->qtd == MAX);
		
}

int listaVazia(Lista *ptrLista){
	if(ptrLista == NULL)
		return -1;
	else if(ptrLista->qtd < MAX)
		return 1;
	else 
		return 0;
}

int listaSemElementos(Lista *ptrLista){
	if(ptrLista == NULL)
		return -1;
	else if(ptrLista->qtd == 0)
		return 1;
	else 
		return 0;
}


int insereFinalDaLista(Lista *ptrLista, Aluno regAluno){
	
	int pos;
	
	if(ptrLista == NULL){
		return -1;
	}else if(listaVazia(ptrLista)){
		ptrLista->dados[ptrLista->qtd] = regAluno;
		
		pos = ptrLista->qtd;
		ptrLista->qtd++;
		
		return pos;
	}
	
}

int insereInicioDaLista(Lista *ptrLista, Aluno regAluno){
	int i;
	
	if(ptrLista == NULL){
		return -1;
		
	}else if(listaVazia(ptrLista)){
		
			for(i = (ptrLista->qtd-1); i>=0 ;i--){
				ptrLista->dados[i+1]= ptrLista->dados[i];
			}
		ptrLista->dados[0] = regAluno;
		ptrLista->qtd++;
	}
}



int insereOrdenada(Lista *ptrLista, Aluno regAluno){
	int j, i = 0;
	
	if(ptrLista == NULL){
		return -1;
		
	}else if(listaVazia(ptrLista)){
		
		while(i <ptrLista->qtd && ptrLista->dados[i].codigo < regAluno.codigo){
			i++;
		}
		
		for(j = (ptrLista->qtd - 1);j>=i;j--){
			ptrLista->dados[j+1] = ptrLista->dados[j];
		}
		
		ptrLista->dados[i] = regAluno;
		ptrLista->qtd++;
	}
}


int insereOrdenada2(Lista *ptrLista, Aluno regAluno){
	int i, j;
	Aluno aux;
	
	if(ptrLista == NULL){
		return -1;
	
	}else if(listaVazia(ptrLista)){
			ptrLista->dados[ptrLista->qtd] = regAluno;
			ptrLista->qtd++;
		
		for(i = 0; i<(ptrLista->qtd-1);i++){
			for(j = (i+1); j< (ptrLista->qtd);j++){
				
				if(ptrLista->dados[i].codigo > ptrLista->dados[j].codigo){
					aux = ptrLista->dados[j];
					ptrLista->dados[j] = ptrLista->dados[i];
					ptrLista->dados[i] = aux;
				}
			}
		}
	}
}

int buscaListaPos(Lista *ptrLista, int pos, Aluno *ptrAluno){
	
	if(ptrLista == NULL){
		return -1;
	
	}else if(pos <= 0 || pos > ptrLista->qtd){
		printf("Posição indisponível para busca \n");
		return -1;
	}else{
		*ptrAluno = ptrLista->dados[pos-1];
	}
}


int buscaListaCod(Lista *ptrLista, int codigo, Aluno *ptrAluno){
	
	int i=0;
	
	if(ptrLista == NULL){
		return -1;
	}
	
	while(i<ptrLista->qtd && ptrLista->dados[i].codigo != codigo){
		i++;
	}
	
	
	if(ptrLista->dados[i].codigo == codigo){
		*ptrAluno = ptrLista->dados[i];
			return 1;
	}else{
		printf("Código não encontrado na lista \n");
		return 0;
	}
}

int removendoInicioDaLista(Lista *ptrLista, Aluno *ptrAluno){
	int i;
	
	if(ptrLista == NULL){
		return -1;
		
	}else if(listaSemElementos(ptrLista)){
		return 0;
		
	}else{
		*ptrAluno = ptrLista->dados[0];
		
		for(i = 0; i < ptrLista->qtd-1;i++){
			ptrLista->dados[i] = ptrLista->dados[i+1];
		}
		
		ptrLista->qtd--;
	}
	
	return 1;
}


int removeFinalDaLista(Lista *ptrLista, Aluno *ptrAluno){
	
	if(ptrLista == NULL){
		return -1;
	
	}else if(listaSemElementos(ptrLista)){
		return 0;
	
	}else{
		
		*ptrAluno = ptrLista->dados[(ptrLista->qtd)-1];
		 ptrLista->qtd--;
		 
		 return 1;
		
	}
}

int removeLista(Lista *ptrLista, int codigo){
	int k, i = 0;
	
	if(ptrLista == NULL){
		return -1;
	
	}else if(listaSemElementos(ptrLista)){
		return 0;
	
	}else{
		while(i < ptrLista->qtd && ptrLista->dados[i].codigo != codigo){
			i++;
		}
	
		if(ptrLista->dados[i].codigo != codigo){
			return -1;
		
		}

		for(k = i; k< ptrLista->qtd; k++){
			ptrLista->dados[k] = ptrLista->dados[k+1];
		}
		
		return 1;
	}
		
}


int liberaLista(Lista * ptrLista){
	
	if(ptrLista == NULL){
		return -1;
	}else{
		free(ptrLista);
		return 1;
	}
}


//int buscaListaPos(Lista *ptrLista, int pos, Aluno *ptrAluno){
//	int i = 0;
//	
//	if(ptrLista == NULL){
//		return -1;
//	
//	}else if(pos > MAX){
//		return -1;
//	}else{
//		
//		while()
//	}
//}






int ordena(Lista *ptrLista){
	int i, j;
	Aluno aux;
	
	if(ptrLista == NULL){
		return -1;
	
	}else if(listaVazia(ptrLista)){
			
		
		for(i = 0; i<(ptrLista->qtd-1);i++){
			for(j = (i+1); j< (ptrLista->qtd);j++){
				
				if(ptrLista->dados[i].codigo > ptrLista->dados[j].codigo){
					aux = ptrLista->dados[j];
					ptrLista->dados[j] = ptrLista->dados[i];
					ptrLista->dados[i] = aux;
				}
			}
		}
	}
}



void exibeElementos(Lista *ptrLista){
	int i;
	printf("\n -------------------------- \n");
	printf("Quantidade de elementos na lista: %d\n", ptrLista->qtd);
	
	if(ptrLista == NULL){
		printf("Não é possível listar os elementos da lista. Lista não existe!\n");
		
	}else{
		for(i= 0; i < ptrLista->qtd; i++){
			printf("Elemento[%d] da lista: %s, Código: %d\n", i, ptrLista->dados[i].nome, ptrLista->dados[i].codigo);
		}
	}
}










