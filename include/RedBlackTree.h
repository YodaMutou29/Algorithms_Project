/*
* Sources used
* https://learn.zybooks.com/zybook/DataStructuresEssentialsJavaR30/chapter/7/section/7
* (used for red black tree algorithm)
*/
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include "Node.h"

class RedBlackTree {
 public:
  RedBlackTree();
  ~RedBlackTree();

  void rotateLeft(Node*);
  void rotateRight(Node*);

  void setRoot(Node*);
  Node* getRoot();
  bool setChild(Node*, std::string, Node*);
  bool replaceChild(Node*, Node*, Node*);

 private:
  Node* root = new Node();
};
#endif
