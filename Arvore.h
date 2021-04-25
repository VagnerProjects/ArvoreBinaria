#pragma once
class Arvore
{
public:
	int chave;

	Arvore* dir, *esq;
	Arvore* inicializa();
	Arvore* adiciona(Arvore *raiz, Arvore *no);
	Arvore* criaNovoNo(int chave);
	Arvore* search(int chave, Arvore* raiz);
	int quantidadeNos(Arvore* raiz);
	void exibirArvore(Arvore* raiz);
	Arvore* buscaNo(Arvore* raiz, int chave, Arvore* pai);
	Arvore* removeNo(Arvore* raiz, int chave);
};

