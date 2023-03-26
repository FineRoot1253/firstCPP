#include "enthusiasm/stack/ArrayBaseStack.h"

using namespace Collection;
int main(){
    ArrayBaseStack<int> stack = ArrayBaseStack<int>(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    while(!stack.isEmpty()){
        std::cout<<stack.pop()<<" ";
    }

    return 0;
}


