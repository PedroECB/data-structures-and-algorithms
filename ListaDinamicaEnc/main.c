#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaDinEncad.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop \n*/

int main() {
	setlocale(LC_ALL, "Portuguese");
	int pos, mat, flag;
	Lista *ponteiroLista;
	Aluno *ptrAluno;
	Aluno regAluno;
	
	ptrAluno = &regAluno;
	
	
	//Criando a lista
	
	printf("---- Criando a lista ----\n ");
	
	ponteiroLista = criaLista();
	
	if(ponteiroLista == NULL){
		printf("Não foi possível criar o ponteiro \n");
	}else{
		printf("O ponteiro foi criado e foi alocado em: %d \n", ponteiroLista);
	}
	
	
	//Tamanho da lista
	
	printf("n --- -----Verificando o tamanho da lista ------- \n");
	
	flag = tamanhoLista(ponteiroLista);
	if(flag == -1){
		printf("Não foi possível verificar o tamanho da lista \n");
	}
	printf("Tamanho da lista criada: %d \n", flag);
	
	
	//Verificando se uma lista está cheia
	
	flag = listaCheia(ponteiroLista);
	if(flag == 1){
		printf("Lista cheia \n");
	
	}else{
		printf("A lista não está cheia \n");
	}
	
	// Verificando se uma lista está sem elementos "Lista vazia"
	
	printf("\n------ Verificando se uma lista está vazia ------\n");

	flag = listaVazia(ponteiroLista);
	if(flag){
		printf("A lista está vazia \n");
	}else{
		printf("A lista não está vazia \n");
	}
	
	//Inserindo no início da lista
	
	regAluno.matricula = 1;
	strcpy(regAluno.nome, "Pedro");
	regAluno.nota = 7.5;
	
	printf("\n Inserindo o aluno %s na lista: ", regAluno.nome);
	
	flag = insereInicioLista(ponteiroLista, regAluno);
	
	if(flag == -1 || flag == 0){
		printf("Não foi possível inserir o aluno na lista \n");
	
	}else{
		pos = tamanhoLista(ponteiroLista);
		printf("\n Tamanho da lista após a inserção do aluno %s = %d \n", regAluno, pos);
	}
	
	//Inserindo no final da lista
	regAluno.matricula = 3;
	strcpy(regAluno.nome, "José");
	regAluno.nota = 8.0;
	
	printf("Inserindo o aluno %s na lista \n", regAluno.nome);
	
	flag = insereFinalLista(ponteiroLista, regAluno);
	pos = tamanhoLista(ponteiroLista);
	
	printf("Tamanho da lista após a inserção de %s = %d \n", regAluno.nome, pos);
	
	//Inserindo de forma ordenada na lista
	
	regAluno.matricula = 2;
	strcpy(regAluno.nome, "Maria");
	regAluno.nota = 8.0;
	
	printf("Inserindo o aluno(a) %s de forma ordenada na lista \n", regAluno.nome);
	flag = insereOrdenada(ponteiroLista, regAluno);
	
	//Exibindo elementos após inserção
	
	pos = tamanhoLista(ponteiroLista);
	printf("Exibindo a lista após a inserção de %s que está com o tamanho %d \n", regAluno.nome, pos);
	
	flag = exibeElementos(ponteiroLista);
	
	
	//Buscando elemento por posição
	printf("---- -Buscando o elemento na posição 1º  -----\n");
	
	flag = buscaElementoPos(ponteiroLista, 1, ptrAluno);
	if(flag == 1){
		printf("Elemento encontrado: %s \n", ptrAluno->nome);
	}else{
		printf("Não foi possível encontrar o elemento na lista \n");
	}
	
	//Buscando elemento por matrícula
	printf("------ Buscando elemento por matrícula ------- \n");
	
	flag = buscaElementoMat(ponteiroLista, 3, ptrAluno);
	
	if(flag == 1){
		printf("Elemento de matrícula Nº3: %s \n", ptrAluno->nome);
	}else{
		printf("Não foi possível encontrar o elemento de matricula Nº3 na lista \n");
	}
	
	//Removendo elemento do início da lista
	printf("------- Removendo elemento do início da lista ---- \n");
	flag = removeListaInicio(ponteiroLista, ptrAluno);
	printf("Elemento que foi removido do início da lista: %s \n", ptrAluno->nome);
	printf("Exibindo elementos da lista após remoção de %s \n", ptrAluno->nome);
	printf(" \n --- Removendo elemento do final da lista  -----  \n");
	flag = exibeElementos(ponteiroLista);
	

	//Removendo elemento o final da lista
	
	printf(" \n --- Removendo elemento do final da lista  -----  \n");
	flag = removeListaFinal(ponteiroLista, ptrAluno);
	
	if(flag == 1){
		printf("O %s foi removido da lista  \n", ptrAluno->nome);
	}
	
	printf("Exibindo lista após remoção de %s  \n", ptrAluno->nome);
	flag = exibeElementos(ponteiroLista);

	//Removendo elemento pelo número da matrícula
	
	printf("Removendo elemento específico da lista \n");
	flag = removeLista(ponteiroLista, 2);
	
	if(flag == 1){
		printf("Elemento com matricula Nº2 removido da lista \n");
		flag = exibeElementos(ponteiroLista);
	}
	
	
	printf("--- Liberando a lista da memória ---- \n");
	ponteiroLista = liberaLista(ponteiroLista);
	
	printf(" -  - -- - - - - - - FIM -----  Lista liberada com sucesso! \n"); 

















}
