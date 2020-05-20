#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "FilaSeq.h"

			/* Implementação de uma fila dinâmica sequencial estática */
			//			\n

int main() {
	setlocale(LC_ALL, "portuguese");


	int flag;
	int pos;
	
	Aluno reg_aluno;
	Aluno *ptrAluno;
	ptrAluno = &reg_aluno;
	Fila *ponteiroFila;
	
	//Criando uma fila
	
	ponteiroFila = criaFila();
	
	if(ponteiroFila != NULL)
	{
		printf("Endereço da fila criada: %d \n", &ponteiroFila);
		
	}
	
	
	//Verificando o tamanho da lista criada
	
	flag = tamanhoFila(ponteiroFila);
	
	if(flag != -1)
	{
		printf("Tamanho da lista que acabou de ser criada: %d \n", flag);	
	}
	
	
	//Verificando se uma lista está cheia
	
	flag = filaCheia(ponteiroFila);
	
	if(flag == 1)
		printf("Fila Cheia \n");
	
	else if(flag == 0)
		printf("A fila não está cheia \n");
	
	
	
	//Verificando se uma lista está vazia
	
	flag = filaVazia(ponteiroFila);
	
	if(flag == 1)
		printf("Fila vazia \n");
	
	else if(flag == 0)
		printf("A fila não está vazia \n");
	
	
	
	//Inserindo elemento na fila
	
	reg_aluno.codigo = 1;
	reg_aluno.media = 6.0;
	strcpy(reg_aluno.nome, "Pedro");
	
	flag = insereFila(ponteiroFila, reg_aluno);
	
	if(flag == 1)
		printf("O %s foi inserido na fila \n", reg_aluno.nome);
	
	else if(flag == 0)
		printf("Não foi possível inserir o elemento %s na fila \n", reg_aluno.nome);
	
	reg_aluno.codigo = 2;
	reg_aluno.media = 7.0;
	strcpy(reg_aluno.nome, "José");
	flag = insereFila(ponteiroFila, reg_aluno);
	
	reg_aluno.codigo = 3;
	reg_aluno.media = 1.0;
	strcpy(reg_aluno.nome, "Carlos");
	flag = insereFila(ponteiroFila, reg_aluno);
	
	exibeElementos(ponteiroFila);
	
	//Removendo elemento da fila
	
	flag = removeFila(ponteiroFila);
	
	if(flag == 1){
		printf("Exibindo elementos após a remoção de um elemento da fila \n");
		exibeElementos(ponteiroFila);
	}

	
	//Consultando um elemento na fila
	
	flag = consultaFila(ponteiroFila, ptrAluno);
	
	if(flag == 1)
		printf("Elemento no final da fila  %s \n", reg_aluno.nome);
	
	//Liberando uma fila
	
	
	liberaFila(ponteiroFila);
	
	printf("----------- Fila liberada com sucesso -----------\n");
	
	
	return 0;
}
