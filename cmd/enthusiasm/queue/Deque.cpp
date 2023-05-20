#include "enthusiasm/queue/Deque.h"

using namespace Collection::Queue;

int main(){
    Deque<int> deque = Deque<int>();

    deque.addFirst(3);
    deque.addFirst(2);
    deque.addFirst(1);

    deque.addLast(4);
    deque.addLast(5);
    deque.addLast(6);

    while(!deque.isEmpty()){
        std::cout<<deque.removeFirst()<<" ";
    }

    std::cout<<std::endl;

    deque.addFirst(3);
    deque.addFirst(2);
    deque.addFirst(1);

    deque.addLast(4);
    deque.addLast(5);
    deque.addLast(6);

    while(!deque.isEmpty()){
        std::cout<<deque.removeLast()<<" ";
    }
    return 0;
}


