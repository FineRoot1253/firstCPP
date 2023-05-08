#include "enthusiasm/sorting/HeapSort.h"
using namespace Collection;

using namespace Collection::SortSolution;

Priority compare(const int& left, const int& right){
    if(left > right){
        return Priority::LEFT_GT;
    }else if(left < right){
        return Priority::RIGHT_GT;
    }else {
        return Priority::EQUAL;
    }
}

int main(){
    int array[5] = {5, 3, 2, 4, 1};

    heapSort<int>(array, 5, compare);

    for (int i = 0; i < 5; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


