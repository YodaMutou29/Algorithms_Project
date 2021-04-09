#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  void setData(int);
  void setParent(Node*);
  void setLeft(Node*);
  void setRight(Node*);

  int getData();
  Node* getParent();
  Node* getLeft();
  Node* getRight();

 private:
  int data;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
};
#endif
