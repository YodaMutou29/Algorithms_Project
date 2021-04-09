#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  void setLeft(int*);
  void setRight(int*);
  int* getLeft();
  int* getRight();

 private:
  int* left = nullptr;
  int* right = nullptr;
};
#endif
