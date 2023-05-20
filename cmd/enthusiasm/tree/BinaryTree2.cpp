#include "enthusiasm/tree/BinaryTree2.h"
using namespace Collection::Tree;

int main(){

    BinaryTreeNode<int>* binaryTreeNode1 = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* binaryTreeNode2 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* binaryTreeNode3 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* binaryTreeNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* binaryTreeNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* binaryTreeNode6 = new BinaryTreeNode<int>(6);

    binaryTreeNode1->makeLeftSubTree(binaryTreeNode2);
    binaryTreeNode1->makeRightSubTree(binaryTreeNode3);
    binaryTreeNode2->makeLeftSubTree(binaryTreeNode4);
    binaryTreeNode2->makeRightSubTree(binaryTreeNode5);
    binaryTreeNode3->makeLeftSubTree(binaryTreeNode6);

    binaryTreeNode1->changeTraversePolicy(TraversalPolicy::PREORDER);
    binaryTreeNode1->traverse(showData);
    std::cout<<std::endl;

    binaryTreeNode1->changeTraversePolicy(TraversalPolicy::INORDER);
    binaryTreeNode1->traverse(showData);
    std::cout<<std::endl;

    binaryTreeNode1->changeTraversePolicy(TraversalPolicy::POSTORDER);
    binaryTreeNode1->traverse(showData);
    std::cout<<std::endl;

    return 0;
}




