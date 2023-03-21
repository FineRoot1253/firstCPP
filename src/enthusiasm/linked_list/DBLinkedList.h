//
// Created by 홍준근 on 2023/03/20.
//

#ifndef FIRSTCPP_DBLINKEDLIST_H
#define FIRSTCPP_DBLINKEDLIST_H
#include "enthusiasm/linked_list/Result.h"
#include "enthusiasm/linked_list/DBNode.h"

namespace Collection{
    template<class T>
    class DBLinkedList {
    private:
        DBNode<T> *headNode;
        DBNode<T> *currentNode;
        int counts;

    public:
        DBLinkedList();

        DBLinkedList(const DBLinkedList &ref);

        DBLinkedList(DBLinkedList &&ref);

        DBLinkedList &operator=(const DBLinkedList &ref);

        ~DBLinkedList();

        void insert(const T &data);

        Result<T> first();

        Result<T> current() const;

        Result<T> next();
        Result<T> previous();

        Result<T> remove();

        int count() const;
    };

    template <class T>
    DBLinkedList<T>::DBLinkedList()
            : currentNode(nullptr)
              , headNode(nullptr)
              , counts(0) {
    }

    template <class T>
    DBLinkedList<T>::DBLinkedList(const DBLinkedList<T> &ref)
            : headNode(ref.headNode)
              , currentNode(ref.currentNode)
              , counts(ref.counts) {
    }

    template <class T>
    DBLinkedList<T>::DBLinkedList(DBLinkedList<T> &&ref) {
        headNode = ref.headNode;
        currentNode = ref.currentNode;
        counts = ref.counts;
    }

    template <class T>
    DBLinkedList<T> &DBLinkedList<T>::operator=(const DBLinkedList<T> &ref) {
        headNode = ref.headNode;
        currentNode = ref.currentNode;
        counts = ref.counts;
        return *this;
    }

    template <class T>
    DBLinkedList<T>::~DBLinkedList() {
    }

    template <class T>
    void DBLinkedList<T>::insert(const T &data) {
        DBNode<T> *newNode;
        newNode = new DBNode<T>(data, nullptr, headNode);
        if(headNode != nullptr){
            *headNode = DBNode<T>(headNode->getData(), newNode, headNode->getNext());
        }
        headNode = newNode;
        ++counts;
    }

    template <class T>
    Result<T> DBLinkedList<T>::first() {
        if (headNode == nullptr) {
            return Result<T>(T(), true);
        }
        currentNode = headNode; // head로 초기화 함으로 첫 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> DBLinkedList<T>::current() const {
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> DBLinkedList<T>::previous() {
        if (currentNode->getPrevious()== nullptr) {
            return Result<T>(T(), true);
        }
        currentNode = currentNode->getPrevious(); // currentNode의 next으로 초기화 함으로 다음 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> DBLinkedList<T>::next() {
        if (currentNode->getNext()== nullptr) {
            return Result<T>(T(), true);
        }
        currentNode = currentNode->getNext(); // currentNode의 next으로 초기화 함으로 다음 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> DBLinkedList<T>::remove() {
        DBNode<T> *tempNode = currentNode;
        Result<T> result = Result<T>(currentNode->getData(), false);
        if(currentNode == headNode){
            if(headNode == headNode->getNext()){
                headNode = nullptr;
            }else{
                headNode = currentNode->getNext(); // headNode를 앞으로 당긴다.
                currentNode = currentNode->getNext(); // currentNode의 앞의 값으로 커서를 옮긴다.
            }
        }else{
            *currentNode->getPrevious() = DBNode<T>(currentNode->getPrevious()->getData(), currentNode->getPrevious()->getPrevious(), currentNode->getNext());
            currentNode = currentNode->getPrevious(); // currentNode의 이전으로 값을 바꾼다.
        }
        delete tempNode;
        --counts;
        return result;
    }

    template <class T>
    int DBLinkedList<T>::count() const {
        return counts;
    }

}
#endif //FIRSTCPP_DBLINKEDLIST_H
