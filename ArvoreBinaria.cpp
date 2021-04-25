#include <iostream>
#include <Windows.h>
#include <locale.h>
#include "Arvore.h"
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	Arvore* arvore = new Arvore;

	arvore = arvore->inicializa();
	Arvore* No = arvore->criaNovoNo(30);
	arvore = arvore->adiciona(arvore, No);

	int qtd = 0;
	cout << endl;
	cout << " Quantos elementos terá na arvore: ";
	cin >> qtd;

	int val = 0;
	for (int i = 0; i < qtd; i++)
	{
		system("cls");
		cout << " Digite o " << i + 1 << " elemento: ";
		cin >> val;
		No = arvore->criaNovoNo(val);
		arvore = arvore->adiciona(arvore, No);
	}
	
	system("cls");
	cout << endl;
	cout << " Qual elemento vc quer buscar na arvore: ";
	cin >> val;
	
	system("cls");
	Arvore* achou = arvore->search(val, arvore);

	if (achou != NULL)
		cout << " Raiz: " << achou->chave << endl << endl;
	else
		cout << " Elemento não encontrado!" << endl << endl;

	cout << " Quantidade de Nós: " << arvore->quantidadeNos(arvore) << endl << endl;

	system("pause");

	system("cls");

	cout << " Remover qual nó: ";
	cin >> val;

	cout << endl << endl;
	auto* remove = arvore->removeNo(arvore, val);
	
	if (remove->chave == arvore->chave)
		cout << " Elemento não encontrado!" << endl << endl;
	else
		cout << " Elemento removido com sucesso!" << endl << endl;
	cout << " Quantidade de Nós: " << arvore->quantidadeNos(arvore) << endl << endl;

	arvore->exibirArvore(arvore);

	delete arvore;
	
	cout << endl << endl;
	system("pause");
	return  0;
}