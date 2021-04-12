#include <iostream>
#include <time.h>
#include "RedBlackTree.h"
#include "Node.h"

int main() {
  std::cout << "Making new red black tree..." << std::endl;
  RedBlackTree* rbt = new RedBlackTree();

  std::cout << "Setting root to 5..." << std::endl;
  (rbt->getRoot())->setData(5);

  std::cout << "Setting left node of root to 3..." << std::endl;
  (rbt->getRoot())->setLeft(new Node());
  ((rbt->getRoot())->getLeft())->setData(3);
  std::cout << rbt << std::endl;
  delete rbt;
  rbt = nullptr;
  std::cout << std::endl;

  std::cout << "Let's create a scenario where we need to do a left rotation." << std::endl;
  std::cout << "Making new red black tree..." << std::endl;
  rbt = new RedBlackTree();

  std::cout << "Setting the root's colour to red..." << std::endl;
  (rbt->getRoot())->setColour(Node::RED);
  std::cout << "Setting root to 4..." << std::endl;
  (rbt->getRoot())->setData(4);
  //std::cout << "Root: " << rbt->getRoot() << std::endl;;

  std::cout << "Setting right node of root to 2..." << std::endl;
  (rbt->getRoot())->setRight(new Node());
  ((rbt->getRoot())->getRight())->setData(2);
  std::cout << "Setting colour of right node to black..." << std::endl;
  ((rbt->getRoot())->getRight())->setColour(Node::BLACK);
  if (((rbt->getRoot())->getRight())->getParent() == nullptr) {
    std::cout << "you goofed" << std::endl;
  }
  //std::cout << "Right: " << (rbt->getRoot())->getRight() << std::endl;

  std::cout << "Setting right node of right node of root to 1..." << std::endl;
  ((rbt->getRoot())->getRight())->setRight(new Node());
  (((rbt->getRoot())->getRight())->getRight())->setData(1);
  std::cout << "Setting colour of right node of right node to red..." << std::endl;
  (((rbt->getRoot())->getRight())->getRight())->setColour(Node::RED);
  //std::cout << "Right of right: " << ((rbt->getRoot())->getRight())->getRight()
    //<< std::endl;
  std::cout << rbt << std::endl;


  std::cout << "Performing a left rotation..." << std::endl;
  rbt->rotateLeft((rbt->getRoot())->getRight());
  std::cout << "Root: " << rbt->getRoot()<< std::endl;

  std::cout << "Testing time complexity: " << std::endl;
  clock_t t = clock();
  for (int i = 0; i < 10000; i++) {
    Node* n = new Node();
    n->setColour(Node::RED);
    n->setData(i);
    rbt->insert(n);
  }
  t = clock() - t;
  std::cout << "When n = 10000, it takes " << ((float)t)/CLOCKS_PER_SEC <<
  " seconds to insert them." << std::endl;
  return 0;
}
