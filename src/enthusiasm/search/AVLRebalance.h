#ifndef FIRSTCPP_AVLREBALANCE _H
#define FIRSTCPP_AVLREBALANCE _H
#include "enthusiasm/tree/BinaryTree3.h"

namespace Collection{
    namespace Tree{
        template <class T>
        class AVLRebalance{
        protected:
            virtual BinaryTreeNode<T>* rotateLL(BinaryTreeNode<T>* binaryTreeNode) = 0;
            virtual BinaryTreeNode<T>* rotateRR(BinaryTreeNode<T>* binaryTreeNode) = 0;
            virtual BinaryTreeNode<T>* rotateLR(BinaryTreeNode<T>* binaryTreeNode) = 0;
            virtual BinaryTreeNode<T>* rotateRL(BinaryTreeNode<T>* binaryTreeNode) = 0;
            virtual int getHeight(BinaryTreeNode<T>* binaryTreeNode) const = 0;
            virtual int getHeightDiff(BinaryTreeNode<T>* binaryTreeNode) const = 0;
        public:
            virtual void rebalance() = 0;
        };
    }
}

#endif // FIRSTCPP_AVLREBALANCE _H

