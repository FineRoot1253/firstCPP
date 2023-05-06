#include "enthusiasm/sorting/RadixSort.h"
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
    int array[7] = {13, 212, 14, 7141, 10987, 6, 15};
    int length = sizeof(array) / sizeof(int);

    radixLSDSort<int>(array, length, 5, compare);

    for (int i = 0; i < length; ++i) {
        std::cout<<array[i]<<" ";
    }
    return 0;
}


