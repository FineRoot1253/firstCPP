#include "enthusiasm/search/BinarySearchTree3.h"
#include <iostream>

using namespace Collection::Tree;

int main(){

    BinarySearchTree<int>* tree = new BinarySearchTree<int>();

    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->insert(8);
    tree->insert(9);

    tree->showHierarchyTree();

    return 0;
}


