//
// Created by 홍준근 on 2023/03/26.
//

#include "enthusiasm/stack/InfixToPostfix.h"
#include <iostream>

using namespace utils;

int main(){
    std::string exp1 = "1+2*3";
    std::string exp2 = "(1+2)*3";
    std::string exp3 = "((1-2)+3)*(5-2)";
    ExpressionCalculator expressionConvertor1 = ExpressionCalculator(exp1);
    ExpressionCalculator expressionConvertor2 = ExpressionCalculator(exp2);
    ExpressionCalculator expressionConvertor3 = ExpressionCalculator(exp3);

    const std::string &exp1Result = expressionConvertor1.convertToRPNExp();
    const std::string &exp2Result = expressionConvertor2.convertToRPNExp();
    const std::string &exp3Result = expressionConvertor3.convertToRPNExp();

    std::cout<<exp1Result<<" => "<<expressionConvertor1.evalRPNExp(exp1Result)<<std::endl;
    std::cout<<exp2Result<<" => "<<expressionConvertor1.evalRPNExp(exp2Result)<<std::endl;
    std::cout<<exp3Result<<" => "<<expressionConvertor1.evalRPNExp(exp3Result)<<std::endl;

    return 0;
}