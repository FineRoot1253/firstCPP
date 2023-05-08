#include "enthusiasm/search/BinarySearchTree.h"

using namespace Collection::Tree;

void printResult(const BinaryTreeNode<int>* result){
    if(result != nullptr){
        std::cout<<"탐색에 성공한 키의 값: "<<result->getData()<<std::endl;
    }else{
        std::cout<<"탐색 실패!"<<std::endl;
    }
}

int main(){
    BinarySearchTree<int>* tree = new BinarySearchTree<int>();
    BinaryTreeNode<int>* result = nullptr;

    tree->insert(9);
    tree->insert(1);
    tree->insert(6);
    tree->insert(2);
    tree->insert(8);
    tree->insert(3);
    tree->insert(5);

    result = tree->search(1);
    printResult(result);

    result = tree->search(4);
    printResult(result);

    result = tree->search(6);
    printResult(result);

    result = tree->search(7);
    printResult(result);

    return 0;
}




