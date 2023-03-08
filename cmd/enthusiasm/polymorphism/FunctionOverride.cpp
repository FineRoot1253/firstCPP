#include "enthusiasm/polymorphism/FunctionOverride.h"

int main(){
    Third *third = new Third();
    Second *second = third;
    First *first = second;

    third->func();
    second->func();
    first->func();
    delete third;
    return 0;
}