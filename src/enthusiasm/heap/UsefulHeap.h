#ifndef FIRSTCPP_USEFULHEAP _H
#define FIRSTCPP_USEFULHEAP _H

#include <iostream>

#define HEAP_ARRAY_LENGTH 100
#define HEAP_PARENT_INDEX 1

namespace Collection {
    namespace Heap {

        enum class Priority : int {
            LEFT_GT = 0,
            RIGHT_GT,
            EQUAL
        };

        template<class T>
        class ArrayBaseHeap {
        private:
            int counts;
            T array[HEAP_ARRAY_LENGTH];
            Priority (*priorityCompareBetween)(const T &, const T &);

        private:
            int getParentIndex(const int &index) const;

            int getLeftChildIndex(const int &index) const;

            int getRightChildIndex(const int &index) const;

            int getHigherPriorityChildIndex(const int &parentIndex) const;

        public:
            explicit ArrayBaseHeap(Priority (*priorityCompareBetween)(const T &, const T &));

            ArrayBaseHeap(const ArrayBaseHeap &ref);

            ArrayBaseHeap(ArrayBaseHeap &&ref) noexcept;

            ArrayBaseHeap<T> &operator=(const ArrayBaseHeap &ref);

            ArrayBaseHeap<T> &operator=(ArrayBaseHeap &&ref) noexcept;

            ~ArrayBaseHeap();

            bool isEmpty() const;

            void insertElement(const T &data);

            T deleteElement();
        };

        template<class T>
        ArrayBaseHeap<T>::ArrayBaseHeap(Priority (*priorityCompareBetween)(const T &, const T &))
                : counts(0)
                  , array{}
                  , priorityCompareBetween(nullptr) {
                      this->priorityCompareBetween = priorityCompareBetween;
        }

        template<class T>
        ArrayBaseHeap<T>::ArrayBaseHeap(const ArrayBaseHeap &ref)
                : counts(ref.counts)
                  , priorityCompareBetween(ref.priorityCompareBetween) {
            for (int i = 0; i < ref.counts+1; ++i) {
                array[i] = ref.array[i];
            }
        }

        template<class T>
        ArrayBaseHeap<T>::ArrayBaseHeap(ArrayBaseHeap &&ref) noexcept {
            counts = ref.counts;
            priorityCompareBetween = ref.priorityCompareBetween;
            ref.priorityCompareBetween = nullptr;
            for (int i = 0; i < ref.counts+1; ++i) {
                array[i] = std::move(ref.array[i]);
            }
        }

        template<class T>
        ArrayBaseHeap<T> &ArrayBaseHeap<T>::operator=(const ArrayBaseHeap &ref) {
            counts = ref.counts;
            priorityCompareBetween = ref.priorityCompareBetween;
            for (int i = 0; i < ref.counts+1; ++i) {
                array[i] = ref.array[i];
            }
            return *this;
        }

        template<class T>
        ArrayBaseHeap<T> &ArrayBaseHeap<T>::operator=(ArrayBaseHeap &&ref) noexcept {
            counts = ref.counts;
            priorityCompareBetween = ref.priorityCompareBetween;
            ref.priorityCompareBetween = nullptr;
            for (int i = 0; i < ref.counts+1; ++i) {
                array[i] = ref.array[i];
            }
            return *this;
        }

        template<class T>
        ArrayBaseHeap<T>::~ArrayBaseHeap() {
        }

        template<class T>
        bool ArrayBaseHeap<T>::isEmpty() const {
            return counts <= 0;
        }

        template<class T>
        void ArrayBaseHeap<T>::insertElement(const T &data) {
            int index = counts + 1;
            for (int i = counts + 1; i != HEAP_PARENT_INDEX;) {
                if (priorityCompareBetween(data, array[getParentIndex(i)]) == Priority::RIGHT_GT) {
                    array[i] = array[getParentIndex(i)];
                    i = getParentIndex(i);
                    index = i;
                } else {
                    break;
                }
            }
            array[index] = data;
            ++counts;
        }

        template<class T>
        T ArrayBaseHeap<T>::deleteElement() {
            int parentIndex = HEAP_PARENT_INDEX;
            T result = array[HEAP_PARENT_INDEX];

            for (int i = getHigherPriorityChildIndex(parentIndex);
                 i != 0 && i <= counts; i = getHigherPriorityChildIndex(parentIndex)) {
                if (priorityCompareBetween(array[counts], array[i]) == Priority::RIGHT_GT ||
                    priorityCompareBetween(array[counts], array[i]) == Priority::EQUAL) {
                    break;
                } else {
                    array[parentIndex] = array[i];
                    parentIndex = i;
                }
            }

            array[parentIndex] = array[counts];
            --counts;

            return result;
        }

        template<class T>
        int ArrayBaseHeap<T>::getParentIndex(const int &index) const {
            return index / 2;
        }

        template<class T>
        int ArrayBaseHeap<T>::getLeftChildIndex(const int &index) const {
            return index * 2;
        }

        template<class T>
        int ArrayBaseHeap<T>::getRightChildIndex(const int &index) const {
            return (index * 2) + 1;
        }

        template<class T>
        int ArrayBaseHeap<T>::getHigherPriorityChildIndex(const int &parentIndex) const {
            if (getLeftChildIndex(parentIndex) > counts) {
                return 0;
            } else if (getLeftChildIndex(parentIndex) == counts) {
                return getLeftChildIndex(parentIndex);
            } else {
                if (priorityCompareBetween(array[getLeftChildIndex(parentIndex)],
                                           array[getRightChildIndex(parentIndex)]) ==
                    Priority::LEFT_GT) {
                    return getRightChildIndex(parentIndex);
                } else {
                    return getLeftChildIndex(parentIndex);
                }
            }
        }
    }

}
#endif // FIRSTCPP_USEFULHEAP _H

