#ifndef FIRSTCPP_QUICKSORT _H
#define FIRSTCPP_QUICKSORT _H
#include <iostream>

namespace Collection{
    enum class Priority : int {
        LEFT_GT = 0,
        RIGHT_GT,
        EQUAL
    };
    namespace SortSolution{
        template <class T>
        int _split(T array[], const int& left, const int& right,  Priority (*compare)(const T& leftData, const T& rightData)){
            int pivotIndex = left;
            int lowIndex = left+1;
            int highIndex = right;

            for (;lowIndex <= highIndex;) {

                for (;(compare(array[pivotIndex], array[lowIndex])==Priority::LEFT_GT ||compare(array[pivotIndex], array[lowIndex])==Priority::EQUAL) && lowIndex <= right;) {
                    ++lowIndex;
                }
                for (;(compare(array[pivotIndex], array[highIndex]) == Priority::RIGHT_GT ||compare(array[pivotIndex], array[lowIndex])==Priority::EQUAL) && highIndex >= left+1;) {
                    --highIndex;
                }

                if(lowIndex <= highIndex){
                    std::swap(array[lowIndex], array[highIndex]);
                }
            }
            std::swap(array[left], array[highIndex]);
            return highIndex;
        }

        template <class T>
        void quickSort(T* array, const int& left, const int& right,  Priority (*compare)(const T& leftData, const T& rightData)){
            if(left <= right){
                int pivotIndex = _split(array, left, right, compare);

                quickSort(array,left, pivotIndex-1, compare);
                quickSort(array,pivotIndex + 1, right, compare);
            }
        }
    }
}
#endif // FIRSTCPP_QUICKSORT _H

