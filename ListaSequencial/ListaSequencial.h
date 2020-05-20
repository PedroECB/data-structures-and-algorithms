#include<stdio.h>
#include<stdlib.h>
#define MAX 5


struct aluno
{
	int codigo;
	char nome[20];
	float nota;	
};

typedef struct aluno Aluno;
typedef struct lista Lista;


Lista * criaLista();

int tamanhoLista(Lista *ptrLista);

int listaCheia(Lista *ptrLista);

int listaVazia(Lista *ptrLista);

int listaSemElementos(Lista *ptrLista);

int insereFinalDaLista(Lista *ptrLista, Aluno regAluno);

int insereInicioDaLista(Lista *ptrLista, Aluno regAluno);

int insereOrdenada(Lista *ptrLista, Aluno regAluno);

int insereOrdenada2(Lista *ptrLista, Aluno regAluno);

int buscaListaPos(Lista *ptrLista, int pos, Aluno *ptrAluno);

int buscaListaCod(Lista *ptrLista, int codigo, Aluno *ptrAluno);

int removendoInicioDaLista(Lista *ptrLista, Aluno *ptrAluno);

int removeFinalDaLista(Lista *ptrLista, Aluno *ptrAluno);

int removeLista(Lista *ptrLista, int codigo);

int liberaLista(Lista * ptrLista);

int ordena(Lista *ptrLista);

void exibeElementos(Lista *ptrLista);

