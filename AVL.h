// ---------- Projeto II AVL - EDII ------------
// --------- Grupo cavalo_sentado.png ----------
// 	Claudia Fiorentino Andrade 		- 42005302
// 	João Victor Ferreira Pimenta 	- 42005876
// 	Joyce Cui 						- 42017157
//	Ryan Marco Andrade dos Santos 	- 42080223
// 	Victor Prado Chaves 			- 32070772

// AVL.h
#ifndef __AVL_H__
#define __AVL_H__

#include "NodeAVL.h"
#include "Alimento.h"
#include <list>
#include <iterator>

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

	NodeAVL* Predecessor(std::string nomeAlimento) const;
	NodeAVL* Successor(std::string nomeAlimento) const;

	NodeAVL* Search(std::string nomeAlimento) const;
	NodeAVL* Search_name(std::string n_Alimento) const;
	NodeAVL* Insert(Alimento Alimento);
	void Remove(std::string nomeAlimento);

	std::string Sintese(std::list<std::string> consumidos);



	std::string OutrasInfos (std::list<std::string> consumidos);

	std::string QntdProteinas (std::list<std::string> consumidos);


	std::string QntdVitaminas (std::list<std::string> consumidos);


	std::string Qnt_Calories(std::list<std::string> consumidos);

	std::string ValoresNutri(std::string nomeAlimento);




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

	NodeAVL* SearchInternal(NodeAVL* node, std::string nomeAlimento) const;
	NodeAVL* SearchInternal_name(NodeAVL* node, std::string nomeAlimento) const;
	NodeAVL* InsertInternal(NodeAVL* node, NodeAVL* parent, Alimento alimento);
	NodeAVL* RemoveInternal(NodeAVL* node, std::string nomeAlimento);
	NodeAVL* RemoveNode(NodeAVL* node);
	void UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild);
	float Qnt_CaloriesInternal(std::string nomeAlimento);

	NodeAVL* RotateLeft(NodeAVL* node);
	NodeAVL* RotateRight(NodeAVL* node);
	NodeAVL* RotateLeftRight(NodeAVL* node);
	NodeAVL* RotateRightLeft(NodeAVL* node);
	NodeAVL* Balance(NodeAVL* node);

	void SinteseInternal(float totais[], std::string nomeAlimento);


	void OutrasInfosInternal (std::string nomeAlimento, float qnts[]);


	float QntdProteinasInternal (std::string nomeAlimento);

	float QntdVitaminasInternal (std::string nomeAlimento, int vit);

	float ValoresNutriInternal(std::string nomeAlimento, int pos);
};

#endif