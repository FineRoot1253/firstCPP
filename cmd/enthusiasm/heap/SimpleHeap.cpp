#include "enthusiasm/heap/SimpleHeap.h"

using namespace Collection::Heap;

int main(){
    ArrayBaseHeap<char> heap = ArrayBaseHeap<char>();

    heap.insertElement('A', 1);
    heap.insertElement('B', 2);
    heap.insertElement('C', 3);
    std::cout<<heap.deleteElement()<<" "<<std::endl;

    heap.insertElement('A', 1);
    heap.insertElement('B', 2);
    heap.insertElement('C', 3);
    std::cout<<heap.deleteElement()<<" "<<std::endl;

    for (; !heap.isEmpty() ;) {
        std::cout<<heap.deleteElement()<<" "<<std::endl;
    }
    return 0;
}


