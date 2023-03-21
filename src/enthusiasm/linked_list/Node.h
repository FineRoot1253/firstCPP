//
// Created by 홍준근 on 2023/03/19.
//

#ifndef FIRSTCPP_NODE_H
#define FIRSTCPP_NODE_H
namespace Collection {
    template<class T>
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

    };

    template<class T>
    T Node<T>::getData() const {
        return data;
    }

    template<class T>
    Node<T> *Node<T>::getNext() const {
        return next;
    }
}
#endif //FIRSTCPP_NODE_H
