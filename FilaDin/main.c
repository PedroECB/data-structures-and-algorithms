#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
#include<locale.h>

							/* Fila Dinâmica encadeada    \n*/

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int flag;
	Fila *ptrFila;
	Aluno *ptrAluno;
	Aluno regAluno;
	ptrAluno = &regAluno;
	
	char op;	
	
	
	//Criando uma fila
	
	
	ptrFila = cria_fila();
	printf("Mostrando endereço da fila que foi criada: %d \n", &ptrFila);
	
	
	//Verificando o tamanho da fila que acabou de ser criada
	
	flag = tamanhoFila(ptrFila);
	
	printf("Tamnho da fila que acabou de ser criada: %d", flag);
	
	
	//Inserindo um elemento na fila
	
	strcpy(regAluno.nome, "Pedro");
	regAluno.matricula = 1;
	regAluno.nota = 9.2;
	
	flag = insereFila(ptrFila, regAluno);
	
	if(flag == 1){
		printf("O aluno %s foi inserido na fila \n", regAluno.nome);
		int tam = tamanhoFila(ptrFila);
		printf("Tamanho da fila após a inserção de %s = %d \n", ptrAluno->nome, tam); 
	}else{
		printf("Erro ao tentar inserer elemento na fila");
	}
	
	
	//Inserindo elemento para ser consultado
	
	strcpy(regAluno.nome, "João");
	regAluno.matricula = 2;
	regAluno.nota = 8.2;
	flag = insereFila(ptrFila, regAluno);
	printf("Flag após inserir o segundo elemento na lista: %d\n ", flag);
	
	flag = removeFila(ptrFila, ptrAluno);
	
	printf("Removendo elemento da fila \n");
	if(flag == 1){
		printf("Elemento que foi removido da fila: %s \n", regAluno.nome);
	
	}else{
		printf("Não foi possível remover o elemento da fila, flag = %d \n", flag);
	}
	
	//Removendo fila
	
	liberaFila(ptrFila);
	
	return 0;
}
