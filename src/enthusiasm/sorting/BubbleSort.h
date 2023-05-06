#ifndef FIRSTCPP_BUBBLESORT _H
#define FIRSTCPP_BUBBLESORT _H

#include <algorithm>

namespace Collection{
    enum class Priority : int {
        LEFT_GT = 0,
        RIGHT_GT,
        EQUAL
    };
    namespace SortSolution{
        template <class T>
        void bubbleSort(T* array, T length,  Priority (*compare)(const T& leftData, const T& rightData)){
            for (int i = 0; i < length - 1; ++i) {
                for (int j = 0; j < (length - i) - 1; ++j) {
                    if(compare(array[j],array[j+1]) == Priority::LEFT_GT){
                        std::swap(array[j], array[j+1]);
                    }
                }
            }
        }
    }
}
#endif // FIRSTCPP_BUBBLESORT _H

