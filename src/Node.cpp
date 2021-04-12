#include "Node.h"
#include <iostream>
#include <string>

Node::Node() {}

void Node::setData(int d) {
  data = d;
  //std::cout << "data now set to " << data << std::endl;
}

void Node::setColour(Colour c) {
  colour = c;
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

std::string Node::getColourName() {
  if (colour == BLACK) {
    return "black";
  }
  return "red";
}

Node* Node::getParent() {
  return parent;
}

Node* Node::getGrandparent() {
  return parent->getParent();
}

Node* Node::getSibling() {
  if (parent->getLeft() == this) {
    return parent->getRight();
  } else {
    return parent->getLeft();
  }
}

Node* Node::getUncle() {
  if (getGrandparent() != nullptr) {
    if (parent == getGrandparent()->getLeft()) {
      return getGrandparent()->getRight();
    } else {
      return getGrandparent()->getLeft();
    }
  }
  return nullptr;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}
