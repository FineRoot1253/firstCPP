#ifndef FIRSTCPP_INSERTIONSORT _H
#define FIRSTCPP_INSERTIONSORT _H
#include <iostream>

namespace Collection{
    enum class Priority : int {
        LEFT_GT = 0,
        RIGHT_GT,
        EQUAL
    };
    namespace SortSolution{
        template <class T>
        void insertSort(T* array, const int& length,  Priority (*compare)(const T& leftData, const T& rightData)){
            T temp;
            for (int i = 1; i < length; ++i) {
                temp = array[i];
                for (int j = i - 1; j >= 0; --j) {
                    if(compare(array[j], temp)==Priority::LEFT_GT) {
                        std::swap(array[j], array[j + 1]);
                    }else{
                        array[j+1] = temp;
                        break;
                    }
                }
            }
        }
    }
}
#endif // FIRSTCPP_INSERTIONSORT _H

