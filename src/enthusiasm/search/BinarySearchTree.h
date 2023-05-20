#ifndef FIRSTCPP_BINARYSEARCHTREE _H
#define FIRSTCPP_BINARYSEARCHTREE _H

#include "enthusiasm/tree/BinaryTree2.h"



namespace Collection{
    namespace Tree{
        template <class T>
        class BinarySearchTree{
        private:
            BinaryTreeNode<T>* root;

        public:
            BinarySearchTree();
            BinarySearchTree(BinarySearchTree&& ref) noexcept;
            BinarySearchTree& operator=(const BinarySearchTree& ref);
            BinarySearchTree& operator=(BinarySearchTree&& ref) noexcept;
            ~BinarySearchTree();

        public:
            void insert(const T& data);

            BinaryTreeNode<T>* search(const T& data);
        };

        template<class T>
        BinarySearchTree<T>::BinarySearchTree() : root(new BinaryTreeNode<T>(T())){
        }

        template<class T>
        BinarySearchTree<T>::BinarySearchTree(BinarySearchTree &&ref) noexcept {
            this->root = ref.root;
            ref.root = nullptr;
        }

        template<class T>
        BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree &ref) {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            this->traversalPolicy = ref.traversalPolicy;
            return *this;
        }

        template<class T>
        BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree &&ref) noexcept {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            this->traversalPolicy = ref.traversalPolicy;
            ref.left = nullptr;
            ref.right = nullptr;
            return *this;
        }

        template<class T>
        BinarySearchTree<T>::~BinarySearchTree() {
            delete root;
        }

        template<class T>
        void BinarySearchTree<T>::insert(const T &data) {
            BinaryTreeNode<T> *currentNode = root;
            BinaryTreeNode<T> *parentNode = nullptr;

            for (;currentNode != nullptr;) {
                
                if(data == currentNode->getData()){
                    return ;
                }
                
                parentNode = currentNode;
                
                if (currentNode->getData() > data){
                    currentNode = currentNode->getLeftSubTree();
                }else{
                    currentNode = currentNode->getRightSubTree();
                }
            }

            BinaryTreeNode <T> *newNode = new BinaryTreeNode<T>(data);
            if(parentNode == nullptr){
                *parentNode = *newNode;
            }else{
                if(parentNode->getData() > data){
                    parentNode->makeLeftSubTree(newNode);
                }else{
                    parentNode->makeRightSubTree(newNode);
                }
            }
        }

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::search(const T &data) {
            BinaryTreeNode<T> *currentNode = root;

            for (;currentNode != nullptr;) {

                if(data == currentNode->getData()){
                    return currentNode;
                }

                if (currentNode->getData() > data){
                    currentNode = currentNode->getLeftSubTree();
                }else{
                    currentNode = currentNode->getRightSubTree();
                }
            }
            return nullptr;
        }
    }
}

#endif // FIRSTCPP_BINARYSEARCHTREE _H

