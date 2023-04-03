#ifndef FIRSTCPP_CIRCULARQUEUE _H
#define FIRSTCPP_CIRCULARQUEUE _H

#include <iostream>

#define CIRCULAR_QUEUE_LENGTH 100

namespace Collection {
    namespace Queue{
        template <class T>
        class CircularQueue{
        private:
            T array[CIRCULAR_QUEUE_LENGTH];
            int front;
            int rear;

        private:
            int nextPositionIndex(int pos);

        public:
            CircularQueue();
            CircularQueue(const CircularQueue& ref);
            CircularQueue(const CircularQueue&& ref);
            CircularQueue& operator=(const CircularQueue& ref);
            ~CircularQueue();

        public:
            bool isEmpty();
            void enqueue(const T& data);
            T dequeue();
            T peek() const ;
        };

        template <class T>
        CircularQueue<T>::CircularQueue()
        : front(0)
        , rear(0){
        }

        template <class T>
        CircularQueue<T>::CircularQueue(const CircularQueue<T> &ref)
        : front(ref.front)
        , rear(ref.rear){
            for (int i = ref.front; i < ref.rear; ++i) {
                this->array[i] = ref.array[i];
            }
        }

        template <class T>
        CircularQueue<T>::CircularQueue(const CircularQueue<T> &&ref){
            this->front = ref.front;
            this->rear = ref.rear;
            for (int i = ref.front; i < ref.rear; ++i) {
                this->array[i] = ref.array[i];
            }
        }

        template <class T>
        CircularQueue<T> &CircularQueue<T>::operator=(const CircularQueue<T> &ref) {
            this->front = ref.front;
            this->rear = ref.rear;
            for (int i = ref.front; i < ref.rear; ++i) {
                this->array[i] = ref.array[i];
            }
            return *this;
        }

        template <class T>
        CircularQueue<T>::~CircularQueue() {
        }

        template <class T>
        int CircularQueue<T>::nextPositionIndex(int pos) {
            if(pos == CIRCULAR_QUEUE_LENGTH - 1){
                return 0;
            }
            return pos + 1;
        }

        template <class T>
        bool CircularQueue<T>::isEmpty() {
            return front == rear;
        }

        template <class T>
        void CircularQueue<T>::enqueue(const T& data) {
            if(nextPositionIndex(rear) == this->front){
                std::cout<<"Queue Memory Error"<<std::endl;
                exit(-1);
            }

            rear = nextPositionIndex(rear);
            array[rear] = data;
        }

        template <class T>
        T CircularQueue<T>::dequeue() {
            if(isEmpty()){
                std::cout<<"Queue Memory Error"<<std::endl;
                exit(-1);
            }
            front = nextPositionIndex(front);
            return array[front];
        }

        template <class T>
        T CircularQueue<T>::peek() const {
            if(isEmpty()){
                std::cout<<"Queue Memory Error"<<std::endl;
                exit(-1);
            }
            return array[nextPositionIndex(front)];
        }
    }
}


#endif // FIRSTCPP_CIRCULARQUEUE _H

