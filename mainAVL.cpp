// ---------- Projeto II AVL - EDII ------------
// --------- Grupo cavalo_sentado.png ----------
// 	Claudia Fiorentino Andrade 		- 42005302
// 	João Victor Ferreira Pimenta 	- 42005876
// 	Joyce Cui 						- 42017157
//	Ryan Marco Andrade dos Santos 	- 42080223
// 	Victor Prado Chaves 			- 32070772

// mainAVL.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
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

// Funções da atividade ----------------------------------

std::list<std::string> gera_consumidos() 
{
	std::list<std::string> lista_consumidos;
	std::string consumidos;

	std::cout << "Quais foram os alimentos consumidos (digite '-1' para finalizar): ";
	while (true)
	{
		std::cin >> consumidos;
		if (consumidos == "-1") return lista_consumidos;
		else lista_consumidos.push_back(consumidos);
	}
}


// Estas funções que são chamadas
// pela main devem receber a AVL e
// dentro delas serão requisitadas as
// variáveis p/ realizar operações

// Leitura dos Dados
// Valores Nutricionais
// Qntd de Calorias
void op3(AVL* avl){

	std::list<std::string> consumidos = gera_consumidos();

	std::cout << avl-> Qnt_Calories(consumidos); 
}
// Qntd de Vitaminas
void op4 (AVL *avl)
{
	std::list<std::string> consumidos = gera_consumidos();

	std::cout << avl->QntdVitaminas(consumidos);
}
// Qntd de Proteínas
void op5 (AVL *avl)
{
	std::list<std::string> consumidos = gera_consumidos();

	std::cout << avl -> QntdProteinas(consumidos);
}
// Outras Informações
void op6 (AVL * avl)
{
	std::list<std::string> consumidos = gera_consumidos();

	std::cout << avl->OutrasInfos(consumidos) << std::endl;
}
// Síntese Nutricional

void SinteseNutri(AVL* avl){
	// int qtde;
	// Alimento comida;
	// std::cout<<"Defina a quantidade de alimentos consumidos";
	// std::cin>> qtde;
	// Alimento alimentos[qtde]; // Importando a relação de alimentos consumidos. Talvez o vetor possa ser do tipo string, pois só será usado o nome do alimento
	// for(int i=0; i<qtde; i++) //popula vetor
	// 	std::cin>>comida;
	// Sintese(avl, alimentos);

	std::list<std::string> consumidos = gera_consumidos();
	std::cout << avl->Sintese(consumidos) << std::endl;
}

void ValoresNutri(AVL *avl)
{
	std::string nomeAlimento;
	std::cout << "Search food name: ";
	std::cin >> nomeAlimento;
	std::cout << avl->ValoresNutri(nomeAlimento);
}

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

			case 2:
				ValoresNutri(avl);
				break;

			case 3:
				op3(avl);
				break;

			case 4:
				op4(avl);
				break;

			case 5:
				op5(avl);
				break;

			case 6:
				op6(avl);
				break;

			case 7:
				SinteseNutri(avl);
				break;

			case 8:
				break;


		}
		std::cout << '\n';
	} while (option != 8);

	std::cout << "-------. Adios .-------";

	delete avl;
}
