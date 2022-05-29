// NodeAVL.h
#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>
#include "Product.h"

class NodeAVL {
public:
  NodeAVL(int codProduto, Product produto, NodeAVL *parent = nullptr,
          NodeAVL *left = nullptr, NodeAVL *right = nullptr);
  ~NodeAVL();

  void CopynomeFrom(const NodeAVL *node);

  int GetcodProduto() const;
  //void SetcodProduto(int codProduto);

  Product GetProduto() const;
  void SetProduto(const Product &produto);

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
  int m_codProduto;
  Product m_produto;

  NodeAVL *m_Parent;
  NodeAVL *m_Left;
  NodeAVL *m_Right;

  int m_BalanceFactor;

  int GetDepthInternal(const NodeAVL *node) const;
  int GetHeightInternal(const NodeAVL *node) const;
};

#endif