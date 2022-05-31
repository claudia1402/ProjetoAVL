// mainAVL.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "AVL.h"
#include "Alimento.h"

// Prototipos das funcoes presentes ----------------------
void Insert(AVL *avl, Alimento novo_alimento);
void Remove(AVL *avl);
void Search(AVL *avl);
void Predecessor(AVL *avl);
void Successor(AVL *avl);
void FindMin(AVL *avl);
void FindMax(AVL *avl);
void TraverseInOrder(AVL *avl);
void TraversePreOrder(AVL *avl);
void TraversePostOrder(AVL *avl);
void Clear(AVL *avl);

// Lendo Arquivo CSV -----------------------------------
void LerArq()
{
	std::string linha, temp;
	std::ifstream arq("NutritionalFacts_Fruit_Vegetables_Seafood - NutritionalFacts_Fruit_Vegetables_Seafood.csv");
	Alimento alimento;
	std::string dados[11];
	int j;

	if (arq.is_open())
	{
		// define arquivo
		while (getline(arq, linha))
		{
			// define linha
			for (int x = 0; x < 12; x++)
			{
				temp = "";
				// define palavra
				for (int i = 0; i < linha.size(); i++)
				{
					if (linha[i] != ',')
					{
						temp = temp + linha[i];
					}
				}
				dados[x] = temp;
			}
		}
		 // Alimento alimento = Alimento(dados);
	}
	else
	{
		std::cout << "Erro! Nao foi possivel ler o arquivo";
	}
}

// Implementações das funções ----------------------------
void Insert(AVL *avl, Alimento novo_alimento)
{
	NodeAVL *node = avl->Insert(novo_alimento);

	if (node)
		std::cout << "Node inserted!\n";
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(AVL *avl)
{
	std::string nomeAlimento;
	std::cout << "Remove: ";
	std::cin >> nomeAlimento;
	avl->Remove(nomeAlimento);
}

void Search(AVL *avl)
{
	std::string nomeAlimento;
	std::cout << "Search food name: ";
	std::cin >> nomeAlimento;
	NodeAVL *node = avl->Search(nomeAlimento);
	if (node)
		std::cout << "Node found:\n"
				  << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL *avl)
{
	std::string nomeAlimento;
	std::cout << "Find predecessor of: ";
	std::cin >> nomeAlimento;
	NodeAVL *node = avl->Predecessor(nomeAlimento);
	if (node)
		std::cout << "Predecessor of " << nomeAlimento << ":\n"
				  << node->ToString();
	else
		std::cout << "*** ERROR! There is no predecessor of " << nomeAlimento << "!\n";
}

void Successor(AVL *avl)
{
	std::string nomeAlimento;
	std::cout << "Find successor of: ";
	std::cin >> nomeAlimento;
	NodeAVL *node = avl->Successor(nomeAlimento);
	if (node)
		std::cout << "Successor of " << nomeAlimento << ":\n"
				  << node->ToString();
	else
		std::cout << "*** ERROR! There is no successor of " << nomeAlimento << "!\n";
}

void FindMin(AVL *avl)
{
	NodeAVL *node = avl->FindMin();
	if (node)
		std::cout << "Minimum:\n"
				  << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL *avl)
{
	NodeAVL *node = avl->FindMax();
	if (node)
		std::cout << "Maximum:\n"
				  << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL *avl)
{
	std::cout << avl->TraverseInOrder() << '\n';
}

void TraversePreOrder(AVL *avl)
{
	std::cout << avl->TraversePreOrder() << '\n';
}

void TraversePostOrder(AVL *avl)
{
	std::cout << avl->TraversePostOrder() << '\n';
}

void Clear(AVL *avl)
{
	avl->Clear();
}

void ValoresNutri(AVL *avl)
{
	std::string nomeAlimento;
	std::cout << "Search food name: ";
	std::cin >> nomeAlimento;
	std::cout << avl->ValoresNutri(nomeAlimento);
}

// Funções da atividade ----------------------------------

// Estas funções que são chamadas
// pela main devem receber a AVL e
// dentro delas serão requisitadas as
// variáveis p/ realizar operações

// Leitura dos Dados
// Valores Nutricionais
// Qntd de Calorias
// Qntd de Vitaminas
// Qntd de Proteínas
// Outras Informações
// Síntese Nutricional

// Implementação das funções -----------------------------

int main()
{
	AVL *avl = new AVL();

	LerArq();

	int option = -1;
	do
	{
		// Menu
		std::cout << "*** AVL Tree ***		\n"
				  << "[1] Leitura dos Dados 		\n"
				  << "[2] Valores Nutricionais 	\n"
				  << "[3] Quantidade de Calorias 	\n"
				  << "[4] Quantidade de Vitaminas	\n"
				  << "[5] Quantidade de Proteinas	\n"
				  << "[6] Outras Informacoes		\n"
				  << "[7] Sintese Nutricional		\n"
				  << "[8] EXIT					\n"
				  << "Option: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1:
			TraverseInOrder(avl);
			break;

			// case 2: ValoresNutri(); break;
		}
		std::cout << '\n';
	} while (option != 8);

	std::cout << "-------. Adios .-------";

	delete avl;
}
