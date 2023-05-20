#ifndef FIRSTCPP_EXPRESSIONTREE _H
#define FIRSTCPP_EXPRESSIONTREE _H

#include "enthusiasm/stack/ListBaseStack.h"
#include "enthusiasm/tree/BinaryTree2.h"

namespace Collection{
    namespace Tree{

        class ExpressionTree{
        private:

            BinaryTreeNode<char>* treeNode;

        public:
            ExpressionTree(std::string expr);
            ExpressionTree(const ExpressionTree& ref);
            ExpressionTree(ExpressionTree&& ref);
            ExpressionTree& operator=(const ExpressionTree& ref);
            ~ExpressionTree();

        public:
            int evaluateExpTree(const BinaryTreeNode<char>* treeNode);
            void showPrefixTypeExp();
            void showInfixTypeExp();
            void showPostfixTypeExp();
        };

        ExpressionTree::ExpressionTree(std::string expr)
        : treeNode(nullptr){
            ListBaseStack<BinaryTreeNode<char>*> stack = ListBaseStack<BinaryTreeNode<char>*>();
            BinaryTreeNode<char>* tempTreeNode;
            for (int i = 0; i < expr.size(); ++i) {
                if(isdigit(expr.at(i))){
                    tempTreeNode = new BinaryTreeNode<char>(expr.at(i) - '0');
                }else{
                    tempTreeNode = new BinaryTreeNode<char>(expr.at(i));
                    tempTreeNode->makeRightSubTree(stack.pop().getData());
                    tempTreeNode->makeLeftSubTree(stack.pop().getData());
                }
                stack.push(tempTreeNode);
            }
            treeNode = stack.pop().getData();
        }

        ExpressionTree::ExpressionTree(const ExpressionTree &ref)
        : treeNode(ref.treeNode){
        }

        ExpressionTree::ExpressionTree(ExpressionTree &&ref) {
            treeNode = ref.treeNode;
            ref.treeNode = nullptr;
        }

        ExpressionTree &ExpressionTree::operator=(const ExpressionTree &ref) {
            treeNode = ref.treeNode;
            return *this;
        }

        ExpressionTree::~ExpressionTree() {
            delete treeNode;
        }

        int ExpressionTree::evaluateExpTree(const BinaryTreeNode<char>* treeNode) {
            // check isLeafNode?
            if(treeNode->getLeftSubTree() == nullptr && treeNode->getRightSubTree() == nullptr){
                return treeNode->getData();
            }

            int leftOp = evaluateExpTree(treeNode->getLeftSubTree());
            int rightOp = evaluateExpTree(treeNode->getRightSubTree());

            switch(treeNode->getData()){
                case '+':
                    return leftOp + rightOp;
                case '-':
                    return leftOp - rightOp;
                case '*':
                    return leftOp * rightOp;
                case '/':
                    return leftOp / rightOp;
            }

            return 0;
        }

        template <class T>
        void showDataWithCheck(const T& data){
            if(data >=0 && data <= 9) {
                printf("%d ", data);
            }else{
                std::cout<<data<<" ";
            }
        }

        void ExpressionTree::showPrefixTypeExp() {
            treeNode->changeTraversePolicy(TraversalPolicy::PREORDER);
            treeNode->traverse(showDataWithCheck);
        }

        void ExpressionTree::showInfixTypeExp() {
            treeNode->changeTraversePolicy(TraversalPolicy::INORDER);
            treeNode->traverse(showDataWithCheck);
        }

        void ExpressionTree::showPostfixTypeExp() {
            treeNode->changeTraversePolicy(TraversalPolicy::POSTORDER);
            treeNode->traverse(showDataWithCheck);
        }



    }
}
#endif // FIRSTCPP_EXPRESSIONTREE _H

