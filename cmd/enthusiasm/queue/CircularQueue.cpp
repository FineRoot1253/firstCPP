#include "enthusiasm/queue/CircularQueue.h"
using namespace Collection::Queue;

int main(){
    CircularQueue<int> queue = CircularQueue<int>();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    while(!queue.isEmpty()){
        std::cout<<queue.dequeue()<<" ";
    }

    return 0;
}


