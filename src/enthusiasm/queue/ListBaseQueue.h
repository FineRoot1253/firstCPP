#ifndef FIRSTCPP_LISTBASEQUEUE _H
#define FIRSTCPP_LISTBASEQUEUE _H

#include <iostream>

#include "enthusiasm/linked_list/Node.h"

namespace Collection {
    namespace Queue{
        template <class T>
        class ListBaseQueue{
        private:
            Node<T> *front;
            Node<T> *rear;

        public:
            ListBaseQueue();
            ListBaseQueue(const ListBaseQueue& ref);
            ListBaseQueue(const ListBaseQueue&& ref);
            ListBaseQueue& operator=(const ListBaseQueue& ref);
            ~ListBaseQueue();

        public:
            bool isEmpty();
            void enqueue(const T& data);
            T dequeue();
            T peek() const ;
        };

        template <class T>
        ListBaseQueue<T>::ListBaseQueue()
                : front(nullptr)
                  , rear(nullptr){
        }

        template <class T>
        ListBaseQueue<T>::ListBaseQueue(const ListBaseQueue<T> &ref)
                : front(ref.front)
                  , rear(ref.rear){
        }

        template <class T>
        ListBaseQueue<T>::ListBaseQueue(const ListBaseQueue<T> &&ref){
            this->front = ref.front;
            this->rear = ref.rear;
        }

        template <class T>
        ListBaseQueue<T> &ListBaseQueue<T>::operator=(const ListBaseQueue<T> &ref) {
            this->front = ref.front;
            this->rear = ref.rear;
            return *this;
        }

        template <class T>
        ListBaseQueue<T>::~ListBaseQueue() {
        }

        template <class T>
        bool ListBaseQueue<T>::isEmpty() {
            return front == nullptr;
        }

        template <class T>
        void ListBaseQueue<T>::enqueue(const T& data) {
            Node<T> *newNode =new Node<T>(data, nullptr);
            if(isEmpty()){
                front = newNode;
                rear = newNode;
            }else{
                *rear = Node<T>(rear->getData(), newNode);
                rear = newNode;
            }
        }
        

        template <class T>
        T ListBaseQueue<T>::dequeue() {
            if(isEmpty()){
                std::cout<<"Queue Memory Error"<<std::endl;
                exit(-1);
            }
            T result = front->getData();
            Node <T> *temp = front;
            front = front->getNext();

            delete temp;

            return result;
        }

        template <class T>
        T ListBaseQueue<T>::peek() const {
            if(isEmpty()){
                std::cout<<"Queue Memory Error"<<std::endl;
                exit(-1);
            }
            return front->getData();
        }
    }
}
#endif // FIRSTCPP_LISTBASEQUEUE _H

