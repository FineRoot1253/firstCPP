#ifndef FIRSTCPP_RADIXSORT _H
#define FIRSTCPP_RADIXSORT _H
#include <iostream>
#include "enthusiasm/queue/ListBaseQueue.h"

#define BUCKET_SIZE 10

using namespace Collection::Queue;

namespace Collection{
    enum class Priority : int {
        LEFT_GT = 0,
        RIGHT_GT,
        EQUAL
    };
    namespace SortSolution{
        template <class T>
        void radixLSDSort(T* array, const int& counts, const int& maxLength,  Priority (*compare)(const T& leftData, const T& rightData)){
            ListBaseQueue<T> buckets[BUCKET_SIZE];
            int divideFactor = 1;
            int radix;

            // init
            for (int i = 0; i < BUCKET_SIZE; ++i) {
                buckets[i] = ListBaseQueue<T>();
            }

            for(int i = 0; i < maxLength ; ++i){
                // insert from radix calculate result
                for (int j = 0; j < counts; ++j) {
                    radix = (array[j] / divideFactor) % 10;
                    buckets[radix].enqueue(array[j]);
                }

                // move from result of insert
                for (int k = 0, l = 0; k < BUCKET_SIZE; ++k) {
                    while(!buckets[k].isEmpty()){
                        array[l++] = buckets[k].dequeue();
                    }
                }
                divideFactor *= 10;
            }
        }
    }
}
#endif // FIRSTCPP_RADIXSORT _H

