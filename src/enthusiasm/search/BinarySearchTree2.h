#ifndef FIRSTCPP_BINARYSEARCHTREE2 _H
#define FIRSTCPP_BINARYSEARCHTREE2 _H
#include "enthusiasm/tree/BinaryTree3.h"

namespace Collection{
    namespace Tree{
        template <class T>
        class BinarySearchTree{
        private:
            BinaryTreeNode<T>* root;

        private:
            void removeLeafNode(BinaryTreeNode<T>* parentNode, const BinaryTreeNode<T>* targetNode);
            void removeWithSingleChildNode(BinaryTreeNode<T>* parentNode, const BinaryTreeNode<T>* targetNode);
            void removeWithChildNodes(BinaryTreeNode<T>* parentNode, BinaryTreeNode<T>* targetNode);

        public:
            BinarySearchTree();
            BinarySearchTree(BinarySearchTree&& ref) noexcept;
            BinarySearchTree& operator=(const BinarySearchTree& ref);
            BinarySearchTree& operator=(BinarySearchTree&& ref) noexcept;
            ~BinarySearchTree();

        public:
            void insert(const T& data);
            BinaryTreeNode<T>* remove(const T& target);
            BinaryTreeNode<T>* search(const T& target) const;
            void showAll() const;
        };

        template<class T>
        BinarySearchTree<T>::BinarySearchTree() : root(nullptr){
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
                parentNode = newNode;
                if(root == nullptr){
                    root = parentNode;
                }
            }else{
                if(parentNode->getData() > data){
                    parentNode->makeLeftSubTree(newNode);
                }else{
                    parentNode->makeRightSubTree(newNode);
                }
            }
        }

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::search(const T &target) const{
            BinaryTreeNode<T> *currentNode = root;

            for (;currentNode != nullptr;) {

                if(target == currentNode->getData()){
                    return currentNode;
                }

                if (currentNode->getData() > target){
                    currentNode = currentNode->getLeftSubTree();
                }else{
                    currentNode = currentNode->getRightSubTree();
                }
            }
            return nullptr;
        }

        template <class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::remove(const T &target) {
            BinaryTreeNode <T> *virtualRootNode = new BinaryTreeNode<T>(T());
            BinaryTreeNode<T> *parentNode = virtualRootNode;
            BinaryTreeNode<T> *currentNode = root;
            BinaryTreeNode<T> *targetNode;

            virtualRootNode->changeRightSubTree(root);

            for (;currentNode != nullptr && currentNode->getData() != target;) {
                parentNode = currentNode;
                if(target < currentNode->getData()){
                    currentNode = currentNode->getLeftSubTree();
                }else{
                    currentNode = currentNode->getRightSubTree();
                }
            }
            if(currentNode == nullptr){
                return nullptr;
            }

            targetNode = currentNode;

            if(targetNode->getLeftSubTree() == nullptr && targetNode->getRightSubTree()== nullptr){
                removeLeafNode(parentNode, targetNode);
            }else if(targetNode->getLeftSubTree()== nullptr || targetNode->getRightSubTree() == nullptr){
                removeWithSingleChildNode(parentNode, targetNode);
            }else{
                removeWithChildNodes(parentNode, targetNode);
            }

            if(virtualRootNode->getRightSubTree() != root){
                root = virtualRootNode->getRightSubTree();
            }
            if(virtualRootNode->getRightSubTree() != nullptr){
                virtualRootNode->changeRightSubTree(nullptr);
            }

            if(targetNode->getRightSubTree()!= nullptr){
                targetNode->removeRightSubTree();
            }else if(targetNode->removeLeftSubTree()!= nullptr){
                targetNode->removeLeftSubTree();
            }

            delete virtualRootNode;
            return targetNode;
        }

        template<class T>
        void BinarySearchTree<T>::removeLeafNode(BinaryTreeNode<T>* parentNode,
                                                 const BinaryTreeNode<T>* targetNode) {
            if(parentNode->getLeftSubTree() == targetNode){
                parentNode->removeLeftSubTree();
            }else{
                parentNode->removeRightSubTree();
            }
        }

        template<class T>
        void BinarySearchTree<T>::removeWithSingleChildNode(BinaryTreeNode<T>* parentNode,
                                                            const BinaryTreeNode<T>* targetNode) {
            BinaryTreeNode<T>* targetChildNode;

            if(targetNode->getLeftSubTree() != nullptr){
                targetChildNode = targetNode->getLeftSubTree();
            }else{
                targetChildNode = targetNode->getRightSubTree();
            }

            if(parentNode->getLeftSubTree() == targetNode){
                parentNode->changeLeftSubTree(targetChildNode);
            }else{
                parentNode->changeRightSubTree(targetChildNode);
            }
        }

        template<class T>
        void BinarySearchTree<T>::removeWithChildNodes(BinaryTreeNode<T>* parentNode, BinaryTreeNode<T>* targetNode) {
            BinaryTreeNode<T>* tempNode = targetNode->getRightSubTree();
            BinaryTreeNode<T>* tempParentNode = targetNode;
            T resultData;

            while(tempNode->getLeftSubTree() != nullptr){
                tempParentNode = tempNode;
                tempNode = tempNode->getLeftSubTree();
            }

            if(tempParentNode->getLeftSubTree() == tempNode){
                tempParentNode->changeLeftSubTree(tempNode->getRightSubTree());
            }else{
                tempParentNode->changeRightSubTree(tempNode->getRightSubTree());
            }

            resultData = targetNode->getData();
            BinaryTreeNode <T> *newNode = new BinaryTreeNode<T>(tempNode->getData());
            newNode->makeLeftSubTree(targetNode->getLeftSubTree());
            newNode->makeRightSubTree(targetNode->getRightSubTree());

            if(parentNode->getRightSubTree() == targetNode){
                parentNode->changeRightSubTree(newNode);
            }else{
                parentNode->changeLeftSubTree(newNode);
            }

            targetNode->removeLeftSubTree();
            targetNode->removeRightSubTree();
            delete targetNode;



            BinaryTreeNode <T> *newNode2 = new BinaryTreeNode<T>(resultData);
            newNode2->makeLeftSubTree(tempNode->getLeftSubTree());
            newNode2->makeRightSubTree(tempNode->getRightSubTree());

            targetNode = newNode2;
        }

        template<class T>
        void BinarySearchTree<T>::showAll() const {
            root->changeTraversePolicy(TraversalPolicy::INORDER);
            root->traverse(showData);
        }


    }
}
#endif // FIRSTCPP_BINARYSEARCHTREE2 _H

