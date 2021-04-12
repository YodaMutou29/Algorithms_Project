#include "RedBlackTree.h"
#include "Node.h"
#include <math.h>
#include <iostream>

RedBlackTree::RedBlackTree() {
  root->setColour(Node::BLACK);
}

RedBlackTree::~RedBlackTree() {
  delete root;
}

void RedBlackTree::rotateLeft(RedBlackTree* t, Node* n) {
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

void RedBlackTree::rotateRight(RedBlackTree* t, Node* n) {
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

void RedBlackTree::insert(Node* n) {
  Node* checkNode = nullptr;
  if (getRoot()->getLeft() == nullptr && getRoot()->getRight() == nullptr) {
    setRoot(n);
  } else {
    checkNode = getRoot();
    while (n->getParent() == nullptr) {
      if (n->getData() == checkNode->getData()) {
        std::cout << "Error: Node could not be added (Duplicate Node)" << std::endl;
        return;
      } else if (n->getData() > checkNode->getData()) {
        if(checkNode->getRight() == nullptr) {
          setChild(checkNode, "right", n);
        } else {
          checkNode = checkNode->getRight();
        }
      } else {
        if(checkNode->getLeft() == nullptr) {
          setChild(checkNode, "left", n);
        } else {
          checkNode = checkNode->getLeft();
        }
      }
    }
  }
  n->setColour(Node::RED);
  if (n->getGrandparent() == nullptr) {
    if (n->getParent() == nullptr)
      n->setColour(Node::BLACK);
  } else if (n->getUncle() == nullptr || n->getUncle()->getColourName() == "black") {
    if (n->getGrandparent()->getLeft() == n->getParent()) {
      if (n->getParent()->getRight() == n) {
        rotateLeft(n->getParent());
      } else {
        if(n->getParent()->getColourName() == "red") {
          n->getParent()->setColour(Node::BLACK);
        } else {
          n->getParent()->setColour(Node::RED);
        }
        if(n->getGrandparent()->getColourName() == "black") {
          n->getGrandparent()->setColour(Node::BLACK);
        } else {
          n->getGrandparent()->setColour(Node::RED);
        }
        rotateRight(n->getGrandparent());
      }
    } else {
      if (n->getParent()->getLeft() == n) {
        rotateRight(n->getParent());
      } else {
        if(n->getParent()->getColourName() == "red") {
          n->getParent()->setColour(Node::BLACK);
        } else {
          n->getParent()->setColour(Node::RED);
        }
        if(n->getGrandparent()->getColourName() == "black") {
          n->getGrandparent()->setColour(Node::BLACK);
        } else {
          n->getGrandparent()->setColour(Node::RED);
        }
        rotateLeft(n->getGrandparent());
      }
    }
  } else {
    if (n->getParent()->getColourName() == "red") {
      n->getParent()->setColour(Node::BLACK);
    } else {
      n->getParent()->setColour(Node::RED);
    }
    if (n->getGrandparent()->getColourName() == "red") {
      n->getGrandparent()->setColour(Node::BLACK);
    } else {
      n->getGrandparent()->setColour(Node::RED);
    }
    if (n->getUncle()->getColourName() == "red") {
      n->getUncle()->setColour(Node::BLACK);
    } else {
      n->getUncle()->setColour(Node::RED);
    }
  }
}

int RedBlackTree::getHeight() {
  return log2(numOfNodes);
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
    numOfNodes++;
  } else {
    parent->setRight(child);
    numOfNodes++;
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
  out << "Root: " << r->getRoot() << std::endl;
  return out;
}

std::ostream& operator<< (std::ostream& out, Node* n) {
  if (n == nullptr) {
    out << "            ";
  } else {
    out << "[" << n->getColourName() << ", " << n->getData() << "]";
    out << " L: " << n->getLeft() << "  R: " << n->getRight();
  }
  return out;
}
