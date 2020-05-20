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
		printf("N�o foi poss�vel criar o ponteiro \n");
	}else{
		printf("O ponteiro foi criado e foi alocado em: %d \n", ponteiroLista);
	}
	
	
	//Tamanho da lista
	
	printf("n --- -----Verificando o tamanho da lista ------- \n");
	
	flag = tamanhoLista(ponteiroLista);
	if(flag == -1){
		printf("N�o foi poss�vel verificar o tamanho da lista \n");
	}
	printf("Tamanho da lista criada: %d \n", flag);
	
	
	//Verificando se uma lista est� cheia
	
	flag = listaCheia(ponteiroLista);
	if(flag == 1){
		printf("Lista cheia \n");
	
	}else{
		printf("A lista n�o est� cheia \n");
	}
	
	// Verificando se uma lista est� sem elementos "Lista vazia"
	
	printf("\n------ Verificando se uma lista est� vazia ------\n");

	flag = listaVazia(ponteiroLista);
	if(flag){
		printf("A lista est� vazia \n");
	}else{
		printf("A lista n�o est� vazia \n");
	}
	
	//Inserindo no in�cio da lista
	
	regAluno.matricula = 1;
	strcpy(regAluno.nome, "Pedro");
	regAluno.nota = 7.5;
	
	printf("\n Inserindo o aluno %s na lista: ", regAluno.nome);
	
	flag = insereInicioLista(ponteiroLista, regAluno);
	
	if(flag == -1 || flag == 0){
		printf("N�o foi poss�vel inserir o aluno na lista \n");
	
	}else{
		pos = tamanhoLista(ponteiroLista);
		printf("\n Tamanho da lista ap�s a inser��o do aluno %s = %d \n", regAluno, pos);
	}
	
	//Inserindo no final da lista
	regAluno.matricula = 3;
	strcpy(regAluno.nome, "Jos�");
	regAluno.nota = 8.0;
	
	printf("Inserindo o aluno %s na lista \n", regAluno.nome);
	
	flag = insereFinalLista(ponteiroLista, regAluno);
	pos = tamanhoLista(ponteiroLista);
	
	printf("Tamanho da lista ap�s a inser��o de %s = %d \n", regAluno.nome, pos);
	
	//Inserindo de forma ordenada na lista
	
	regAluno.matricula = 2;
	strcpy(regAluno.nome, "Maria");
	regAluno.nota = 8.0;
	
	printf("Inserindo o aluno(a) %s de forma ordenada na lista \n", regAluno.nome);
	flag = insereOrdenada(ponteiroLista, regAluno);
	
	//Exibindo elementos ap�s inser��o
	
	pos = tamanhoLista(ponteiroLista);
	printf("Exibindo a lista ap�s a inser��o de %s que est� com o tamanho %d \n", regAluno.nome, pos);
	
	flag = exibeElementos(ponteiroLista);
	
	
	//Buscando elemento por posi��o
	printf("---- -Buscando o elemento na posi��o 1�  -----\n");
	
	flag = buscaElementoPos(ponteiroLista, 1, ptrAluno);
	if(flag == 1){
		printf("Elemento encontrado: %s \n", ptrAluno->nome);
	}else{
		printf("N�o foi poss�vel encontrar o elemento na lista \n");
	}
	
	//Buscando elemento por matr�cula
	printf("------ Buscando elemento por matr�cula ------- \n");
	
	flag = buscaElementoMat(ponteiroLista, 3, ptrAluno);
	
	if(flag == 1){
		printf("Elemento de matr�cula N�3: %s \n", ptrAluno->nome);
	}else{
		printf("N�o foi poss�vel encontrar o elemento de matricula N�3 na lista \n");
	}
	
	//Removendo elemento do in�cio da lista
	printf("------- Removendo elemento do in�cio da lista ---- \n");
	flag = removeListaInicio(ponteiroLista, ptrAluno);
	printf("Elemento que foi removido do in�cio da lista: %s \n", ptrAluno->nome);
	printf("Exibindo elementos da lista ap�s remo��o de %s \n", ptrAluno->nome);
	printf(" \n --- Removendo elemento do final da lista  -----  \n");
	flag = exibeElementos(ponteiroLista);
	

	//Removendo elemento o final da lista
	
	printf(" \n --- Removendo elemento do final da lista  -----  \n");
	flag = removeListaFinal(ponteiroLista, ptrAluno);
	
	if(flag == 1){
		printf("O %s foi removido da lista  \n", ptrAluno->nome);
	}
	
	printf("Exibindo lista ap�s remo��o de %s  \n", ptrAluno->nome);
	flag = exibeElementos(ponteiroLista);

	//Removendo elemento pelo n�mero da matr�cula
	
	printf("Removendo elemento espec�fico da lista \n");
	flag = removeLista(ponteiroLista, 2);
	
	if(flag == 1){
		printf("Elemento com matricula N�2 removido da lista \n");
		flag = exibeElementos(ponteiroLista);
	}
	
	
	printf("--- Liberando a lista da mem�ria ---- \n");
	ponteiroLista = liberaLista(ponteiroLista);
	
	printf(" -  - -- - - - - - - FIM -----  Lista liberada com sucesso! \n"); 

















}
