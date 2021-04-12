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

void RedBlackTree::remove(Node* n) {
  Node* replacement = nullptr;
  Node* replacementParent = nullptr;
  Node* replaceReplacement = nullptr;
  std::string oldColour = n->getColourName();
  if (n->getLeft() == nullptr && n->getRight() == nullptr) {

  } else if (n->getLeft() == nullptr || n->getRight() == nullptr) {
    if (n->getLeft() == nullptr) {
      replaceChild(n->getParent(), n, n->getRight());
      replacement = n->getRight();
    } else {
      replaceChild(n->getParent(), n, n->getLeft());
      replacement = n->getLeft();
    }
  } else {
    replacement = n->getRight();
    while (replacement->getLeft() != nullptr) {
      replacementParent = replacement;
      replacement = replacement->getLeft();
      replaceReplacement = replacement->getRight();
    }
    replaceChild(replacementParent, replacement, replaceReplacement);
    replaceChild(n->getParent(), n, replacement);
  }
  delete n;
  n = nullptr;
  if (oldColour == "red") {
    if(replacement->getColourName() == "red" || replacement == nullptr) {
      return;
    } else {
      replacement->setColour(Node::RED);
    }
  } else {
    if (replacement->getColourName() == "red") {
      replacement->setColour(Node::BLACK);
      return;
    }
  }
  Node* sibling = replaceReplacement->getSibling();
  if(replaceReplacement->getColourName() == "red") {
    replaceReplacement->setColour(Node::BLACK);
    return;
  }
  while(replaceReplacement->getColourName() == "black") {
    if (sibling->getColourName() == "red") {
      sibling->setColour(Node::BLACK);
      replaceReplacement->getParent()->setColour(Node::RED);
      if (replaceReplacement->getParent()->getLeft() == replaceReplacement) {
        rotateLeft(replaceReplacement->getParent());
      } else {
        rotateRight(replaceReplacement->getParent());
      }
      if (replaceReplacement->getParent()->getLeft() == replaceReplacement) {
        replaceReplacement->getParent()->setRight(sibling);
        sibling->setParent(replaceReplacement->getParent());
      } else {
        replaceReplacement->getParent()->setLeft(sibling);
        sibling->setParent(replaceReplacement->getParent());
      }
    }
    if (sibling->getLeft()->getColourName() == "black" || sibling->getLeft() == nullptr) {
      if (sibling->getRight()->getColourName() == "black" || sibling->getRight() == nullptr) {
        sibling->setColour(Node::RED);
        replaceReplacement = replaceReplacement->getParent();
        if (replaceReplacement->getColourName() == "red") {
          replaceReplacement->setColour(Node::BLACK);
          return;
        }
      }
    }
    if (sibling->getColourName() == "black") {
      if ((replaceReplacement->getParent()->getLeft() == replaceReplacement &&
          sibling->getLeft()->getColourName() == "red" && sibling->getRight()->
          getColourName() == "black")) {
        sibling->getLeft()->setColour(Node::BLACK);
        sibling->setColour(Node::RED);
        rotateRight(sibling);
        sibling = replaceReplacement->getParent()->getRight();
      }
      if ((replaceReplacement->getParent()->getRight() == replaceReplacement &&
          sibling->getRight()->getColourName() == "red" && sibling->getLeft()->
          getColourName() == "black")) {
        sibling->getRight()->setColour(Node::BLACK);
        sibling->setColour(Node::RED);
        rotateLeft(sibling);
        sibling = replaceReplacement->getParent()->getLeft();
      }
    }
    if (sibling->getColourName() == "black") {
      if(replaceReplacement->getParent()->getLeft() == replaceReplacement &&
        sibling->getRight()->getColourName() == "red") {
        if (replaceReplacement->getParent()->getColourName() == "red") {
          sibling->setColour(Node::RED);
        } else {
          sibling->setColour(Node::BLACK);
        }
        replaceReplacement->getParent()->setColour(Node::BLACK);
        sibling->getRight()->setColour(Node::BLACK);
        rotateLeft(replaceReplacement->getParent());
        return;
      }
      if(replaceReplacement->getParent()->getRight() == replaceReplacement &&
        sibling->getLeft()->getColourName() == "red") {
        if (replaceReplacement->getParent()->getColourName() == "red") {
          sibling->setColour(Node::RED);
        } else {
          sibling->setColour(Node::BLACK);
        }
        replaceReplacement->getParent()->setColour(Node::BLACK);
        sibling->getLeft()->setColour(Node::BLACK);
        rotateRight(replaceReplacement->getParent());
        return;
      }
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
