#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "PilhaSeq.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop \n*/

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int flag;
	Pilha *ptrPilha;
	Aluno *ptrAluno;
	Aluno regAluno;
	ptrAluno = &regAluno;
	
	
	//Criando pilha
	
	ptrPilha = criaPilha();
	
	printf("Endereço da pilha criada: %d \n", &ptrPilha);
	
	
	
	//Verificando tamanho da pilha
	
	flag = tamanhoPilha(ptrPilha);
	printf("Tamanho da pilha que acabou de ser criada: %d \n", flag);
	
	
	//Verificando se uma pilha está cheia
	
	flag = pilhaCheia(ptrPilha);
	
	if(flag == 1)
		printf("A pilha está cheia \n");
	else if(flag == 0)
		printf("A pilha não está cheia \n");
	else
	 printf("Falha na verificação da pilha");
	 
	 
	//Verificando se a fila está vazia
	 
	 flag = pilhaVazia(ptrPilha);
	 
	 if(flag == 1)
	 	printf("A pilha está vazia \n");
	 else
	 	printf("A pilha não está vazia \n");
	 	
	 
	 
	 //Criando elemento para inserir na pilha
	 
	 regAluno.matricula = 1;
	 regAluno.nota = 9.2;
	 strcpy(regAluno.nome, "Pedro");
	 flag = inserePilha(ptrPilha, regAluno);
	 
	 if(flag == 1)
	 	printf("O elemento %s foi inserido na pilha \n", regAluno.nome);
	 else
	  printf("Falha ao tentar inserir elemento na pilha \n");
	
	 regAluno.matricula = 3;
	 regAluno.nota = 9.2;
	 strcpy(regAluno.nome, "Acessando elemento do topo da pilha");
	 flag = inserePilha(ptrPilha, regAluno);
	
	 regAluno.matricula = 2;
	 regAluno.nota = 9.2;
	 strcpy(regAluno.nome, "Carlos");
	 flag = inserePilha(ptrPilha, regAluno);
	 

	 
	 //Acessando elemento do topo da pilha
	
	 flag = acessaTopo(ptrPilha, ptrAluno);
	 
	 if(flag == 1)
	 	printf("Elemento no topo da pilha: %s \n", regAluno.nome);
   	 else 
		printf("Falha ao acessar elemento do topo da pilha \n");
	
	
	//Removendo elemento da pilha (removendo do início)
	
	flag = removePilhaInicio(ptrPilha, ptrAluno);
	
	if(flag == 1)
	 	printf("Elemento removido da pilha : %s \n", regAluno.nome);
	else
	printf("Falha ao remover elemento da pilha \n");
	
	
	liberaPilha(ptrPilha);
	
	printf("Pilha liberada com sucesso!");
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
