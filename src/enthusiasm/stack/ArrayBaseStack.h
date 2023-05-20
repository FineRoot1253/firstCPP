#ifndef FIRSTCPP_ARRAYBASESTACK _H
#define FIRSTCPP_ARRAYBASESTACK _H

#include <iostream>

namespace Collection{
    template <class T>
    class ArrayBaseStack{
    private:
        T *array;
        int topIndex;
        int length;
        int capacity;

    private:
        bool ensureIncrease(const int& requireLength);
        void increaseCapacity(const int& requireLength);

    public:
        ArrayBaseStack();
        explicit ArrayBaseStack(const int& length);
        ArrayBaseStack(const ArrayBaseStack<T>& ref);
        ArrayBaseStack(ArrayBaseStack<T>&& ref) noexcept ;
        ArrayBaseStack& operator=(const ArrayBaseStack<T>& ref);
        ~ArrayBaseStack();

    public:
        bool isEmpty();
        void push(const T& data);
        T pop();
        T seek() const;
    };

    template <class T>
    ArrayBaseStack<T>::ArrayBaseStack()
    : topIndex(-1)
    , length(10)
    , capacity(0){
        array = new T[length];
    }

    template <class T>
    ArrayBaseStack<T>::ArrayBaseStack(const int &length)
    : topIndex(-1)
    , length(length)
    , capacity(0){
        array = new T[this->length];
    }

    template <class T>
    ArrayBaseStack<T>::ArrayBaseStack(const ArrayBaseStack<T> &ref)
    : topIndex(ref.topIndex)
    , length(ref.length)
    , capacity(ref.capacity){
        this->array = new T [ref.memLength];
        for (int i = 0; i < ref.currentCapacity; ++i) {
            this->array[i] = new T(ref.array[i]);
        }
    }

    template <class T>
    ArrayBaseStack<T>::ArrayBaseStack(ArrayBaseStack<T> &&ref) noexcept
    : topIndex(ref.topIndex)
    , length(ref.length)
    , capacity(ref.capacity)
    , array(ref.array) {
          ref.array = nullptr;
    }

    template <class T>
    ArrayBaseStack<T> &ArrayBaseStack<T>::operator=(const ArrayBaseStack<T> &ref) {
        topIndex = ref.topIndex;
        length = ref.length;
        capacity = ref.capacity;
        array = ref.array;
        array = new T [length];
        for (int i = 0; i < capacity; ++i) {
            array[i] = new T(ref.array[i]);
        }
    }

    template <class T>
    ArrayBaseStack<T>::~ArrayBaseStack() {
        delete array;
    }

    template <class T>
    bool ArrayBaseStack<T>::ensureIncrease(const int &requireLength) {
        return capacity+requireLength<length;
    }

    template <class T>
    void ArrayBaseStack<T>::increaseCapacity(const int &requireLength) {
        T *tempArray = array;
        length = capacity + requireLength + 1;
        array = new T [length];
        for (int i = 0; i < capacity; ++i) {
            array[i] = tempArray[i];
        }
        delete[] tempArray;
    }

    template <class T>
    bool ArrayBaseStack<T>::isEmpty() {
        return topIndex == -1;
    }

    template <class T>
    void ArrayBaseStack<T>::push(const T& data) {
        if(!ensureIncrease(1)){
            increaseCapacity(1);
        }
        topIndex += 1;
        ++capacity;
        *(array + (topIndex)) = data;
    }

    template <class T>
    T ArrayBaseStack<T>::pop() {
        if(isEmpty()){
            std::cout<<"Pop Memory Error"<<std::endl;
            exit(-1);
        }
        T result = array[topIndex];
        --capacity;
        --topIndex;
        return result;
    }

    template <class T>
    T ArrayBaseStack<T>::seek() const {
        if(isEmpty()){
            std::cout<<"Seek Memory Error"<<std::endl;
            exit(-1);
        }
        return array[topIndex];
    }

}

#endif // FIRSTCPP_ARRAYBASESTACK _H

