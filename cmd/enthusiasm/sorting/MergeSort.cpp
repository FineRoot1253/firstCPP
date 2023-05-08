#include "enthusiasm/sorting/MergeSort.h"
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
    int array[9] = {3, 2, 4, 1, 7, 6, 5, 9, 8};

    mergeSort<int>(array,0, sizeof(array)/sizeof(int)-1, compare);

    for (int i = 0; i < 9; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


