//
// Created by 홍준근 on 2023/03/19.
//

#ifndef FIRSTCPP_CLINKEDLIST_H
#define FIRSTCPP_CLINKEDLIST_H
#include "enthusiasm/linked_list/Result.h"
#include "enthusiasm/linked_list/Node.h"

namespace Collection{
    template<class T>
    class CLinkedList {
    private:
        Node<T> *tailNode;
        Node<T> *currentNode;
        Node<T> *beforeNode;
        int counts;

    public:
        CLinkedList();

        CLinkedList(const CLinkedList &ref);

        CLinkedList(CLinkedList &&ref);

        CLinkedList &operator=(const CLinkedList &ref);

        ~CLinkedList();

        void insert(const T &data);
        void insertFront(const T &data);

        Result<T> first();

        Result<T> current() const;

        Result<T> next();

        Result<T> remove();

        int count() const;
    };

    template <class T>
    CLinkedList<T>::CLinkedList()
            : currentNode(nullptr)
              , beforeNode(nullptr)
              , tailNode(nullptr)
              , counts(0) {
    }

    template <class T>
    CLinkedList<T>::CLinkedList(const CLinkedList<T> &ref)
            : tailNode(ref.tailNode)
              , currentNode(ref.currentNode)
              , beforeNode(ref.beforeNode)
              , counts(ref.counts) {
    }

    template <class T>
    CLinkedList<T>::CLinkedList(CLinkedList<T> &&ref) {
        tailNode = ref.tailNode;
        currentNode = ref.currentNode;
        beforeNode = ref.beforeNode;
        counts = ref.counts;
    }

    template <class T>
    CLinkedList<T> &CLinkedList<T>::operator=(const CLinkedList<T> &ref) {
        tailNode = ref.tailNode;
        currentNode = ref.currentNode;
        beforeNode = ref.beforeNode;
        counts = ref.counts;
        return *this;
    }

    template <class T>
    CLinkedList<T>::~CLinkedList() {
//        delete tailNode;
//        delete currentNode;
//        delete beforeNode;
    }

    template <class T>
    void CLinkedList<T>::insert(const T &data) {
        Node<T> *newNode;
        if(tailNode == nullptr){
            newNode = new Node<T>(data, nullptr);
            *newNode = Node<T>(data, newNode);
            tailNode = newNode;
        }else{
            newNode = new Node<T>(data, tailNode->getNext());
            *tailNode = Node<T>(tailNode->getData(), newNode);
            tailNode = newNode;
        }
        ++counts;
    }

    template <class T>
    void CLinkedList<T>::insertFront(const T &data) {
        Node<T> *newNode;
        if(tailNode == nullptr){
            newNode = new Node<T>(data, nullptr);
            *newNode = Node<T>(data, newNode);
            tailNode = newNode;
        }else{
            newNode = new Node<T>(data, tailNode->getNext());
            *tailNode = Node<T>(tailNode->getData(), newNode);
        }
        ++counts;
    }

    template <class T>
    Result<T> CLinkedList<T>::first() {
        if (tailNode == nullptr) {
            return Result<T>(T(), true);
        }
        beforeNode = tailNode; // before를 head로 초기화
        currentNode = tailNode->getNext(); // head의 next으로 초기화 함으로 첫 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> CLinkedList<T>::current() const {
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> CLinkedList<T>::next() {
        if (tailNode== nullptr) {
            beforeNode = nullptr;
            return Result<T>(T(), true);
        }
        beforeNode = currentNode; // before를 currentNode로 초기화
        currentNode = currentNode->getNext(); // currentNode의 next으로 초기화 함으로 다음 노드를 담음
        return Result<T>(currentNode->getData(), false);
    }

    template <class T>
    Result<T> CLinkedList<T>::remove() {
        Node<T> *tempNode1 = currentNode;
        Result<T> result = Result<T>(currentNode->getData(), false);
        if(currentNode == tailNode){
            if(tailNode == tailNode->getNext()){
                tailNode = nullptr;
            }else{
                tailNode = beforeNode;
            }
        }
        *beforeNode = Node<T>(beforeNode->getData(), currentNode->getNext());
        currentNode = beforeNode;
        delete tempNode1;
        --counts;
        return result;
    }

    template <class T>
    int CLinkedList<T>::count() const {
        return counts;
    }

}
#endif //FIRSTCPP_CLINKEDLIST_H
