#ifndef FIRSTCPP_HEAPSORT _H
#define FIRSTCPP_HEAPSORT _H
#include <iostream>
#include "enthusiasm/heap/UsefulHeap.h"

using namespace Collection::Heap;

namespace Collection{
    namespace SortSolution{
        template <class T>
        void heapSort(T* array, const int& length,  Priority (*compare)(const T& leftData, const T& rightData)){
            ArrayBaseHeap<T> heap = ArrayBaseHeap<T>(compare);
            for (int i = 0; i < length; ++i) {
                heap.insertElement(array[i]);
            }
            for (int i = 0; i < length; ++i) {
                array[i] = heap.deleteElement();
            }
        }
    }
}
#endif // FIRSTCPP_HEAPSORT _H

