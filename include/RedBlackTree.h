#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include "Node.h"

class RedBlackTree {
 public:
  RedBlackTree();
  void setRootValue(int);
  int getRootValue();
  bool setChild(Node*, std::string, Node*);
  void replaceChild(Node*, Node*, Node*);

 private:
  Node* root = nullptr;
};
#endif
