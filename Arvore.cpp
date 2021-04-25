#include "Arvore.h"
#include <iostream>

using namespace std;

Arvore* Arvore::inicializa()
{
	return NULL;
}

Arvore* Arvore::adiciona(Arvore* raiz, Arvore* no)
{
	if (raiz == NULL) return no;

	if (no->chave < raiz->chave)
		raiz->esq = adiciona(raiz->esq, no);
	else
		raiz->dir = adiciona(raiz->dir, no);

	return raiz;
}

Arvore* Arvore::criaNovoNo(int chave)
{
	Arvore* novoNo = new Arvore;

	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = chave;

	return novoNo;
}

Arvore* Arvore::search(int chave, Arvore* raiz)
{
	if (raiz == NULL) return NULL;

	if (raiz->chave == chave) return raiz;

	if (raiz->chave > chave)
		return search(chave, raiz->esq);

	return search(chave, raiz->dir);
}


int Arvore::quantidadeNos(Arvore* raiz)
{
	if (!raiz) return 0;

	return quantidadeNos(raiz->esq) + 1 + quantidadeNos(raiz->dir);
}

void Arvore::exibirArvore(Arvore* raiz)
{
	if (raiz != NULL)
	{
		cout << raiz->chave;
		cout << "(";
		exibirArvore(raiz->esq);
		exibirArvore(raiz->dir);
		cout << ")";
	}
}

Arvore* Arvore::buscaNo(Arvore* raiz, int chave, Arvore* pai)
{
	Arvore* atual = raiz;
	pai = NULL;

	while (atual)
	{
		if (atual->chave == chave) return atual;
		pai = atual;
		if (chave < atual->chave) atual = atual->esq;
		else atual = atual->dir;
	}

	return NULL;
}

Arvore* Arvore::removeNo(Arvore* raiz, int chave)
{
	Arvore* pai = new Arvore, * no, * p, * q;

	no = buscaNo(raiz, chave, pai);

	if (no == NULL) return raiz;
	if (!no->esq || !no->dir)
	{
		if (!no->esq) q = no->dir;
		else q = no->esq;
	}
	else
	{
		p = no;
		q = no->esq;

		while (q->dir)
		{
			p = q;
			q = q->dir;
		}

		if (p != no)
		{
			p->dir = q->esq;
			q->esq = no->esq;
		}

		q->dir = no->esq;
	}

	if (!pai)
	{
		delete no;
		return q;
	}

	if (chave < pai->chave) pai->esq = q;
	else pai->dir = q;

	delete no;

	return raiz;

}