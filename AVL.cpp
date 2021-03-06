// ---------- Projeto II AVL - EDII ------------
// --------- Grupo cavalo_sentado.png ----------
// 	Claudia Fiorentino Andrade 		- 42005302
// 	João Victor Ferreira Pimenta 	- 42005876
// 	Joyce Cui 						- 42017157
//	Ryan Marco Andrade dos Santos 	- 42080223
// 	Victor Prado Chaves 			- 32070772

// AVL.cpp
#include "AVL.h"
#include "Utils.h"
#include "NodeAVL.h"
#include <sstream>

AVL::AVL()
	: m_Root(nullptr)
{
}

AVL::~AVL()
{
	Clear();
}

NodeAVL* AVL::GetRoot() const
{
	return m_Root;
}

bool AVL::IsEmpty() const
{
	return m_Root == nullptr;
}

void AVL::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void AVL::Destroy(NodeAVL* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int AVL::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int AVL::GetDegreeInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int AVL::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::string AVL::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}

std::string AVL::TraverseInOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->ToString();
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

// Usa SimpleToString() ao invés do comum;
std::string AVL::SimpleTraverseInOrder() const
{
	return SimpleTraverseInOrderInternal(m_Root);
}

std::string AVL::SimpleTraverseInOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << SimpleTraverseInOrderInternal(node->GetLeft());
		oss << node->SimpleToString();
		oss << SimpleTraverseInOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

std::string AVL::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}

std::string AVL::TraversePreOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->ToString();
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

std::string AVL::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}

std::string AVL::TraversePostOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->ToString();
		return oss.str();
	}

	//return "null ";
	return "";
}

