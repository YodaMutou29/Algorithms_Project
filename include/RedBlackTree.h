#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"

class RedBlackTree {
 public:
  RedBlackTree();
  void setChild(Node*, Node*, Node*);
  void replaceChild(Node*, Node*, Node*);
};
#endif
