#include "enthusiasm/heap/UsefulHeap.h"

using namespace Collection::Heap;

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
    ArrayBaseHeap<char> heap = ArrayBaseHeap<char>(priorityCompareBetween);

    heap.insertElement('A');
    heap.insertElement('B');
    heap.insertElement('C');
    std::cout<<heap.deleteElement()<<" "<<std::endl;

    heap.insertElement('A');
    heap.insertElement('B');
    heap.insertElement('C');
    std::cout<<heap.deleteElement()<<" "<<std::endl;

    for (; !heap.isEmpty() ;) {
        std::cout<<heap.deleteElement()<<" "<<std::endl;
    }
    return 0;
}


