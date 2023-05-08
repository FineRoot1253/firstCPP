#ifndef FIRSTCPP_BINARYSEARCHTREE3 _H
#define FIRSTCPP_BINARYSEARCHTREE3 _H
#include "enthusiasm/tree/BinaryTree3.h"
#include "AVLRebalance.h"

namespace Collection{
    namespace Tree{
        template <class T>
        class BinarySearchTree: public Collection::Tree::AVLRebalance<T>{
        private:
            BinaryTreeNode<T>* root;

        private:
            void removeLeafNode(BinaryTreeNode<T>* parentNode, const BinaryTreeNode<T>* targetNode);
            void removeWithSingleChildNode(BinaryTreeNode<T>* parentNode, const BinaryTreeNode<T>* targetNode);
            void removeWithChildNodes(BinaryTreeNode<T>* parentNode, BinaryTreeNode<T>* targetNode);
            BinaryTreeNode<T> * _insertInternal(BinaryTreeNode<T> *&node, const T& data);

        public:
            BinarySearchTree();
            BinarySearchTree(BinarySearchTree&& ref) noexcept;
            BinarySearchTree& operator=(const BinarySearchTree& ref);
            BinarySearchTree& operator=(BinarySearchTree&& ref) noexcept;
            ~BinarySearchTree();

        protected:
            BinaryTreeNode<T>* rotateLL(BinaryTreeNode<T>* binaryTreeNode) override;
            BinaryTreeNode<T>* rotateRR(BinaryTreeNode<T>* binaryTreeNode) override;
            BinaryTreeNode<T>* rotateLR(BinaryTreeNode<T>* binaryTreeNode) override;
            BinaryTreeNode<T>* rotateRL(BinaryTreeNode<T>* binaryTreeNode) override;
            int getHeight(BinaryTreeNode<T>* binaryTreeNode) const override;
            int getHeightDiff(BinaryTreeNode<T>* binaryTreeNode) const  override;

        public:
            void insert(const T& data);
            BinaryTreeNode<T>* remove(const T& target);
            BinaryTreeNode<T>* search(const T& target) const;
            void showAll() const;
            void showHierarchyTree() const;
            
        public:
            void rebalance() override;
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
            _insertInternal(root, data);
        }

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::_insertInternal(BinaryTreeNode<T> *&node, const T &data) {
            if(node == nullptr){
                node = new BinaryTreeNode<T>(data);
//                BinaryTreeNode <T> *newNode = new BinaryTreeNode<T>(data);
//                std::swap(node, newNode);
            }else if(data < node->getData()){
                BinaryTreeNode <T> *&leftSubNode = node->getLeftSubTree();
                _insertInternal(leftSubNode, data);
                rebalance();
            }else if(data > node->getData()){
                BinaryTreeNode <T> *&rightSubNode = node->getRightSubTree();
                _insertInternal(rightSubNode, data);
                rebalance();
            }else {
                return nullptr;
            }
            return node;
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
            rebalance();
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

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::rotateLL(BinaryTreeNode<T> *binaryTreeNode) {
            BinaryTreeNode<T>* parentNode;
            BinaryTreeNode<T>* currentNode;

            parentNode = binaryTreeNode;
            currentNode = binaryTreeNode->getLeftSubTree();

            parentNode->changeLeftSubTree(currentNode->getRightSubTree());
            currentNode->changeRightSubTree(parentNode);

            return currentNode;
        }

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::rotateRR(BinaryTreeNode<T> *binaryTreeNode) {
            BinaryTreeNode<T>* parentNode;
            BinaryTreeNode<T>* currentNode;

            parentNode = binaryTreeNode;
            currentNode = binaryTreeNode->getRightSubTree();

            parentNode->changeRightSubTree(currentNode->getLeftSubTree());
            currentNode->changeLeftSubTree(parentNode);
            return currentNode;
        }

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::rotateLR(BinaryTreeNode<T> *binaryTreeNode) {
            BinaryTreeNode<T>* parentNode;
            BinaryTreeNode<T>* currentNode;

            parentNode = binaryTreeNode;
            currentNode = binaryTreeNode->getLeftSubTree();

            parentNode->changeLeftSubTree(rotateRR(currentNode));
            return rotateLL(parentNode);
        }

        template<class T>
        BinaryTreeNode<T> *BinarySearchTree<T>::rotateRL(BinaryTreeNode<T> *binaryTreeNode) {
            BinaryTreeNode<T>* parentNode;
            BinaryTreeNode<T>* currentNode;

            parentNode = binaryTreeNode;
            currentNode = binaryTreeNode->getRightSubTree();

            parentNode->changeRightSubTree(rotateLL(currentNode));
            return rotateRR(parentNode);
        }

        template<class T>
        int BinarySearchTree<T>::getHeight(BinaryTreeNode<T> *binaryTreeNode) const{
            int leftHeight;
            int rightHeight;

            if(binaryTreeNode == nullptr){
                return 0;
            }

            leftHeight = getHeight(binaryTreeNode->getLeftSubTree());
            rightHeight = getHeight(binaryTreeNode->getRightSubTree());

            if(leftHeight > rightHeight){
                return leftHeight + 1;
            }else{
                return rightHeight + 1;
            }
        }

        template<class T>
        int BinarySearchTree<T>::getHeightDiff(BinaryTreeNode<T> *binaryTreeNode) const{
            int leftSubTreeHeight;
            int rightSubTreeHeight;

            if(binaryTreeNode == nullptr){
                return 0;
            }

            leftSubTreeHeight = getHeight(binaryTreeNode->getLeftSubTree());
            rightSubTreeHeight = getHeight(binaryTreeNode->getRightSubTree());

            return leftSubTreeHeight - rightSubTreeHeight;
        }

        template<class T>
        void BinarySearchTree<T>::rebalance() {
            int balanceFactor = getHeightDiff(root);

            if(balanceFactor > 1){
                if(getHeightDiff(root->getLeftSubTree()) > 0){
                    root = rotateLL(root);
                }else{
                    root = rotateLR(root);
                }
            }

            if(balanceFactor < -1){
                if(getHeightDiff(root->getRightSubTree()) < 0){
                    root = rotateRR(root);
                }else{
                    root = rotateRL(root);
                }
            }
        }

        template<class T>
        void BinarySearchTree<T>::showHierarchyTree() const {
            BinaryTreeNode<int>* currentLeftNode= root->getLeftSubTree();;
            BinaryTreeNode<int>* currentRightNode= root->getRightSubTree();;

            std::cout<<"루트 노드: "<<root->getData()<<std::endl;
            for (int i = 0; i < getHeight(root); ++i) {
                if(currentLeftNode != nullptr){
                    std::cout<<"왼쪽"<<i<<": "<<currentLeftNode->getData()<<", ";
                    currentLeftNode = currentLeftNode->getLeftSubTree();
                }

                if(currentRightNode != nullptr){
                    std::cout<<"오른쪽"<<i<<": "<<currentRightNode->getData()<<std::endl;
                    currentRightNode = currentRightNode->getRightSubTree();
                }
            }
        }


    }
}
#endif // FIRSTCPP_BINARYSEARCHTREE3 _H

