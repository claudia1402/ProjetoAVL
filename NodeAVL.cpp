// ---------- Projeto II AVL - EDII ------------
// --------- Grupo cavalo_sentado.png ----------
// 	Claudia Fiorentino Andrade 		- 42005302
// 	João Victor Ferreira Pimenta 	- 42005876
// 	Joyce Cui 						- 42017157
//	Ryan Marco Andrade dos Santos 	- 42080223
// 	Victor Prado Chaves 			- 32070772

// NodeAVL.cpp
#include "NodeAVL.h"
#include "Utils.h"
#include <sstream>

NodeAVL::NodeAVL(Alimento alimento, NodeAVL *parent, NodeAVL *left, NodeAVL *right)
	: m_nomeAlimento(alimento.GetNome())
	, m_alimento(alimento)
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
	, m_BalanceFactor(0)
{
}

NodeAVL::~NodeAVL()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

void NodeAVL::CopynomeFrom(const NodeAVL* node)
{
	m_nomeAlimento = node->GetNomeAlimento();
	m_alimento = node->GetAlimento();
}

std::string NodeAVL::GetNomeAlimento() const
{
	return m_nomeAlimento;
}

Alimento NodeAVL::GetAlimento() const
{
	return m_alimento;
}

void NodeAVL::SetAlimento(const Alimento& alimento)
{
	m_alimento = alimento;
}

NodeAVL* NodeAVL::GetParent() const
{
	return m_Parent;
}

void NodeAVL::SetParent(NodeAVL* parent)
{
	m_Parent = parent;
}

NodeAVL* NodeAVL::GetLeft() const
{
	return m_Left;
}

void NodeAVL::SetLeft(NodeAVL* left)
{
	m_Left = left;
}

NodeAVL* NodeAVL::GetRight() const
{
	return m_Right;
}

void NodeAVL::SetRight(NodeAVL* right)
{
	m_Right = right;
}

bool NodeAVL::IsRoot() const
{
	return m_Parent == nullptr;
}

bool NodeAVL::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int NodeAVL::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int NodeAVL::GetDepth() const
{
	return GetDepthInternal(this);
}

int NodeAVL::GetDepthInternal(const NodeAVL* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int NodeAVL::GetHeight() const
{
	return GetHeightInternal(this);
}

int NodeAVL::GetHeightInternal(const NodeAVL* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}

int NodeAVL::GetBalanceFactor() const
{
	return m_BalanceFactor;
}

void NodeAVL::UpdateBalanceFactor()
{
	int leftHeight = m_Left == nullptr ? -1 : GetHeightInternal(m_Left);
	int rightHeight = m_Right == nullptr ? -1 : GetHeightInternal(m_Right);
	m_BalanceFactor = rightHeight - leftHeight;

	// Read the comments inside AVL::Balance().
	//m_BalanceFactor = leftHeight - rightHeight;
}

std::string NodeAVL::ToString() const
{
	std::ostringstream oss;

	oss << m_nomeAlimento
		<< " (" << m_alimento.GetNome() << ")"
		<< " Parent:" << (m_Parent != nullptr ? m_Parent->GetNomeAlimento() : "")
		<< " Left:" << (m_Left != nullptr ? m_Left->GetNomeAlimento() : "")
		<< " Right:" << (m_Right != nullptr ? m_Right->GetNomeAlimento() : "")
		<< " Degree: " << GetDegree()
		<< " Depth: " << GetDepth()
		<< " Height: " << GetHeight()
		<< " Balance: " << m_BalanceFactor << '\n';

	return oss.str();
}

// mostra apenas informações relevantes do alimento,
// diferentemente do ToString() que apresenta dados
// sobre a árvore também;
std::string NodeAVL::SimpleToString() const
{
	std::ostringstream oss;

	oss << m_nomeAlimento
		<< " (" << m_alimento.GetNome() << ")";

	return oss.str();
}
