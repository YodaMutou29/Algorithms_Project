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

  void rotateLeft(Node*); //fix (root node should be black and 2)
  void rotateRight(Node*); //fix?
  //add an insert function
  //add a remove function

  void setRoot(Node*);
  Node* getRoot();
  bool setChild(Node*, std::string, Node*);
  bool replaceChild(Node*, Node*, Node*);

 private:
  Node* root = new Node();
};
//implement ostream override
std::ostream& operator<< (std::ostream&, RedBlackTree*);
std::ostream& operator<< (std::ostream&, Node*);
#endif
