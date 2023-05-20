//
// Created by 홍준근 on 2023/03/20.
//

#ifndef FIRSTCPP_DBDBNode_H
#define FIRSTCPP_DBDBNode_H
namespace Collection {
    template<class T>
    class DBNode {
    private:
        T data;
        DBNode *previous;
        DBNode *next;
    public:
        DBNode()
        : data(T())
        , previous(nullptr)
        , next(nullptr) {};
        DBNode(T data,DBNode *previous, DBNode *next)
        : data(data)
        , previous(previous)
        , next(next) {};
        DBNode(const DBNode &ref)
        : data(ref.data)
        , previous(ref.previous)
        , next(ref.next) {
        }
        DBNode &operator=(const DBNode &ref) {
            data = ref.data;
            previous = ref.previous;
            next = ref.next;
            return *this;
        }

        T getData() const;
        DBNode * getPrevious() const;
        DBNode *getNext() const;
    };

    template<class T>
    T DBNode<T>::getData() const {
        return data;
    }

    template<class T>
    DBNode<T> *DBNode<T>::getPrevious() const {
        return previous;
    }

    template<class T>
    DBNode<T> *DBNode<T>::getNext() const {
        return next;
    }
}
#endif //FIRSTCPP_DBDBNode_H
