// mainAVL.cpp
#include <iostream>
#include <string>
#include "AVL.h"

// Protótipos das funções presentes ----------------------
void Insert(AVL* avl);		// está quebrado
void Remove(AVL* avl);
void Search(AVL* avl);		// precisa mudar para buscar pelo nome do alimento
void Predecessor(AVL* avl); 
void Successor(AVL* avl);
void FindMin(AVL* avl);
void FindMax(AVL* avl);
void TraverseInOrder(AVL* avl);
void TraversePreOrder(AVL* avl);
void TraversePostOrder(AVL* avl);
void Clear(AVL* avl);


// Implementações das funções ----------------------------
void Insert(AVL* avl)
{
	int	code, qntde;
	std::string	nome;
	float valorUnit;

	std::cout << "Insert food code, name, quantity and unit value (in this order):\n";
	std::cin >> code >> nome >> qntde >> valorUnit;
	Alimento alimento(code, nome, qntde, valorUnit);
	NodeAVL* node = avl->Insert(code, alimento);

	if (node)
		std::cout << "Node inserted!\n";
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(AVL* avl)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	avl->Remove(num);
}

void Search(AVL* avl)
{
	int num;
	std::cout << "Search number: ";
	std::cin >> num;
	NodeAVL* node = avl->Search(num);
	if (node)
		std::cout << "Node found:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL* avl)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Predecessor(num);
	if (node)
		std::cout << "Predecessor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(AVL* avl)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Successor(num);
	if (node)
		std::cout << "Successor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(AVL* avl)
{
	NodeAVL* node = avl->FindMin();
	if (node)
		std::cout << "Minimum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL* avl)
{
	NodeAVL* node = avl->FindMax();
	if (node)
		std::cout << "Maximum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL* avl)
{
	std::cout << avl->TraverseInOrder() << '\n';
}

void TraversePreOrder(AVL* avl)
{
	std::cout << avl->TraversePreOrder() << '\n';
}

void TraversePostOrder(AVL* avl)
{
	std::cout << avl->TraversePostOrder() << '\n';
}

void Clear(AVL* avl)
{
	avl->Clear();
}

// Funções da atividade ----------------------------------

// Estas funções que são chamadas
// pela main devem receber a AVL e
// dentro delas serão requisitadas as
// variáveis p/ realizar operações

void op1(AVL* avl); // Leitura dos Dados
void op2(AVL* avl); // Valores Nutricionais
void op3(AVL* avl); // Qntd de Calorias
void op4(AVL* avl); // Qntd de Vitaminas
void op5(AVL* avl); // Qntd de Proteínas
void op6(AVL* avl); // Outras Informações
void op7(AVL* avl); // Síntese Nutricional

// Implementação das funções -----------------------------

void op1(AVL* avl)
{
	return;
}

void op2(AVL* avl)
{
	return;
}

void op3(AVL* avl){
	return;
}

void op4(AVL* avl)
{
	return;
}

void op5 (AVL* avl) {
	return;
}

void op6 (AVL* avl) {
	return;
}

void op7 (AVL* avl) {
	return;
}

int main()
{
	AVL* avl = new AVL();

	int option = -1;
	do
	{
		// Menu
		std::cout << "*** AVL Tree ***		\n"
			<< "[1] Leitura dos Dados 		\n"
			<< "[2] Valores Nutricionais 	\n"
			<< "[3] Quantidade de Calorias 	\n"
			<< "[4] Quantidade de Vitaminas	\n"
			<< "[5] Quantidade de Proteínas	\n"
			<< "[6] Outras Informações		\n"
			<< "[7] Síntese Nutricional		\n"
			<< "[8] EXIT					\n"
			<< "Option: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
			case 1: op1(avl); break;
			case 2: op2(avl); break;
			case 3: op3(avl); break;
			case 4: op4(avl); break;
			case 5: op5(avl); break;
			case 6: op6(avl); break;
			case 7: op7(avl); break;
		}
		std::cout << '\n';
	} while (option != 8);

	std::cout << "-------. Adios .-------";

	delete avl;
}

