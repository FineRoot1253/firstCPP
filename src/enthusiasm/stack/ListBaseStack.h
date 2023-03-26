#ifndef FIRSTCPP_LISTBASESTACK _H
#define FIRSTCPP_LISTBASESTACK _H
#include "enthusiasm/linked_list/Result.h"
#include "enthusiasm/linked_list/Node.h"

#include <iostream>
#include <memory>

namespace Collection {
    template<class T>
    class ListBaseStack {
    private:
        Node<T> *headNode;

    public:
        ListBaseStack();
        ListBaseStack(const ListBaseStack &ref);
        ListBaseStack(ListBaseStack &&ref);
        ListBaseStack &operator=(const ListBaseStack &ref);
        ~ListBaseStack();

    public:
        void push(const T &data);
        bool isEmpty() const;
        Result<T> pop();
        Result<T> seek() const;
    };

    template <class T>
    ListBaseStack<T>::ListBaseStack()
            : headNode(nullptr) {
    }

    template <class T>
    ListBaseStack<T>::ListBaseStack(const ListBaseStack<T> &ref)
            : headNode(ref.headNode) {
    }

    template <class T>
    ListBaseStack<T>::ListBaseStack(ListBaseStack<T> &&ref) {
        headNode = ref.headNode;
        ref.headNode = nullptr;
    }

    template <class T>
    ListBaseStack<T> &ListBaseStack<T>::operator=(const ListBaseStack<T> &ref) {
        headNode = ref.headNode;
        return *this;
    }

    template <class T>
    ListBaseStack<T>::~ListBaseStack() {
        delete headNode;
    }

    template <class T>
    void ListBaseStack<T>::push(const T &data) {
        headNode = new Node<T>(data, this->headNode);
    }

    template <class T>
    bool ListBaseStack<T>::isEmpty() const {
        return headNode == nullptr;
    }

    template <class T>
    Result<T> ListBaseStack<T>::pop() {
        if(isEmpty()){
            std::cout<<"Pop Memory Error!"<<std::endl;
            exit(1);
        }
        Node<T> *tempNode = headNode;
        Result<T> result = Result<T>(headNode->getData(), false);
        headNode = headNode->getNext();
        delete tempNode;
        return result;
    }

    template <class T>
    Result<T> ListBaseStack<T>::seek() const {
        if(isEmpty()){
            std::cout<<"Seek Memory Error!"<<std::endl;
            exit(1);
        }
        return Result<T>(headNode->getData(), false);
    }

}
#endif // FIRSTCPP_LISTBASESTACK _H

