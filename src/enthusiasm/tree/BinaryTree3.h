#ifndef FIRSTCPP_BINARYTREE3 _H
#define FIRSTCPP_BINARYTREE3 _H

#include <iostream>

namespace Collection {
    namespace Tree {
        enum class TraversalPolicy : int {
            PREORDER = 0,
            INORDER,
            POSTORDER
        };

        template<class T>
        class BinaryTreeNode {
        private:
            T data;
            BinaryTreeNode *left;
            BinaryTreeNode *right;
            TraversalPolicy traversalPolicy;

        public:
            explicit BinaryTreeNode(const T &data);
            BinaryTreeNode(const BinaryTreeNode &ref);
            BinaryTreeNode(BinaryTreeNode &&ref) noexcept;
            BinaryTreeNode<T> &operator=(const BinaryTreeNode &ref);
            BinaryTreeNode<T> &operator=(BinaryTreeNode &&ref) noexcept;
            ~BinaryTreeNode();

        public:
            T getData() const;
            BinaryTreeNode *&getLeftSubTree() ;
            BinaryTreeNode *&getRightSubTree() ;

            void makeLeftSubTree(BinaryTreeNode *sub);
            void makeRightSubTree(BinaryTreeNode *sub);

            void changeTraversePolicy(TraversalPolicy traversalPolicy);
            void traverse(void (*callback)(const T &)) const;

            BinaryTreeNode<T> *removeLeftSubTree();
            BinaryTreeNode<T> *removeRightSubTree();

            void changeLeftSubTree(BinaryTreeNode<T> *node);
            void changeRightSubTree(BinaryTreeNode<T> *node);
        };

        template<class T>
        BinaryTreeNode<T>::BinaryTreeNode(const T &data)
                : data(data)
                  , left(nullptr)
                  , right(nullptr)
                  , traversalPolicy(TraversalPolicy::INORDER) {
        }

        template<class T>
        BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T> &ref)
                : data(ref.data)
                  , left(ref.left)
                  , right(ref.right)
                  , traversalPolicy(ref.traversalPolicy) {
        }

        template<class T>
        BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode<T> &&ref) noexcept {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            this->traversalPolicy = ref.traversalPolicy;
            ref.left = nullptr;
            ref.right = nullptr;
        }

        template<class T>
        BinaryTreeNode<T> &BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &ref) {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            this->traversalPolicy = ref.traversalPolicy;
            return *this;
        }

        template<class T>
        BinaryTreeNode<T> &BinaryTreeNode<T>::operator=(BinaryTreeNode &&ref) noexcept {
            this->data = ref.data;
            this->left = ref.left;
            this->right = ref.right;
            this->traversalPolicy = ref.traversalPolicy;
            ref.left = nullptr;
            ref.right = nullptr;
            return *this;
        }

        template<class T>
        BinaryTreeNode<T>::~BinaryTreeNode() {
            delete this->left;
            delete this->right;
        }

        template<class T>
        T BinaryTreeNode<T>::getData() const {
            return data;
        }

        template<class T>
        BinaryTreeNode<T> *&BinaryTreeNode<T>::getLeftSubTree()  {
            return left;
        }

        template<class T>
        BinaryTreeNode<T> *&BinaryTreeNode<T>::getRightSubTree()  {
            return right;
        }

        template<class T>
        void BinaryTreeNode<T>::makeLeftSubTree(BinaryTreeNode *sub) {
            if (this->left != nullptr) {
                delete this->left;
            }
            this->left = sub;
        }

        template<class T>
        void BinaryTreeNode<T>::makeRightSubTree(BinaryTreeNode *sub) {
            if (this->right != nullptr) {
                delete this->right;
            }
            this->right = sub;
        }

        template<class T>
        BinaryTreeNode<T> *BinaryTreeNode<T>::removeLeftSubTree() {
            BinaryTreeNode<T> *tempNode;
            if (this != nullptr) {
                tempNode = this->left;
                this->left = nullptr;
            }
            return tempNode;
        }

        template<class T>
        BinaryTreeNode<T> *BinaryTreeNode<T>::removeRightSubTree() {
            BinaryTreeNode<T> *tempNode;
            if (this != nullptr) {
                tempNode = this->right;
                this->right = nullptr;
            }
            return tempNode;
        }

        template<class T>
        void BinaryTreeNode<T>::changeLeftSubTree(BinaryTreeNode<T> *node) {
            this->left = node;
        }

        template<class T>
        void BinaryTreeNode<T>::changeRightSubTree(BinaryTreeNode<T> *node) {
            this->right = node;
        }

        template<class T>
        void BinaryTreeNode<T>::changeTraversePolicy(TraversalPolicy traversalPolicy) {
            this->traversalPolicy = traversalPolicy;
        }

        template<class T>
        void BinaryTreeNode<T>::traverse(void (*callback)(const T &)) const {
            switch (traversalPolicy) {
                case TraversalPolicy::PREORDER :
                    preorderTraverse(this, callback);
                    break;
                case TraversalPolicy::INORDER :
                    inorderTraverse(this, callback);
                    break;
                default:
                    postorderTraverse(this, callback);
                    break;
            }
        }

        template<class T>
        void preorderTraverse(const BinaryTreeNode<T> *binaryTreeNode, void (*callback)(const T &)) {
            if (binaryTreeNode == nullptr) {
                return;
            }

            callback(binaryTreeNode->getData());
            preorderTraverse(binaryTreeNode->getLeftSubTree(), callback);
            preorderTraverse(binaryTreeNode->getRightSubTree(), callback);
        }

        template<class T>
        void inorderTraverse(const BinaryTreeNode<T> *binaryTreeNode, void (*callback)(const T &)) {
            if (binaryTreeNode == nullptr) {
                return;
            }
            inorderTraverse(binaryTreeNode->getLeftSubTree(), callback);
            callback(binaryTreeNode->getData());
            inorderTraverse(binaryTreeNode->getRightSubTree(), callback);
        }

        template<class T>
        void postorderTraverse(const BinaryTreeNode<T> *binaryTreeNode, void (*callback)(const T &)) {
            if (binaryTreeNode == nullptr) {
                return;
            }
            postorderTraverse(binaryTreeNode->getLeftSubTree(), callback);
            postorderTraverse(binaryTreeNode->getRightSubTree(), callback);
            callback(binaryTreeNode->getData());
        }

        template<class T>
        void showData(const T &data) {
            std::cout << data << " ";
        }
    }
}

#endif // FIRSTCPP_BINARYTREE3 _H

