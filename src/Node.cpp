#include "Node.h"

Node::Node() {}

void Node::setLeft(int* l) {
  left = l;
}

void Node::setRight(int* r) {
  right = r;
}

int* Node::getLeft() {
  return left;
}

int* Node::getRight() {
  return right;
}
