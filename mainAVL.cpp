// mainAVL.cpp
#include <iostream>
#include <string>
#include "AVL.h"

// Protótipos das funções presentes ----------------------
void Insert(AVL* avl);
void Remove(AVL* avl);
void Search(AVL* avl);
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

	std::cout << "Insert product code, name, quantity and unit value (in this order):\n";
	std::cin >> code >> nome >> qntde >> valorUnit;
	Product produto(code, nome, qntde, valorUnit);
	NodeAVL* node = avl->Insert(code, produto);

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

void op1(AVL* avl);
void op2(AVL* avl);
void op3(AVL* avl);
void op4(AVL* avl);
void op5(AVL* avl);

// Implementação das funções -----------------------------

void op1(AVL* avl)
{
	Search(avl);
}


//metodo Pimenta
void op2(AVL* avl)
{
	std::cout << avl->SimpleTraverseInOrder() << '\n';
}

//metodo joyce
void op3(AVL* avl){
	
	std::string nome_prod;
	float preco_total;
	Product produto;

	std::cout << "Digite o nome do produto que deseja:" << "\t";
	std::cin >> nome_prod;
    produto = avl->Search_name(nome_prod)->GetProduto();
	
	if (produto.GetNome() == nome_prod) {
		preco_total = produto.GetQtde() * produto.GetValorUnitario();
	};
	std::cout << "Preço total do estoque é R$ " <<preco_total;
	std::cout << avl->Search_name(nome_prod)->SimpleToString();
}

//metodo claudia
void op4(AVL* avl)
{
	std::cout << avl->StockValue() << '\n';
}

//metodo vitor
void op5 (AVL* avl) {
	int quant = 0;
	std::cout << "Digite o valor de uma quantidade de produtos: \n";
	std::cin >> quant; 
	std::cout << avl->percorre(quant);
}

int main()
{
	AVL* avl = new AVL();

	const int SIZE = 9;
	int codProdutos[SIZE] = { 5, 4, 3, 1, 2, 6, 7, 9, 8 };
	int qntProdutos[SIZE] = {35, 100, 200, 1000, 2, 45, 0, 27, 20};
	float vProdutos[SIZE] = {5.00, 10.00, 3.50, 59.99, 8.90, 2.10, 300.00, 10.18, 3.00};
	std::string nomes[SIZE] = { "açucar", "guarana", "detergente", "cafe", "energetico", "pao", "manteiga", "bisnaguinha", "sorvete"};
	Product produto;
	for (int i = 0; i < SIZE; ++i)
	{
		produto.SetCod(codProdutos[i]);
		produto.SetNome(nomes[i]);
		produto.SetQtde(qntProdutos[i]);
		produto.SetValorUnitario(vProdutos[i]);
		avl->Insert(codProdutos[i], produto);
	}
	int option = -1;
	do
	{
		std::cout << "*** AVL Tree ***\n"
			<< "[1] Lê dados de um produto 							\n"
			<< "[2] Apresenta todos os produtos						\n"
			<< "[3] Calcula o valor em Reais do produto em Estoque	\n"
			<< "[4] Calcula o valor do Estoque						\n"
			<< "[5] Mostra os produtos inferiores					\n"
			<< "[6] Exit											\n"
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
		}

		std::cout << '\n';
	} while (option != 6);

	delete avl;
}

