#ifndef FIRSTCPP_BINARYTREE _H
#define FIRSTCPP_BINARYTREE _H

#include <iostream>

namespace Collection{
    namespace Tree{
        template <class T>
        class BinaryTreeNode{
        private:
            T data;
            BinaryTreeNode* left;
            BinaryTreeNode* right;

        public:
            explicit BinaryTreeNode(const T& data);
            BinaryTreeNode(const BinaryTreeNode& ref);
            BinaryTreeNode(BinaryTreeNode&& ref);
            BinaryTreeNode& operator=(const BinaryTreeNode& ref);
            ~BinaryTreeNode();

        public:
            T getData();
            BinaryTreeNode* getLeftSubTree();
            BinaryTreeNode* getRightSubTree();
            void makeLeftSubTree(BinaryTreeNode* sub);
            void makeRightSubTree(BinaryTreeNode* sub);
        };

        template <class T>
        BinaryTreeNode<T>::BinaryTreeNode(const T& data)
        : data(data)
        , left(nullptr)
        , right(nullptr) {
        }

        template <class T>
        BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T> &ref)
        : data(ref.data)
        , left(ref.left)
        , right(ref.right) {
        }

        template <class T>
        BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode<T> &&ref) {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            ref.left = nullptr;
            ref.right = nullptr;
        }

        template <class T>
        BinaryTreeNode<T> &BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &ref) {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            return *this;
        }

        template <class T>
        BinaryTreeNode<T>::~BinaryTreeNode() {
            if(left != nullptr){
                delete left;
            }
            if(right != nullptr){
                delete right;
            }
        }

        template <class T>
        T BinaryTreeNode<T>::getData() {
            return data;
        }

        template <class T>
        BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftSubTree() {
            return left;
        }

        template <class T>
        BinaryTreeNode<T>* BinaryTreeNode<T>::getRightSubTree() {
            return right;
        }

        template <class T>
        void BinaryTreeNode<T>::makeLeftSubTree(BinaryTreeNode<T> *sub) {
            if(this->left != nullptr){
                delete this->left;
            }
            this->left = sub;
        }

        template <class T>
        void BinaryTreeNode<T>::makeRightSubTree(BinaryTreeNode<T> *sub) {
            if(this->right != nullptr){
                delete this->right;
            }
            this->right = sub;
        }
    }
}

#endif // FIRSTCPP_BINARYTREE _H

