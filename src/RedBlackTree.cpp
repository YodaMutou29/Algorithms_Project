#include "RedBlackTree.h"
#include "Node.h"
#include <iostream>

RedBlackTree::RedBlackTree() {
  root->setColour(Node::BLACK);
}

RedBlackTree::~RedBlackTree() {
  delete root;
}

void RedBlackTree::rotateLeft(Node* n) {
  Node* leftOfRightChild = (n->getRight())->getLeft();
  if (n->getParent() != nullptr) {
    replaceChild(n->getParent(), n, n->getRight());
  } else { //node is root
    root->setRight(n->getRight());
    root->setParent(nullptr);
  }
  setChild(n->getRight(), "left", n);
  setChild(n, "right", leftOfRightChild);
}

void RedBlackTree::rotateRight(Node* n) {
  Node* rightOfLeftChild = (n->getLeft())->getRight();
  if (n->getParent() != nullptr) {
    replaceChild(n->getParent(), n, n->getLeft());
  } else { //node is root
    root->setLeft(n->getLeft());
    root->setParent(nullptr);
  }
  setChild(n->getLeft(), "right", n);
  setChild(n, "left", rightOfLeftChild);
}

void RedBlackTree::setRoot(Node* r) {
  //std::cout << "setting root value to " << v << std::endl;
  root = r;
}

Node* RedBlackTree::getRoot() {
  //std::cout << "returning root data of " << root->getData() << std::endl;
  return root;
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
  if (child != nullptr) {
    child->setParent(parent);
  }
  return true;
}

bool RedBlackTree::replaceChild(Node* parent, Node* currentChild, Node* newChild) {
  if (parent->getLeft() == currentChild) {
    return setChild(parent, "left", newChild);
  } else if (parent->getRight() == currentChild) {
    return setChild(parent, "right", newChild);
  }
  return false;
}

std::ostream& operator<< (std::ostream& out, RedBlackTree* r) {
  return out;
}

std::ostream& operator<< (std::ostream& out, Node* n) {
  std::cout << "[" << n->getColourName() << ", " << n->getData() << "]";
  return out;
}
