#include "enthusiasm/priority_queue/PriorityQueue.h"

using namespace Collection::Queue;

Priority priorityCompareBetween(const char& left, const char& right){
    if(left < right){
        return Priority::RIGHT_GT;
    }else if(left > right){
        return Priority::LEFT_GT;
    }else{
        return Priority::EQUAL;
    }
}

int main(){
    PriorityQueue<char> priorityQueue = PriorityQueue<char>(priorityCompareBetween);

    priorityQueue.enqueue('A');
    priorityQueue.enqueue('B');
    priorityQueue.enqueue('C');
    std::cout<<priorityQueue.dequeue()<<" "<<std::endl;

    priorityQueue.enqueue('A');
    priorityQueue.enqueue('B');
    priorityQueue.enqueue('C');
    std::cout<<priorityQueue.dequeue()<<" "<<std::endl;

    for (; !priorityQueue.isEmpty() ;) {
        std::cout<<priorityQueue.dequeue()<<" "<<std::endl;
    }
    return 0;
}


