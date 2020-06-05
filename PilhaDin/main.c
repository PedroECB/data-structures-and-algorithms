#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "PilhaDin.h"
						/* Pilha din�mica encadeada \n*/

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int flag;
	Pilha *ptrPilha;
	Aluno *ptrAluno;
	Aluno regAluno;
	ptrAluno = &regAluno;
	
	//Criando a pilha 
	
	ptrPilha =  criaPilha();
	
	if(ptrPilha != NULL){
		printf("Endere�o da pilha que acabou de ser criada: %d \n", ptrPilha);
	}
	
	//Verificando o tamanho da pilha
	
	flag = tamanhoPilha(ptrPilha);
	
	if(flag == -1){
		printf("N�o foi poss�vel verificar o tamanho da fila \n");
	
	}else{
		printf("Tamanho da pilha: %d \n", flag);
	}
	
	//Verificando se uma pilha est� cheia
	
	
	flag = pilhaCheia(ptrPilha);
	
	if(flag == 0)
		printf("A pilha n�o est� cheia \n");
	
	
	//Verificando se uma pilha est� vazia
	
	flag = pilhaVazia(ptrPilha);
	
	if(flag == 1){
		printf("A pilha est� vazia \n");
	}
	
	
	//Criando elemento para ser inserido na pilha
	
	regAluno.matricula = 1;
	regAluno.nota = 7.0;
	strcpy(regAluno.nome, "Pedro");
	
	flag = inserePilha(ptrPilha, regAluno);
	
	if(flag == 1){
		printf("Elemento que foi inserido na pilha: %s \n", regAluno.nome);
	}else{
		printf("N�o foi poss�vel inserir o elemento %s na pilha \n", regAluno.nome);
	}
	
	regAluno.matricula = 2;
	regAluno.nota = 8.0;
	strcpy(regAluno.nome, "Jo�o");
	flag = inserePilha(ptrPilha, regAluno);
	
	regAluno.matricula = 3;
	regAluno.nota = 9.0;
	strcpy(regAluno.nome, "Carlos");
	flag = inserePilha(ptrPilha, regAluno);
	
	
	//Acessando elemento no topo da pilha
	
	flag = acessaTopoPilha(ptrPilha, ptrAluno);
	
	if(flag == 1){
		printf("Elemento que est� no topo da pilha: %s \n", ptrAluno->nome);
	
	}else{
		printf("N�o foi poss�vel acessar o elemento do topo da pilha \n");
	}
	
	
	
	//Remnovendo elemento da pilha
	
	flag = removePilhaInicio(ptrPilha, ptrAluno);
	
	if(flag == 1 ){
		printf("Elemento que foi removido do topo da pilha: %s, \n", ptrAluno->nome);
	
	}else{
		printf("N�o foi poss�vel remover o elemento da piha \n");
	}
	
	flag = tamanhoPilha(ptrPilha);
	printf("Tamnho da pilha ap�s a remo��o de %s = %d \n", ptrAluno->nome, flag);
	
	
	
	ptrPilha = liberaPilha(ptrPilha);
	
	if(ptrPilha == NULL)
		printf("Pilha removida com sucesso! \n");
	
	
	
	
	
	
	
	return 0;
}
