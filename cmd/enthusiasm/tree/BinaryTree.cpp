#include "enthusiasm/tree/BinaryTree.h"

using namespace Collection::Tree;

int main(){
    BinaryTreeNode<int>* binaryTreeNode1 = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* binaryTreeNode2 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* binaryTreeNode3 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* binaryTreeNode4 = new BinaryTreeNode<int>(4);

    binaryTreeNode1->makeLeftSubTree(binaryTreeNode2);
    binaryTreeNode1->makeRightSubTree(binaryTreeNode3);
    binaryTreeNode2->makeLeftSubTree(binaryTreeNode4);

    std::cout<<binaryTreeNode1->getLeftSubTree()->getData()<<std::endl;
    std::cout<<binaryTreeNode1->getLeftSubTree()->getLeftSubTree()->getData()<<std::endl;
    return 0;
}


