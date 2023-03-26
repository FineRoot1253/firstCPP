//
// Created by 홍준근 on 2023/03/23.
//

#ifndef FIRSTCPP_OPERATIONPRIORITY_H
#define FIRSTCPP_OPERATIONPRIORITY_H
enum class OperationPriority : int{
    First = 3,
    Second = 2,
    Third =1,
    Other = -1
};

namespace utils{
    OperationPriority getOperationPriority(const char& op){
        switch(op){
            case '*':
            case '/':
                return OperationPriority::First;
            case '+':
            case '-':
                return OperationPriority::Second;
            case '(':
                return OperationPriority::Third;
            default:
                return OperationPriority::Other;
        }
    }
}
#endif //FIRSTCPP_OPERATIONPRIORITY_H
