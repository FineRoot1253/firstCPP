#include "enthusiasm/search/BinarySearchTree2.h"

using namespace Collection::Tree;

int main(){
    BinarySearchTree<int> *tree = new BinarySearchTree<int>();
    tree->insert(5);
    tree->insert(8);
    tree->insert(1);
    tree->insert(6);
    tree->insert(4);
    tree->insert(9);
    tree->insert(3);
    tree->insert(2);
    tree->insert(7);

    tree->showAll();
    std::cout<<std::endl;
    delete tree->remove(3);

    tree->showAll();
    std::cout<<std::endl;
    delete tree->remove(8);

    tree->showAll();
    std::cout<<std::endl;
    delete tree->remove(1);

    tree->showAll();
    std::cout<<std::endl;
    delete tree->remove(6);

    tree->showAll();
    return 0;
}


