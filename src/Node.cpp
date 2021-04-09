#include "Node.h"

Node::Node() {}

void Node::setData(int d) {
  data = d;
}

void Node::setParent(Node* p) {
  parent = p;
}

void Node::setLeft(Node* l) {
  left = l;
}

void Node::setRight(Node* r) {
  right = r;
}

int Node::getData() {
  return data;
}

Node* Node::getParent() {
  return parent;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}
