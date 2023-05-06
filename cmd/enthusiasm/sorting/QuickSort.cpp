#include "enthusiasm/sorting/QuickSort.h"
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
    int array[9] = {5, 1, 3, 7, 9, 2, 4, 6, 8};

    quickSort<int>(array,0, 8, compare);

    for (int i = 0; i < 9; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


