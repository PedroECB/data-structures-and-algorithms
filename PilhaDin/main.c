#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "PilhaDin.h"
						/* Pilha dinâmica encadeada \n*/

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
		printf("Endereço da pilha que acabou de ser criada: %d \n", ptrPilha);
	}
	
	//Verificando o tamanho da pilha
	
	flag = tamanhoPilha(ptrPilha);
	
	if(flag == -1){
		printf("Não foi possível verificar o tamanho da fila \n");
	
	}else{
		printf("Tamanho da pilha: %d \n", flag);
	}
	
	//Verificando se uma pilha está cheia
	
	
	flag = pilhaCheia(ptrPilha);
	
	if(flag == 0)
		printf("A pilha não está cheia \n");
	
	
	//Verificando se uma pilha está vazia
	
	flag = pilhaVazia(ptrPilha);
	
	if(flag == 1){
		printf("A pilha está vazia \n");
	}
	
	
	//Criando elemento para ser inserido na pilha
	
	regAluno.matricula = 1;
	regAluno.nota = 7.0;
	strcpy(regAluno.nome, "Pedro");
	
	flag = inserePilha(ptrPilha, regAluno);
	
	if(flag == 1){
		printf("Elemento que foi inserido na pilha: %s \n", regAluno.nome);
	}else{
		printf("Não foi possível inserir o elemento %s na pilha \n", regAluno.nome);
	}
	
	regAluno.matricula = 2;
	regAluno.nota = 8.0;
	strcpy(regAluno.nome, "João");
	flag = inserePilha(ptrPilha, regAluno);
	
	regAluno.matricula = 3;
	regAluno.nota = 9.0;
	strcpy(regAluno.nome, "Carlos");
	flag = inserePilha(ptrPilha, regAluno);
	
	
	//Acessando elemento no topo da pilha
	
	flag = acessaTopoPilha(ptrPilha, ptrAluno);
	
	if(flag == 1){
		printf("Elemento que está no topo da pilha: %s \n", ptrAluno->nome);
	
	}else{
		printf("Não foi possível acessar o elemento do topo da pilha \n");
	}
	
	
	
	//Remnovendo elemento da pilha
	
	flag = removePilhaInicio(ptrPilha, ptrAluno);
	
	if(flag == 1 ){
		printf("Elemento que foi removido do topo da pilha: %s, \n", ptrAluno->nome);
	
	}else{
		printf("Não foi possível remover o elemento da piha \n");
	}
	
	flag = tamanhoPilha(ptrPilha);
	printf("Tamnho da pilha após a remoção de %s = %d \n", ptrAluno->nome, flag);
	
	
	
	ptrPilha = liberaPilha(ptrPilha);
	
	if(ptrPilha == NULL)
		printf("Pilha removida com sucesso! \n");
	
	
	
	
	
	
	
	return 0;
}