NodeAVL* AVL::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeAVL* AVL::FindMinInternal(NodeAVL* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeAVL* AVL::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeAVL* AVL::FindMaxInternal(NodeAVL* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeAVL* AVL::Predecessor(std::string nomeAlimento) const
{
	NodeAVL* node = SearchInternal(m_Root, nomeAlimento);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeAVL* AVL::PredecessorInternal(NodeAVL* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeAVL* AVL::Successor(std::string nomeAlimento) const
{
	NodeAVL* node = SearchInternal(m_Root, nomeAlimento);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeAVL* AVL::SuccessorInternal(NodeAVL* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeAVL* AVL::Search(std::string nomeAlimento) const
{
	return SearchInternal(m_Root, nomeAlimento);
}

NodeAVL* AVL::SearchInternal(NodeAVL* node, std::string nomeAlimento) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetNomeAlimento() == nomeAlimento)
		return node;
	else if (node->GetNomeAlimento() > nomeAlimento)
		return SearchInternal(node->GetLeft(), nomeAlimento);
	else
		return SearchInternal(node->GetRight(), nomeAlimento);
}

NodeAVL* AVL::Insert(Alimento alimento)
{
	if (IsEmpty())
	{
		m_Root = new NodeAVL(alimento);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, alimento);
}

NodeAVL* AVL::InsertInternal(NodeAVL* node, NodeAVL* parent, Alimento alimento)
{
	if (node == nullptr)
		node = new NodeAVL(alimento, parent);
	else if (node->GetNomeAlimento() == alimento.GetNome())
		return nullptr; // Error! Cannot insert duplicate.
	else if (node->GetNomeAlimento() > alimento.GetNome())
		node->SetLeft(InsertInternal(node->GetLeft(), node, alimento));
	else if (node->GetNomeAlimento() < alimento.GetNome())
		node->SetRight(InsertInternal(node->GetRight(), node, alimento));

	node = Balance(node);
	return node;
}

void AVL::Remove(std::string nomeAlimento)
{
	RemoveInternal(m_Root, nomeAlimento);
}

NodeAVL* AVL::RemoveInternal(NodeAVL* node, std::string nomeAlimento)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetNomeAlimento() == nomeAlimento)
		node = RemoveNode(node);
	else if (node->GetNomeAlimento() > nomeAlimento)
		node->SetLeft(RemoveInternal(node->GetLeft(), nomeAlimento));
	else
		node->SetRight(RemoveInternal(node->GetRight(), nomeAlimento));
	
	node = Balance(node);
	return node;
}

NodeAVL* AVL::RemoveNode(NodeAVL* node)
{
	NodeAVL* parent = node->GetParent();

	// Case 1: The node to be removed is a leaf.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: The node to be removed has no left child/subtree.
	else if (node->GetLeft() == nullptr)
	{
		NodeAVL* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: The node to be removed has no right child/subtree.
	else if (node->GetRight() == nullptr)
	{
		NodeAVL* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: The node to be removed has both left and right children/subtrees.
	else
	{
		// To remove the node, we are reducing the problem to Case 3.
		// In this case, predecessor is located in the node's left child/subtree and
		// is the node that has no right child/subtree.
		NodeAVL* predecessor = Predecessor(node->GetNomeAlimento());

		// Instead of only updating pointers, we are copying the nome from the
		// predecessor to the node pointer and then we remove the predecessor node.
		node->CopynomeFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetNomeAlimento()));
	}

	return node;
}

void AVL::UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}

// Also known as LL Rotation (or RR tree, right-right tree).
NodeAVL* AVL::RotateLeft(NodeAVL* node)
{
	if (node == nullptr) return nullptr;

	// The current node must have a right child/subtree.	
	NodeAVL* newRoot = node->GetRight();
	if (newRoot == nullptr) return nullptr;

	// Swap parent links.
	NodeAVL* parent = node->GetParent();
	UpdateParentChild(parent, node, newRoot);
	node->SetParent(newRoot);

	// Since newRoot is this subtree's new root,
	// its left child becomes the right child of
	// the current node.
	NodeAVL* left = newRoot->GetLeft();
	node->SetRight(left);

	// Update the parent of newRoot's left child
	// if there is a left child.
	if (left != nullptr)
		left->SetParent(node);

	// The new left child of newRoot is the current node.
	newRoot->SetLeft(node);

	node->UpdateBalanceFactor();
	newRoot->UpdateBalanceFactor();

	return newRoot;
}

// Also known as RR Rotation (or LL tree, left-left tree).
NodeAVL* AVL::RotateRight(NodeAVL* node)
{
	if (node == nullptr) return nullptr;

	// The current node must have a left child/subtree.	
	NodeAVL* newRoot = node->GetLeft();
	if (newRoot == nullptr) return nullptr;

	// Swap parent links.
	NodeAVL* parent = node->GetParent();
	UpdateParentChild(parent, node, newRoot);
	node->SetParent(newRoot);

	// Since newRoot is this subtree's new root,
	// its right child becomes the left child of
	// the current node.
	NodeAVL* right = newRoot->GetRight();
	node->SetLeft(right);

	// Update the parent of newRoot's right child
	// if there is a right child.
	if (right != nullptr)
		right->SetParent(node);

	// The new right child of newRoot is the current node.
	newRoot->SetRight(node);

	node->UpdateBalanceFactor();
	newRoot->UpdateBalanceFactor();

	return newRoot;
}

// Also known as Left-Right Rotation (LR Rotation).
NodeAVL* AVL::RotateLeftRight(NodeAVL* node)
{
	node->SetLeft(RotateLeft(node->GetLeft()));
	return RotateRight(node);
}

// Also known as Right-Left Rotation (RL Rotation).
NodeAVL* AVL::RotateRightLeft(NodeAVL* node)
{
	node->SetRight(RotateRight(node->GetRight()));
	return RotateLeft(node);
}

NodeAVL* AVL::Balance(NodeAVL* node)
{
	if (node != nullptr)
	{
		node->UpdateBalanceFactor();
		int nodeBF = node->GetBalanceFactor();

		// Tree is left heavy.
		//if (nodeBF == 2) // --> Use this if BF=HL-HR.
		if (nodeBF == -2)
		{
			// Get left subtree's height.
			NodeAVL* left = node->GetLeft();
			left->UpdateBalanceFactor();
			int leftChildBF = left->GetBalanceFactor();

			//if (leftChildBF == 1) // --> Use this if BF=HL-HR.
			if (leftChildBF == -1)
				node = RotateRight(node);
			else
				node = RotateLeftRight(node);
		}
		// Tree is right heavy.
		//else if (nodeBF == -2) // --> Use this if BF=HL-HR.
		else if (nodeBF == 2)
		{
			// Get right subtree's height.
			NodeAVL* right = node->GetRight();
			right->UpdateBalanceFactor();
			int rightChildBF = right->GetBalanceFactor();

			//if (rightChildBF == -1) // --> Use this if BF=HL-HR.
			if (rightChildBF == 1)
				node = RotateLeft(node);
			else
				node = RotateRightLeft(node);
		}
	}

	return node;
}

NodeAVL* AVL::Search_name(std::string n_Alimento) const
{
	return SearchInternal_name(FindMin(), n_Alimento);
}

NodeAVL* AVL::SearchInternal_name(NodeAVL* node, std::string nomeAlimento) const
{
	while (Successor(node->GetNomeAlimento()) != nullptr)
	{
		if (node->GetAlimento().GetNome() == nomeAlimento)
			return node;
		node = Successor(node->GetNomeAlimento());
	}
	return nullptr;
}


//Metodo Victor----
std::string AVL::Sintese (std::list<std::string> consumidos)
{
	std::ostringstream oss;
	std::list<std::string>::iterator it = consumidos.begin();
	std::string dados[12] = {"Calorias","Gorduras","Sodio","Potassio",
							"Carboidratos","Fibras","Açucar","Proteinas",
							"Gorduras Saturadas","Colesterol","Vitamina A",
							"Vitamina C"};
	float totais[12] = {0};

	// Calcula as quantidades de cada nutriente
	for (; it != consumidos.end(); it++)
		SinteseInternal(totais, *it);

	// Cria a string de saída
	oss << "Sintese de Nutrientes" << std::endl
		<< "---------------------" << std::endl;
	for (int i = 0; i < 12; i++)
		oss << "|" << dados[i] << ":" << totais[i] << "|" << std::endl;
	oss << "---------------------";

	return oss.str();
}

void AVL::SinteseInternal(float qntds[], std::string nomeAlimento)
{
	std::list<float>::iterator it;

	it = Search(nomeAlimento) -> GetAlimento().GetNutrientes().begin();
	std::advance(it, 1);

	for (int i = 0; i < 12; i++, it++)
	{
		switch (i)
		{
			case 0:
				qntds[0] += Qnt_CaloriesInternal(nomeAlimento);
				break;
			case 8:
				qntds[8] += QntdProteinasInternal(nomeAlimento);
				break;
			case 11:
				qntds[11] += QntdVitaminasInternal(nomeAlimento, 12);
				break;
			case 12:
				qntds[12] += QntdVitaminasInternal(nomeAlimento, 13);
			default:
				qntds[i] += * it;
				break;
		}
	}
}

std::string AVL::OutrasInfos (std::list<std::string> consumidos)
{
	std::list<std::string>::iterator it;
	std::ostringstream oss;
	float qntdes_totais[8] = {0};
	std::string nutrientes[] = {"Sódio", "Potássio","Carboidrato","Fibras","Açúcares","Proteína","Gordura Saturada","Colesterol"};

	for (it = consumidos.begin(); it != consumidos.end(); ++it)
		OutrasInfosInternal (* it, qntdes_totais);
	
	oss << "Foram consumidos: " << std::endl;
	for (int i = 0; i < 8; i++)
		oss << qntdes_totais[i] << " de "
			<< nutrientes[i] << std::endl;
	
	return oss.str();
}

void AVL::OutrasInfosInternal (std::string nomeAlimento, float qnts[])
{
	std::list<float>::iterator it;

	it = Search(nomeAlimento) -> GetAlimento().GetNutrientes().begin();
	std::advance(it, 3);

	for (int i = 0; i < 8; i++)
	{
		qnts[i] += * it;
		std::advance(it, 1);
	}
}


std::string AVL::QntdVitaminas (std::list<std::string> consumidos)
{
	std::list<std::string>::iterator it;
	std::ostringstream oss;
	float qntd_total_a = 0.0;
	float qntd_total_c = 0.0;

	// itera por toda a lista adicionando as vitaminas
	// correspondentes às variáveis qntd_total
	for (it = consumidos.begin(); it != consumidos.end(); ++it)
	{
		qntd_total_a += QntdVitaminasInternal(* it, 12);
		qntd_total_c += QntdVitaminasInternal(* it, 13);
	}
	oss << "A quantidade de Vitamina A consumida foi de: "
		<< qntd_total_a << std::endl
		<< "A quantidade de Vitamina C consumida foi de: "
		<< qntd_total_c << std::endl;
	return oss.str();
}

float AVL::QntdVitaminasInternal (std::string nomeAlimento, int vit)
{
	// valor será um ponteiro para o início da lista
	// que guarda os dados de cada alimento
	auto valor = Search(nomeAlimento)->GetAlimento().GetNutrientes().begin();
	
	// incrementa o ponteiro para avançá-lo pela lista
	std::advance(valor, vit);
	return * valor;
}

std::string AVL::QntdProteinas (std::list<std::string> consumidos)
{
	std::list<std::string>::iterator it;
	std::ostringstream oss;
	float qntd_total = 0.0;

	// itera por toda a lista adicionando as vitaminas
	// correspondentes às variáveis qntd_total
	for (it = consumidos.begin(); it != consumidos.end(); ++it)
		qntd_total += QntdProteinasInternal(* it);

	oss << "A quantidade total de Proteínas consumida foi de: "
		<< qntd_total << std::endl;
	return oss.str();
}

float AVL::QntdProteinasInternal (std::string nomeAlimento)
{
	// valor será um ponteiro para o início da lista
	// que guarda os dados de cada alimento
	auto valor = Search(nomeAlimento)->GetAlimento().GetNutrientes().begin();
	
	// incrementa o ponteiro para avançá-lo pela lista
	std::advance(valor, 9);
	return * valor;
}

std::string AVL::Qnt_Calories(std::list<std::string> consumidos){
	std::list<std::string>::iterator it;std::ostringstream oss;
	float qnt_total = 0.0;
	
	for  (it = consumidos.begin(); it != consumidos.end(); it++){
		qnt_total += Qnt_CaloriesInternal(* it);
	}
	oss << "Quantidade de calorias cosumidos é de:" << qnt_total << std::endl;

	return oss.str();

}

float AVL::Qnt_CaloriesInternal(std::string nomeAlimento){
	auto valor = Search(nomeAlimento)->GetAlimento().GetNutrientes().begin();
    std::advance(valor, 1);
    return * valor;
}

std::string AVL::ValoresNutri(std::string nomeAlimento) {
	
	std::ostringstream oss;

	std::string nomes[12] = {"calories: ","total fat (g): ", "sodium (g): ", "potassium (g): ", "total carbo-hydrate (g): ", "dietary Fiber (g): ", "sugars (g): ", "protein (g): ", "saturated fat (mg): ", "cholesterol (mg): ", "vitamin a (DV): ", "vitamin c (DV): "};
	float valores[12];
    for (int i = 0; i < 12; i++)
	{
		valores[i] = ValoresNutriInternal(nomeAlimento, i+2);
    }
    oss << nomes[0] << valores[0] 
	<<   nomes[1] << valores[1]
	<< nomes[2] << valores[2]
	<< nomes[3] << valores[3]
	<< nomes[4] << valores[4]
	<< nomes[5] << valores[5]
	<< nomes[6] << valores[6]
	<< nomes[7] << valores[7]
	<< nomes[8] << valores[8]
	<< nomes[9] << valores[9]
	<< nomes[10] << valores[10]
	<< nomes[11] << valores[11]
	<< std::endl;
    return oss.str();

}

float AVL::ValoresNutriInternal(std::string nomeAlimento, int pos){

    auto valor = Search(nomeAlimento)->GetAlimento().GetNutrientes().begin();
    
    std::advance(valor, pos);
    return * valor;

}