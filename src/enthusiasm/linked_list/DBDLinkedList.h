//
// Created by 홍준근 on 2023/03/20.
//

#ifndef FIRSTCPP_DBDLinkEDLIST_H
#define FIRSTCPP_DBDLinkEDLIST_H

#include "enthusiasm/linked_list/Result.h"
#include "enthusiasm/linked_list/DBNode.h"

namespace Collection {
    template<class T>
    class DBDLinkedList {
    private:
        DBNode<T> *headNode;
        DBNode<T> *tailNode;
        DBNode<T> *currentNode;
        int counts;

    public:
        DBDLinkedList();

        DBDLinkedList(const DBDLinkedList &ref);

        DBDLinkedList(DBDLinkedList &&ref);

        DBDLinkedList &operator=(const DBDLinkedList &ref);

        ~DBDLinkedList();

        void insert(const T &data);

        void insertFront(const T &data);

        Result<T> first();

        Result<T> current() const;

        Result<T> next();

        Result<T> previous();

        bool isDone() const;

        Result<T> remove();

        int count() const;
    };

    template<class T>
    DBDLinkedList<T>::DBDLinkedList()
            : counts(0) {
        headNode = new DBNode<T>(T(), nullptr, nullptr);
        tailNode = new DBNode<T>(T(), headNode, nullptr);
        *headNode = DBNode<T>(T(), nullptr, tailNode);
        currentNode = headNode;
    }

    template<class T>
    DBDLinkedList<T>::DBDLinkedList(const DBDLinkedList<T> &ref)
            : currentNode(ref.currentNode)
              , tailNode(ref.tailNode)
              , headNode(ref.headNode)
              , counts(ref.counts) {
    }

    template<class T>
    DBDLinkedList<T>::DBDLinkedList(DBDLinkedList<T> &&ref) {
        headNode = ref.headNode;
        tailNode = ref.tailNode;
        currentNode = ref.currentNode;
        counts = ref.counts;
    }

    template<class T>
    DBDLinkedList<T> &DBDLinkedList<T>::operator=(const DBDLinkedList<T> &ref) {
        headNode = ref.headNode;
        tailNode = ref.tailNode;
        currentNode = ref.currentNode;
        counts = ref.counts;
        return *this;
    }

    template<class T>
    DBDLinkedList<T>::~DBDLinkedList() {
    }

    template<class T>
    void DBDLinkedList<T>::insert(const T &data) {
        DBNode<T> *newNode;
        if (tailNode->getPrevious() != headNode) {
            newNode = new DBNode<T>(data, tailNode->getPrevious(), tailNode);
            *tailNode->getPrevious() = DBNode<T>(tailNode->getPrevious()->getData(), tailNode->getPrevious()->getPrevious(), newNode);
        }else{
            newNode = new DBNode<T>(data, headNode, tailNode);
            *headNode = DBNode<T>(headNode->getData(), headNode->getPrevious(), newNode);
        }
        *tailNode = DBNode<T>(tailNode->getData(), newNode, tailNode->getNext());
        ++counts;
    }

    template<class T>
    void DBDLinkedList<T>::insertFront(const T &data) {
        DBNode<T> *newNode;
        if (headNode->getNext() != tailNode) {
            newNode = new DBNode<T>(data, headNode, headNode->getNext());
        }else{
            newNode = new DBNode<T>(data, headNode, tailNode);
            *tailNode = DBNode<T>(tailNode->getData(), newNode, tailNode->getNext());
        }
        *headNode = DBNode<T>(headNode->getData(), headNode->getPrevious(), newNode);

        ++counts;
    }

    template<class T>
    Result<T> DBDLinkedList<T>::first() {
        if (headNode == nullptr) {
            return Result<T>(T(), true);
        }
        currentNode = headNode->getNext(); // head의 next로 초기화 함으로 첫 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template<class T>
    Result<T> DBDLinkedList<T>::current() const {
        return Result<T>(currentNode->getData(), false);
    }

    template<class T>
    Result<T> DBDLinkedList<T>::previous() {
        if (currentNode->getPrevious() == headNode || currentNode->getPrevious() == nullptr) {
            return Result<T>(T(), true);
        }
        currentNode = currentNode->getPrevious(); // currentNode의 next으로 초기화 함으로 다음 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template<class T>
    Result<T> DBDLinkedList<T>::next() {
        if (currentNode->getNext() == tailNode) {
            return Result<T>(T(), true);
        }
        currentNode = currentNode->getNext(); // currentNode의 next으로 초기화 함으로 다음 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template<class T>
    Result<T> DBDLinkedList<T>::remove() {
        DBNode<T> *tempNode = currentNode;
        Result<T> result = Result<T>(currentNode->getData(), false);
        *currentNode->getPrevious() = DBNode<T>(currentNode->getPrevious()->getData(), currentNode->getPrevious()->getPrevious(),currentNode->getNext());
        *currentNode->getNext() = DBNode<T>(currentNode->getNext()->getData(), currentNode->getPrevious(),currentNode->getNext()->getNext());
        currentNode = currentNode->getPrevious();
        delete tempNode;

        --counts;
        return result;
    }

    template<class T>
    int DBDLinkedList<T>::count() const {
        return counts;
    }

}
#endif //FIRSTCPP_DBDLinkEDLIST_H
