#ifndef FIRSTCPP_PRIORITYQUEUE _H
#define FIRSTCPP_PRIORITYQUEUE _H

#include "enthusiasm/heap/UsefulHeap.h"

using namespace Collection::Heap;

namespace Collection{
    namespace Queue{
        template <class T>
        class PriorityQueue{
        private:
            ArrayBaseHeap<T> heap;
        public:
            explicit PriorityQueue(Priority (*priorityCompareBetween)(const T&, const T&));
            PriorityQueue(const PriorityQueue& ref);
            PriorityQueue(PriorityQueue&& ref) noexcept;
            PriorityQueue& operator=(const PriorityQueue& ref);
            PriorityQueue& operator=(PriorityQueue&& ref) noexcept;
            ~PriorityQueue() = default;
        public:
            bool isEmpty() const;

            void enqueue(const T& data);
            T dequeue();
        };

        template<class T>
        PriorityQueue<T>::PriorityQueue(Priority (*priorityCompareBetween)(const T&, const T&))
        : heap(ArrayBaseHeap<T>(priorityCompareBetween)){
        }

        template<class T>
        PriorityQueue<T>::PriorityQueue(const PriorityQueue &ref)
        : heap(ref.heap){
        }

        template<class T>
        PriorityQueue<T>::PriorityQueue(PriorityQueue &&ref) noexcept
        : heap(ref.heap){
        }

        template<class T>
        PriorityQueue<T> &PriorityQueue<T>::operator=(const PriorityQueue &ref) {
            heap = ref.heap;
            return *this;
        }

        template<class T>
        PriorityQueue<T> &PriorityQueue<T>::operator=(PriorityQueue &&ref) noexcept {
            heap = ref.heap;
            return *this;
        }

        template<class T>
        bool PriorityQueue<T>::isEmpty() const {
            return heap.isEmpty();
        }

        template<class T>
        void PriorityQueue<T>::enqueue(const T &data) {
            heap.insertElement(data);
        }

        template<class T>
        T PriorityQueue<T>::dequeue() {
            return heap.deleteElement();
        }

    }
}

#endif // FIRSTCPP_PRIORITYQUEUE _H

