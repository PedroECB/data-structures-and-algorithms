#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct aluno{
	char nome[20];
	int matricula;
	float nota;
};


typedef struct elemento *Lista;
typedef struct aluno Aluno;

Lista *criaLista();

int tamanhoLista(Lista *ptrLi);

int listaCheia(Lista *ptrLi);

int listaVazia (Lista *ptrLi);

int insereInicioLista(Lista *ptrLi, Aluno regAluno);

int insereFinalLista(Lista *ptrLi, Aluno regAluno);

int insereOrdenada(Lista *ptrLi, Aluno regAluno);

int buscaElementoPos(Lista *ptrLi, int pos, Aluno *ptrAluno);

int buscaElementoMat(Lista *ptrLi, int mat, Aluno *ptrAluno);

int removeListaInicio(Lista *ptrLi, Aluno *ptrAluno);

int removeListaFinal(Lista *ptrLi, Aluno *ptrAluno);

int removeLista(Lista *ptrLi, int mat);

Lista* liberaLista(Lista *ptrLi);

int exibeElementos(Lista *ptrLi);


