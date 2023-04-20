#ifndef FIRSTCPP_SIMPLEHEAP _H
#define FIRSTCPP_SIMPLEHEAP _H

#include <iostream>

#define HEAP_ARRAY_LENGTH 100
#define HEAP_PARENT_INDEX 1

namespace Collection{
    namespace Heap{



        template <class T>
        class ArrayBaseHeapElement{
        private:
            int priority;
            T data;

        public:
            ArrayBaseHeapElement();
            ArrayBaseHeapElement(const T& data, const int& priority);
            ArrayBaseHeapElement(const ArrayBaseHeapElement& ref);
            ArrayBaseHeapElement(ArrayBaseHeapElement&& ref);
            ArrayBaseHeapElement& operator=(const ArrayBaseHeapElement& ref);
            ~ArrayBaseHeapElement();

            int getPriority() const;
            T getData() const;

        };

        template<class T>
        ArrayBaseHeapElement<T>::ArrayBaseHeapElement()
        : priority(-1)
        , data(T()){
        }

        template <class T>
        ArrayBaseHeapElement<T>::ArrayBaseHeapElement(const T& data, const int& priority)
        : data(data)
        , priority(priority){
        }

        template <class T>
        ArrayBaseHeapElement<T>::ArrayBaseHeapElement(const ArrayBaseHeapElement &ref)
        : data(ref.data)
        , priority(ref.priority){
        }

        template <class T>
        ArrayBaseHeapElement<T>::ArrayBaseHeapElement(ArrayBaseHeapElement &&ref) {
            data = ref.data;
            priority = ref.priority;
        }

        template <class T>
        ArrayBaseHeapElement<T> &ArrayBaseHeapElement<T>::operator=(const ArrayBaseHeapElement &ref) {
            data = ref.data;
            priority = ref.priority;
            return *this;
        }

        template<class T>
        ArrayBaseHeapElement<T>::~ArrayBaseHeapElement() {
        }

        template<class T>
        int ArrayBaseHeapElement<T>::getPriority() const {
            return priority;
        }

        template<class T>
        T ArrayBaseHeapElement<T>::getData() const {
            return data;
        }


        template <class T>
        class ArrayBaseHeap{
        private:
            int counts;
            ArrayBaseHeapElement<T> array[HEAP_ARRAY_LENGTH];

        private:
            int getParentIndex(const int& index) const;
            int getLeftChildIndex(const int& index) const;
            int getRightChildIndex(const int& index) const;
            int getHigherPriorityChildIndex(const int &parentIndex) const;

        public:
            explicit ArrayBaseHeap();
            ArrayBaseHeap(const ArrayBaseHeap& ref);
            ArrayBaseHeap(ArrayBaseHeap&& ref) noexcept;
            ArrayBaseHeap<T>& operator=(const ArrayBaseHeap& ref);
            ArrayBaseHeap<T>&operator=(ArrayBaseHeap &&ref) noexcept;
            ~ArrayBaseHeap();

            bool isEmpty() const;

            void insertElement(const T& data, const int& priority);
            T deleteElement();
        };

        template<class T>
        ArrayBaseHeap<T>::ArrayBaseHeap()
        : counts(0)
        , array{}{
        }

        template<class T>
        ArrayBaseHeap<T>::ArrayBaseHeap(const ArrayBaseHeap &ref)
        : counts(ref.counts){
            for (int i = 0; i < ref.counts; ++i) {
                array[i] = ref.array[i];
            }
        }

        template<class T>
        ArrayBaseHeap<T>::ArrayBaseHeap(ArrayBaseHeap &&ref) noexcept{
            counts = ref.counts;
            for (int i = 0; i < ref.counts; ++i) {
                array[i] = std::move(ref.array[i]);
            }
        }

        template<class T>
        ArrayBaseHeap<T> &ArrayBaseHeap<T>::operator=(const ArrayBaseHeap &ref) {
            counts = ref.counts;
            for (int i = 0; i < ref.counts; ++i) {
                array[i] = ref.array[i];
            }
            return *this;
        }

        template<class T>
        ArrayBaseHeap<T> &ArrayBaseHeap<T>::operator=(ArrayBaseHeap &&ref) noexcept {
            counts = ref.counts;
            for (int i = 0; i < ref.counts; ++i) {
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
        void ArrayBaseHeap<T>::insertElement(const T& data, const int& priority) {
            int index = counts + 1;
            ArrayBaseHeapElement<T> element = ArrayBaseHeapElement<T>(data, priority);

            for (int i = counts+1; i != HEAP_PARENT_INDEX;) {
                if(priority < array[getParentIndex(i)].getPriority()){
                    array[i] = array[getParentIndex(i)];
                    i = getParentIndex(i);
                    index = i;
                }else{
                    break;
                }
            }
            array[index] = element;
            ++counts;
        }

        template<class T>
        T ArrayBaseHeap<T>::deleteElement() {
            int parentIndex = HEAP_PARENT_INDEX;
            ArrayBaseHeapElement<T> result = array[HEAP_PARENT_INDEX];

            for (int i = getHigherPriorityChildIndex(parentIndex); i != 0 && i <= counts; i = getHigherPriorityChildIndex(parentIndex)) {
                if(array[counts].getPriority() <= array[i].getPriority()){
                    break;
                } else {
                    array[parentIndex] = array[i];
                    parentIndex = i;
                }
            }

            array[parentIndex] = array[counts];
            --counts;

            return result.getData();
        }

        template<class T>
        int ArrayBaseHeap<T>::getParentIndex(const int& index) const{
            return index / 2;
        }

        template<class T>
        int ArrayBaseHeap<T>::getLeftChildIndex(const int& index) const{
            return index * 2;
        }

        template<class T>
        int ArrayBaseHeap<T>::getRightChildIndex(const int& index) const{
            return (index * 2) + 1;
        }

        template<class T>
        int ArrayBaseHeap<T>::getHigherPriorityChildIndex(const int &parentIndex) const {
            if(getLeftChildIndex(parentIndex) > counts){
                return 0;
            }else if(getLeftChildIndex(parentIndex) == counts){
                return getLeftChildIndex(parentIndex);
            }else{
                if(array[getLeftChildIndex(parentIndex)].getPriority() > array[getRightChildIndex(parentIndex)].getPriority()){
                    return getRightChildIndex(parentIndex);
                }else{
                    return getLeftChildIndex(parentIndex);   
                }
            }
        }
    }

}

#endif // FIRSTCPP_SIMPLEHEAP _H

