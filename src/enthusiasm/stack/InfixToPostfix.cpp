//
// Created by 홍준근 on 2023/03/23.
//
#include "enthusiasm/stack/InfixToPostfix.h"
#include "enthusiasm/stack/OperationPriority.h"
#include "enthusiasm/stack/ListBaseStack.h"
using namespace utils;
using namespace Collection;

ExpressionCalculator::ExpressionCalculator()
        : expression(""){
}
ExpressionCalculator::ExpressionCalculator(const std::string &expression)
:expression(expression) {
}

ExpressionCalculator::ExpressionCalculator(const utils::ExpressionCalculator &ref)
: expression(ref.expression) {
}

ExpressionCalculator::ExpressionCalculator(const utils::ExpressionCalculator &&ref)
: expression(ref.expression){
}

ExpressionCalculator &ExpressionCalculator::operator=(const utils::ExpressionCalculator &ref) {
    this->expression = ref.expression;
    return *this;
}
ExpressionCalculator::~ExpressionCalculator() {
    expression.clear();
}

int ExpressionCalculator::compareOperations(const char &op1, const char &op2) const {
    OperationPriority operationPriority1 = getOperationPriority(op1);
    OperationPriority operationPriority2 = getOperationPriority(op2);

    if(operationPriority1 > operationPriority2){
        return 1;
    }else if(operationPriority1 < operationPriority2){
        return -1;
    }else{
        return 0;
    }
}

std::string ExpressionCalculator::convertToRPNExp() const {
    ListBaseStack<char> operationStack = ListBaseStack<char>();
    std::string result = {};
    for (int i = 0; i < expression.size(); ++i) {
        if(isdigit(expression.at(i))){
            result += expression.at(i);
        }else{
            switch(expression.at(i)){
                case '(':
                    operationStack.push(expression.at(i));
                    break;
                case ')':
                    while(!operationStack.isEmpty()){
                        Result<char> popResult = operationStack.pop();
                        if(popResult.isError() || popResult.getData() == '('){
                            break;
                        }
                        result += popResult.getData();
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while(!operationStack.isEmpty()&& compareOperations(operationStack.seek().getData(), expression.at(i)) >= 0){
                        result += operationStack.pop().getData();
                    }
                    operationStack.push(expression.at(i));
                    break;
                default:
                    break;
            }
        }
    }
    while(!operationStack.isEmpty()){
        result += operationStack.pop().getData();
    }
    return result;
}

int ExpressionCalculator::evalRPNExp(std::string rpnExpr) const {
    ListBaseStack<int> stack = ListBaseStack<int>();
    std::string tempExpr = rpnExpr;
    for (int i = 0; i < tempExpr.size(); ++i) {
        if(isdigit(tempExpr.at(i))){
            stack.push(tempExpr.at(i)-'0');
        }else{
            const Result<int> &result1 = stack.pop();
            const Result<int> &result2 = stack.pop();
            switch(tempExpr.at(i)){
                case '+':
                    stack.push(result2.getData() + result1.getData());
                    break;
                case '-':
                    stack.push(result2.getData() - result1.getData());
                    break;
                case '*':
                    stack.push(result2.getData() * result1.getData());
                    break;
                case '/':
                    stack.push(result2.getData() / result1.getData());
                    break;
            }
        }
    }
    return stack.pop().getData();
}