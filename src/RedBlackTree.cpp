#include "RedBlackTree.h"
#include "Node.h"

RedBlackTree::RedBlackTree() {}

void RedBlackTree::setRootValue(int v) {
  root->setData(v);
}

int RedBlackTree::getRootValue() {
  return root->getData();
}

bool RedBlackTree::setChild(Node* parent, std::string whichChild, Node* child) {
  if (whichChild != "left" && whichChild != "right") {
    return false;
  }
  if (whichChild == "left") {
    parent->setLeft(child);
  } else {
    parent->setRight(child);
  }
  if (child != null) {
    child->setParent(parent);
  }
  return true;
}

void RedBlackTree::replaceChild(Node* parent, Node* currentChild, Node* newChild) {

}
