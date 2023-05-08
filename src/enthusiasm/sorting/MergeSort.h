#ifndef FIRSTCPP_MERGESORT _H
#define FIRSTCPP_MERGESORT _H

#include <iostream>

namespace Collection {
    enum class Priority : int {
        LEFT_GT = 0,
        RIGHT_GT,
        EQUAL
    };

    namespace SortSolution {
        template<class T>
        void _mergeTwoArea(T *array, const int &left, const int &mid, const int &right,
                           Priority (*compare)(const T &leftData, const T &rightData)) {
            int leftRangeIndex = left;
            int rightRangeIndex = mid + 1;

            T *tempArray = new T[right + 1];
            int index = left;

            for (; leftRangeIndex <= mid && rightRangeIndex <= right; ++index) {
                if (compare(array[leftRangeIndex], array[rightRangeIndex]) == Priority::RIGHT_GT ||
                    compare(array[leftRangeIndex], array[rightRangeIndex]) == Priority::EQUAL) {
                    tempArray[index] = array[leftRangeIndex++];
                } else {
                    tempArray[index] = array[rightRangeIndex++];
                }
            }

            if (leftRangeIndex > mid) {
                for (int i = rightRangeIndex; i <= right; ++i, ++index) {
                    tempArray[index] = array[i];
                }
            } else {
                for (int i = leftRangeIndex; i <= mid; ++i, ++index) {
                    tempArray[index] = array[i];
                }
            }
            for (int i = left; i <= right; ++i) {
                array[i] = tempArray[i];
            }

            delete tempArray;
        }

        template<class T>
        void mergeSort(T *array, const int &left, const int &right, Priority (*compare)(const T &leftData, const T &rightData)) {
            int mid;

            if (left < right) {
                mid = (left + right) / 2;
                mergeSort<T>(array, left, mid, compare);
                mergeSort<T>(array, mid + 1, right, compare);

                _mergeTwoArea<T>(array, left, mid, right, compare);
            }

        }
    }



}
#endif // FIRSTCPP_MERGESORT _H

