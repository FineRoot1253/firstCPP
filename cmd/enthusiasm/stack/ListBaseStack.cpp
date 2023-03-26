#include "enthusiasm/stack/ListBaseStack.h"

using namespace Collection;

int main(){
    ListBaseStack<int> stack = ListBaseStack<int>();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    while(!stack.isEmpty()){
        std::cout<<stack.pop().getData()<<" ";
    }

    return 0;
}


