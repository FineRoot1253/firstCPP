//
// Created by 홍준근 on 2023/03/18.
//

#ifndef FIRSTCPP_DLINKEDLIST_H
#define FIRSTCPP_DLINKEDLIST_H

#include "enthusiasm/linked_list/Result.h"
#include <memory>

namespace Collection {
    template <class T>
    class Node {
    private:
        T data;
        Node *next;
    public:
        Node()
                : data(T()), next(nullptr) {};

        Node(T data, Node *next)
                : data(data), next(next) {};

        Node(const Node &ref)
                : data(ref.data)
                  , next(ref.next) {
        }

        Node &operator=(const Node &ref) {
            data = ref.data;
            next = ref.next;
            return *this;
        }

        T getData() const;

        Node *getNext() const;

//        void setNext(Node* next){
//            this->next = next;
//        }
    };

    template<class T>
    T Node<T>::getData() const {
        return data;
    }

    template<class T>
    Node<T> *Node<T>::getNext() const {
        return next;
    }

    template<class T>
    class DLinkedList {
    private:
        Node<T> *headNode;
        Node<T> *currentNode;
        Node<T> *beforeNode;
        int counts;

        bool (*comp)(T data1, T data2);

    private:
        void firstInsert(const T &data);

        void sortInsert(const T &data);

    public:
        DLinkedList();

        DLinkedList(const DLinkedList &ref);

        DLinkedList(DLinkedList &&ref);

        DLinkedList &operator=(const DLinkedList &ref);

        ~DLinkedList();

        void insert(const T &data);

        Result<T> first();

        Result<T> current() const;

        Result<T> next();

        bool isDone() const;

        Result<T> remove();

        int count() const;

        void setSortRule(bool (*comp)(T d1, T d2));
    };

    template <class T>
    DLinkedList<T>::DLinkedList()
            : currentNode(nullptr)
              , beforeNode(nullptr)
              , counts(0)
              , comp(nullptr) {
        // add dummy Node
        headNode = new Node<T>(T(), nullptr);
    }

    template <class T>
    DLinkedList<T>::DLinkedList(const DLinkedList<T> &ref)
            : headNode(ref.headNode)
              , currentNode(ref.currentNode)
              , beforeNode(ref.beforeNode)
              , counts(ref.counts)
              , comp(ref.comp) {
    }

    template <class T>
    DLinkedList<T>::DLinkedList(DLinkedList<T> &&ref) {
        headNode = ref.headNode;
        currentNode = ref.currentNode;
        beforeNode = ref.beforeNode;
        counts = ref.counts;
        comp = ref.comp;
    }

    template <class T>
    DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &ref) {
        headNode = ref.headNode;
        currentNode = ref.currentNode;
        beforeNode = ref.beforeNode;
        counts = ref.counts;
        comp = ref.comp;
        return *this;
    }

    template <class T>
    DLinkedList<T>::~DLinkedList() {
        delete headNode;
        delete currentNode;
        delete beforeNode;
    }

    template <class T>
    void DLinkedList<T>::firstInsert(const T &data) {
        // headNode 더미 초기화 덕분에 if 연산을 없앨 수 있다. nullptr인지 아닌지 검사를 해야만 했었다.
        Node<T> *tempNode = headNode;
        Node<T> *newNode = new Node<T>(data, headNode->getNext());
        headNode = new Node<T>(headNode->getData(), newNode);
        delete tempNode;
        ++counts;
    }

    template <class T>
    void DLinkedList<T>::sortInsert(const T &data) {
        Node<T>* newNode;

        for (this->first(); !this->isDone()&&this->currentNode->getNext()!= nullptr; this->next()) {
            if(!comp(data, this->currentNode->getNext()->getData())) {
                break;
            }
        }
        if(this->currentNode == nullptr){
            newNode = new Node<T>(data, nullptr);
            *headNode = Node<T>(headNode->getData(), newNode);
        }else{
            newNode = new Node<T>(data, this->currentNode->getNext());
            *this->currentNode = Node<T>(this->currentNode->getData(), newNode);
        }
        ++counts;
    }

    template <class T>
    void DLinkedList<T>::insert(const T &data) {
        if (comp != nullptr) {
            sortInsert(data);
        } else {
            firstInsert(data);
        }
    }

    template <class T>
    Result<T> DLinkedList<T>::first() {
        if (headNode->getNext() == nullptr) {
            return Result<T>(T(), true);
        }
        beforeNode = headNode; // before를 head로 초기화
        currentNode = headNode->getNext(); // head의 next으로 초기화 함으로 첫 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> DLinkedList<T>::current() const {
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> DLinkedList<T>::next() {
        if (currentNode->getNext() == nullptr) {
            beforeNode = nullptr;
            return Result<T>(T(), true);
        }
        beforeNode = currentNode; // before를 currentNode로 초기화
        currentNode = currentNode->getNext(); // currentNode의 next으로 초기화 함으로 다음 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    bool DLinkedList<T>::isDone() const {
        return beforeNode == nullptr;
    }

    template <class T>
    Result<T> DLinkedList<T>::remove() {
        Node<T> *tempNode1 = currentNode;
        Node<T> *tempNode2 = beforeNode;
        Result<T> result = Result<T>(currentNode->getData(), false);
        beforeNode = new Node<T>(beforeNode->getData(), currentNode->getNext());
        currentNode = beforeNode;
        delete tempNode1;
        delete tempNode2;
        --counts;
        return result;
    }

    template <class T>
    int DLinkedList<T>::count() const {
        return counts;
    }

    template <class T>
    void DLinkedList<T>::setSortRule(bool (*comp)(T, T)) {
        this->comp = comp;
    }
    template <class T>
    bool whichIsPrecede(T d1, T d2){
        if(d1 < d2){
            return false;
        }
        return true;
    }

}




#endif //FIRSTCPP_DLINKEDLIST_H
