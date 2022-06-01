// ---------- Projeto II AVL - EDII ------------
// --------- Grupo cavalo_sentado.png ----------
// 	Claudia Fiorentino Andrade 		- 42005302
// 	João Victor Ferreira Pimenta 	- 42005876
// 	Joyce Cui 						- 42017157
//	Ryan Marco Andrade dos Santos 	- 42080223
// 	Victor Prado Chaves 			- 32070772


// NodeAVL.h
#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>
#include "Alimento.h"

class NodeAVL {
public:
  NodeAVL(Alimento alimento, NodeAVL *parent = nullptr,
          NodeAVL *left = nullptr, NodeAVL *right = nullptr);
  ~NodeAVL();

  void CopynomeFrom(const NodeAVL *node);

  std::string GetNomeAlimento() const;
  //void SetNomeAlimento(std::string nomeAlimento);

  Alimento GetAlimento() const;
  void SetAlimento(const Alimento &alimento);

  NodeAVL *GetParent() const;
  void SetParent(NodeAVL *parent);

  NodeAVL *GetLeft() const;
  void SetLeft(NodeAVL *left);

  NodeAVL *GetRight() const;
  void SetRight(NodeAVL *right);

  bool IsRoot() const;
  bool IsLeaf() const;

  int GetDegree() const;
  int GetDepth() const;
  int GetHeight() const;

  int GetBalanceFactor() const;
  void UpdateBalanceFactor();

  std::string ToString() const;
  std::string SimpleToString() const;

private:
  std::string m_nomeAlimento;
  Alimento m_alimento;

  NodeAVL *m_Parent;
  NodeAVL *m_Left;
  NodeAVL *m_Right;

  int m_BalanceFactor;

  int GetDepthInternal(const NodeAVL *node) const;
  int GetHeightInternal(const NodeAVL *node) const;
};

#endif