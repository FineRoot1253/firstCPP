#include "enthusiasm/stack/InfixToPostfix.h"
#include <iostream>
using namespace utils;

int main(){
    std::string exp1 = "1+2*3";
    std::string exp2 = "(1+2)*3";
    std::string exp3 = "((1-2)+3)*(5-2)";

    const std::string &exp1Result = ExpressionCalculator(exp1).convertToRPNExp();
    const std::string &exp2Result = ExpressionCalculator(exp2).convertToRPNExp();
    const std::string &exp3Result = ExpressionCalculator(exp3).convertToRPNExp();

    std::cout<<exp1Result<<" "<<std::endl;
    std::cout<<exp2Result<<" "<<std::endl;
    std::cout<<exp3Result<<" "<<std::endl;



    return 0;
}


