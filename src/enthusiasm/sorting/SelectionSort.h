#ifndef FIRSTCPP_SELECTIONSORT _H
#define FIRSTCPP_SELECTIONSORT _H

#include <iostream>

namespace Collection{
    enum class Priority : int {
        LEFT_GT = 0,
        RIGHT_GT,
        EQUAL
    };
    namespace SortSolution{
        template <class T>
        void selectionSort(T* array, const int& length,  Priority (*compare)(const T& leftData, const T& rightData)){
            int minIndex = 0;
            for (int i = 0; i < length - 1; ++i) {
                minIndex = i;
                for (int j = i+1; j < length; ++j) {
                    if(compare(array[j],array[minIndex])==Priority::RIGHT_GT){
                        minIndex = j;
                    }
                }
                std::swap(array[i], array[minIndex]);
            }
        }
    }
}
#endif // FIRSTCPP_SELECTIONSORT _H

