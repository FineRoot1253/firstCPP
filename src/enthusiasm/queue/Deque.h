#ifndef FIRSTCPP_DEQUE _H
#define FIRSTCPP_DEQUE _H

#include <iostream>
#include "enthusiasm/linked_list/DBDLinkedList.h"

namespace Collection{
    namespace Queue{
        template <class T>
        class Deque{
        private:
            DBNode<T> *head;
            DBNode<T> *tail;

        public:
            Deque();
            Deque(const Deque& ref);
            Deque(const Deque&& ref);
            Deque& operator=(const Deque& ref);
            ~Deque();

        public:
            bool isEmpty();
            void addFirst(const T& data);
            void addLast(const T& data);
            T removeFirst();
            T removeLast();
            T getFirst() const;
            T getLast() const;
        };

        template <class T>
        Deque<T>::Deque() 
        : head(nullptr)
        , tail(nullptr){
        }

        template <class T>
        Deque<T>::Deque(const Deque<T> &ref)
        : head(ref.head)
        , tail(ref.tail){
        }

        template <class T>
        Deque<T>::Deque(const Deque<T> &&ref) {
            this->head = ref.head;
            this->tail = ref.tail;
        }

        template <class T>
        Deque<T> &Deque<T>::operator=(const Deque<T> &ref){
            this->head = ref.head;
            this->tail = ref.tail;
            return *this;
        }

        template <class T>
        Deque<T>::~Deque() {}

        template <class T>
        bool Deque<T>::isEmpty() {
            return head == nullptr;
        }

        template <class T>
        void Deque<T>::addFirst(const T& data) {
            DBNode <T> *newNode = new DBNode<T>(data, nullptr, head);
            if(isEmpty()){
                tail = newNode;
            }else{
                *head = DBNode<T>(head->getData(), newNode, head->getNext());
            }
            head = newNode;
        }

        template <class T>
        void Deque<T>::addLast(const T& data) {
            DBNode <T> *newNode = new DBNode<T>(data, tail, nullptr);
            if(isEmpty()){
                head = newNode;
            }else{
                *tail = DBNode<T>(tail->getData(), tail->getPrevious(),newNode);
            }
            tail = newNode;
        }

        template <class T>
        T Deque<T>::removeFirst() {
            DBNode <T> *temp = head;
            if(isEmpty()){
                std::cout<<"Deque Memory Error!"<<std::endl;
                exit(-1);
            }
            T result = head->getData();
            head = head->getNext();
            delete temp;
            
            if(head == nullptr){
                tail = nullptr;
            }else{
                *head = DBNode<T>(head->getData(), nullptr, head->getNext());
            }
            
            return result;
        }

        template <class T>
        T Deque<T>::removeLast() {
            DBNode <T> *temp = tail;
            if(isEmpty()){
                std::cout<<"Deque Memory Error!"<<std::endl;
                exit(-1);
            }
            T result = tail->getData();
            tail = tail->getPrevious();
            delete temp;

            if(tail == nullptr){
                head = nullptr;
            }else{
                *tail = DBNode<T>(tail->getData(), tail->getPrevious(), nullptr);
            }

            return result;
        }

        template <class T>
        T Deque<T>::getFirst() const {
            if(isEmpty()){
                std::cout<<"Deque Memory Error!"<<std::endl;
                exit(-1);
            }
            return head->getData();
        }

        template <class T>
        T Deque<T>::getLast() const {
            if(isEmpty()){
                std::cout<<"Deque Memory Error!"<<std::endl;
                exit(-1);
            }
            return tail->getData();
        }

    }
}

#endif // FIRSTCPP_DEQUE _H

