#include "enthusiasm/tree/ExpressionTree.h"

using namespace Collection::Tree;

int main(){
    std::string expr = "12+7*";
    ExpressionTree* tree = new ExpressionTree(expr);
    std::cout<<"전위 표기법의 수식: ";
    tree->showPrefixTypeExp();
    std::cout<<std::endl;
    std::cout<<"중위 표기법의 수식: ";
    tree->showInfixTypeExp();
    std::cout<<std::endl;
    std::cout<<"후위 표기법의 수식: ";
    tree->showPostfixTypeExp();
    std::cout<<std::endl;
    return 0;
}


