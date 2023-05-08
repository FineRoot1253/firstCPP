#include "enthusiasm/sorting/SelectionSort.h"

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
    int array[4] = {3, 2, 4, 1};

    selectionSort<int>(array, 4, compare);

    for (int i = 0; i < 4; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


