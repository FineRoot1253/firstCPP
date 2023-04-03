#include "enthusiasm/queue/ListBaseQueue.h"

using namespace Collection::Queue;

int main(){
    ListBaseQueue<int> queue = ListBaseQueue<int>();

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


