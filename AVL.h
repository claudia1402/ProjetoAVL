// AVL.h
#ifndef __AVL_H__
#define __AVL_H__

#include "NodeAVL.h"
#include "Product.h"

class AVL
{
public:
	AVL();
	~AVL();

	NodeAVL* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;

	std::string SimpleTraverseInOrder() const;

	NodeAVL* FindMin() const;
	NodeAVL* FindMax() const;

	NodeAVL* Predecessor(int codProduto) const;
	NodeAVL* Successor(int codProduto) const;

	NodeAVL* Search(int codProduto) const;
	NodeAVL* Search_name(std::string n_produto) const;
	NodeAVL* Insert(int codProduto, Product produto);
	void Remove(int codProduto);

	float StockValue() const;
	std::string percorre (int quant);
	

private:
	NodeAVL* m_Root;

	void Destroy(NodeAVL *node);
	
	int GetDegreeInternal(const NodeAVL* node) const;

	std::string TraverseInOrderInternal(const NodeAVL* node) const;
	std::string TraversePreOrderInternal(const NodeAVL* node) const;
	std::string TraversePostOrderInternal(const NodeAVL* node) const;

	std::string SimpleTraverseInOrderInternal(const NodeAVL* node) const;

	NodeAVL* FindMinInternal(NodeAVL* node) const;
	NodeAVL* FindMaxInternal(NodeAVL* node) const;

	NodeAVL* PredecessorInternal(NodeAVL* node) const;
	NodeAVL* SuccessorInternal(NodeAVL* node) const;

	NodeAVL* SearchInternal(NodeAVL* node, int& codProduto) const;
	NodeAVL* SearchInternal_name(NodeAVL* node, std::string n_produto) const;
	NodeAVL* InsertInternal(NodeAVL* node, NodeAVL* parent, int codProduto, Product produto);
	NodeAVL* RemoveInternal(NodeAVL* node, int codProduto);
	NodeAVL* RemoveNode(NodeAVL* node);
	void UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild);

	NodeAVL* RotateLeft(NodeAVL* node);
	NodeAVL* RotateRight(NodeAVL* node);
	NodeAVL* RotateLeftRight(NodeAVL* node);
	NodeAVL* RotateRightLeft(NodeAVL* node);

	NodeAVL* Balance(NodeAVL* node);
	float StockValueInternal(const NodeAVL* node, float totalValue) const;
};

#endif