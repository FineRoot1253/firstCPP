#ifndef FIRSTCPP_INFIXTOPOSTFIX _H
#define FIRSTCPP_INFIXTOPOSTFIX _H

#include <string>

namespace utils{
    class ExpressionCalculator{
    private:
        std::string expression;

    private:
        int compareOperations(const char& op1, const char& op2) const;

    public:
        ExpressionCalculator();
        ExpressionCalculator(const std::string& expression);
        ExpressionCalculator(const ExpressionCalculator& ref);
        ExpressionCalculator(const ExpressionCalculator&& ref);
        ExpressionCalculator& operator=(const ExpressionCalculator& ref);
        ~ExpressionCalculator();

    public:
        std::string convertToRPNExp() const;
        int evalRPNExp(std::string rpnExpr) const;
    };


}
#endif // FIRSTCPP_INFIXTOPOSTFIX _H

