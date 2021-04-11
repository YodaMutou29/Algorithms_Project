#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
 public:
   enum Colour{RED, BLACK};
  Node();
  void setData(int);
  void setColour(Colour);
  void setParent(Node*);
  void setLeft(Node*);
  void setRight(Node*);

  int getData();
  std::string getColourName();
  Node* getParent();
  Node* getGrandparent();
  Node* getSibling();
  Node* getUncle();
  Node* getLeft();
  Node* getRight();

 private:
  int data = 0;
  Colour colour;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
};
#endif
