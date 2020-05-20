#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "ListaSequencial.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL, "portuguese");
	printf("Constante definidida como valor m�ximo: %d \n", MAX);
	
							//Vari�veis de utiliza��o
	Aluno regAluno;
	Aluno *ptrAluno;
	int pos;
	
	ptrAluno = &regAluno;
	
	
	Lista *ponteiroLista;
	
								//Criando a lista
	
	ponteiroLista = criaLista();
	
	if(ponteiroLista == NULL){
		printf("N�o foi poss�vel criar a lista");
	}else{
		printf("Endere�o da lista criada: %d \n", ponteiroLista);
	}
	
							
	printf("Tamanho em bytes do tipo Lista: %d bytes \n", sizeof(Aluno));
	
	
							//Verificando o tamanho da lista
	
	int tamanho = tamanhoLista(ponteiroLista);
		
		if(tamanho == -1){
			printf("Lista n�o existe \n");
		}else{
			printf("Tamanho da lista: %d \n", tamanho);
		}
		
		
							//Verifica se lista est� cheia
		
		
	int flagListaCheia = listaCheia(ponteiroLista);
		
		if(flagListaCheia == -1)
			printf("Lista n�o existe \n");
		
		else 
			printf("A lista est� cheia? (1 Sim, 0 N�o) :%d \n", flagListaCheia);
			
			
						//Verifica se h� espa�o na lista
	
	
	int flagListaVazia = listaVazia(ponteiroLista);
		
		if(flagListaVazia == -1)
			printf("Lista n�o existe \n");
		else
			printf("H� espa�o na lista criada? (1 Sim, 0 N�o) :%d \n", flagListaVazia);
			
			
			
						//Insere no final da lista
			
	
	regAluno.codigo = 1;
	strcpy(regAluno.nome, "Pedro Henrique");
	regAluno.nota = 9.0;
	
	printf("Dados do aluno que vai ser inserido no final da lista:  \n");
	printf("Nome: %s  \n", regAluno.nome);
	printf("C�digo: %d  \n", regAluno.codigo);
	printf("Nota: %.2f  \n", regAluno.nota);
	
	
	pos = insereFinalDaLista(ponteiroLista, regAluno);
	
	printf("\n\n -------------------------------------------------------------\n\n\n");
	
	printf("Posi��o na lista em que o aluno %s foi inserido: %d \n\n", regAluno.nome, pos);
	printf("Tamanho da lista agora: %d \n", tamanhoLista(ponteiroLista));
	
	regAluno.codigo = 2;
	strcpy(regAluno.nome, "Jo�o da Silva");
	regAluno.nota = 7.0;
	
	pos = insereFinalDaLista(ponteiroLista, regAluno);
	printf("Posi��o na lista em que o aluno Jo�o foi inserido: %d \n\n", pos);
	printf("Tamanho da lista agora: %d \n", tamanhoLista(ponteiroLista));
	
	exibeElementos(ponteiroLista);
	
	
	
	
								//Inserindo no in�cio da lista
					
	regAluno.codigo = 3;
	strcpy(regAluno.nome, "Maria Barbosa");
	regAluno.nota = 8.5;
	
	pos = insereInicioDaLista(ponteiroLista, regAluno);
	exibeElementos(ponteiroLista);
	
	
	
	
							//Inserindo elemento na lista ordenada 1
					
						
	regAluno.codigo = 0;
	strcpy(regAluno.nome, "Jos� da Silva");
	regAluno.nota = 5.5;
	
	printf("Inserindo o aluno %s de maneira ordenada: \n", regAluno.nome);
	pos = insereOrdenada(ponteiroLista, regAluno);
	exibeElementos(ponteiroLista);	
	
	
	
	
			
							//Inserindo elementos de maneira ordenada 2
					
	regAluno.codigo = 5;
	strcpy(regAluno.nome, "Xavier Medeiros");
	regAluno.nota = 8.5;
	
	
	pos = insereOrdenada2(ponteiroLista, regAluno);
	
	exibeElementos(ponteiroLista);
	
	
								//Buscando aluno pela posi��o
		
	
	
	pos = buscaListaPos(ponteiroLista, 2, ptrAluno);
	
	printf("Aluno N� 2 da lista: %s \n", regAluno.nome);
	
	
	
								//Buscando aluno pela matr�cula
	
	printf("\n\n ----------------------Buscando por matr�cula -----------\n");
	pos = buscaListaCod(ponteiroLista, 2, ptrAluno);
	
		if(pos == -1){
			printf("Erro no ponteiro passado como par�metro");
		
		}else if(pos == 0){
			printf("C�digo n�o encontrado na lista");
		
		}else if(pos == 1){
			printf("Aluno com o c�digo 2 na lista: %s", regAluno.nome);
		}
		
	exibeElementos(ponteiroLista);
	
							//Removendo do inicio da lista
							
	int flag = removendoInicioDaLista(ponteiroLista, ptrAluno);
	
	if(flag == -1){
		printf("Ponteiro vazio");
	
	}else if(flag == 0){
		printf("Lista vazia, n�o foi poss�vel remover o elemento");
	
	}else{
		printf("-------------------------------------------\n");
		printf("Aluno que foi removido do in�cio da lista: %s\n", ptrAluno->nome);
		printf("Exibindo lista ap�s remover o primeiro elemento \n");
		exibeElementos(ponteiroLista);
	}
	
	
	printf("\n ---------------------------------------------------- \n ");
								//Removendo do final da lista
					
	flag = removeFinalDaLista(ponteiroLista, ptrAluno);
	
	if(flag == -1){
		printf("Lista inexistente para remo��o da �ltima posi��o");
	
	}else if(flag == 0){
		printf("Lista vazia, n�o foi poss�vel fazer a remo��o do elemento na ultima posicao %d", flag);
	
	}else{
		printf("Aluno que foi removido do final da lista: %s \n", ptrAluno->nome);
		printf("Exibindo lista ap�s remover o �ltimo elemento \n");
		exibeElementos(ponteiroLista);
	}
	
					//Removendo pela matricula da lista
					
	printf("\n ---------------------------------------------------- \n ");
					
	flag = removeLista(ponteiroLista, 2);
	
	
	if(flag == -1){
		printf("N�o foi poss�vel remover o aluno da lista \n");
	
	}else if(flag == 0){
		printf("A lista n�o cont�m elementos para ser removido \n");
	
	}else{
		printf("O aluno com o codigo 2 foi removido com sucesso \n");
		printf("Exibindo lista ap�s remover o aluno \n");
		exibeElementos(ponteiroLista);
	}
	
	
	
							// Liberando lista
							
		flag = liberaLista(ponteiroLista);
		
		
		if(flag == 1){
			printf("--------------------------------------------------------- \n");
			printf("-                 LISTA LIBERADA COM SUCESSO!           -\n");
			printf("---------------------------------------------------------");
		}
	
	
					//ordenando
		
	
//	ordena(ponteiroLista);
					
						
						
						
						
						
						
						
						
						
						
			
			
//	printf("Nome: %s  \n", *ponteiroLista->reg_aluno[pos].nome);
//	printf("C�digo: %d  \n", *ponteiroLista->reg_aluno[pos]->codigo);
//	printf("Nota: %.2f  \n", *ponteiroLista->reg_aluno[pos]->nota);
	
	
	
	
	
	
	
	
	
	free(ponteiroLista);
	return 0;
}
