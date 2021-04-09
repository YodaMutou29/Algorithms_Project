#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include "Node.h"

class RedBlackTree {
 public:
  RedBlackTree();
  bool setChild(Node*, std::string, Node*);
  void replaceChild(Node*, Node*, Node*);
};
#endif
