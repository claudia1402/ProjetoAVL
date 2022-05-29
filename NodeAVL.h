// NodeAVL.h
#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>
#include "Alimento.h"

class NodeAVL {
public:
  NodeAVL(int codAlimento, Alimento alimento, NodeAVL *parent = nullptr,
          NodeAVL *left = nullptr, NodeAVL *right = nullptr);
  ~NodeAVL();

  void CopynomeFrom(const NodeAVL *node);

  int GetcodAlimento() const;
  //void SetcodAlimento(int codAlimento);

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
  int m_codAlimento;
  Alimento m_alimento;

  NodeAVL *m_Parent;
  NodeAVL *m_Left;
  NodeAVL *m_Right;

  int m_BalanceFactor;

  int GetDepthInternal(const NodeAVL *node) const;
  int GetHeightInternal(const NodeAVL *node) const;
};

#endif