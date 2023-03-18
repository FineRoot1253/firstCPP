//
// Created by 홍준근 on 2023/03/15.
//

#ifndef FIRSTCPP_ARRAYLIST_H
#define FIRSTCPP_ARRAYLIST_H

#include <memory>
#include <iostream>

namespace Collection{
    template <class T>
    class ArrayListResult{
    private:
        T data;
        bool errorState;
    public:
        ArrayListResult(const T& data, bool errorState):data(data), errorState(errorState){
        }

        bool isError();
        T getData() const;
    };

    template <class T>
    bool ArrayListResult<T>::isError(){
        return errorState;
    }
    template <class T>
    T ArrayListResult<T>::getData() const{
        return data;
    }

    template <class T>
    class ArrayList{
    private:
        T* array;
        int currentPosition;
        int memLength;
        int currentCapacity;


    private:
        bool ensureCapacity(const int& requireLength) const;
        void increaseLength(const int& requireLength);

    public:
        ArrayList(const int& length)
        : memLength(length)
        , currentCapacity(0)
        , currentPosition(0){
            array = new T[length];
        }

        ArrayList(const ArrayList& ref)
        : array(ref.array){
        }

        ArrayList(ArrayList&& ref){
            array = ref.array;
        }

        ArrayList& operator=(const ArrayList& ref){
            array = ref.array;
        }

        void insert(const T& data);

        ArrayListResult<T> first();

        ArrayListResult<T> current() const;

        ArrayListResult<T> next();

        bool isDone() const;

        ArrayListResult<T> remove();

        int count() const;
    };
    template <class T>
    bool ArrayList<T>::ensureCapacity(const int& requireLength) const{
        return currentCapacity + requireLength < memLength;
    }

    template <class T>
    void ArrayList<T>::increaseLength(const int &requireLength) {
        T *tempArray = array;
        memLength = currentCapacity + requireLength + 1;
        array = new T [memLength];

        for (int i = 0; i < currentCapacity; ++i) {
            array[i] = tempArray[i];
        }
        delete[] tempArray;
    }

    template <class T>
    void ArrayList<T>::insert(const T& data){
        if (!ensureCapacity(1)) {
            increaseLength(1);
        }
        this->array[currentCapacity++] = data;
    }

    template <class T>
    ArrayListResult<T> ArrayList<T>::first(){

        if(currentCapacity== 0){
            return ArrayListResult<T>(T(),true);
        }
        currentPosition = 0;
        return ArrayListResult<T>(array[0],false);
    }

    template <class T>
    ArrayListResult<T> ArrayList<T>::next(){
        if(currentCapacity == currentPosition){
            return ArrayListResult<T>(T(),true);
        }
        return ArrayListResult<T>(array[currentPosition++],false);
    }

    template <class T>
    ArrayListResult<T> ArrayList<T>::current() const{
        if(currentCapacity == currentPosition){
            return ArrayListResult<T>(T(),true);
        }
        return ArrayListResult<T>(array[currentPosition],false);
    }

    template <class T>
    bool ArrayList<T>::isDone() const{
        return currentPosition >= currentCapacity;
    }

    template <class T>
    ArrayListResult<T> ArrayList<T>::remove(){
        T result = array[currentPosition];
        // push elements to forward
        if(currentPosition != currentCapacity -1){
            for (int i = currentPosition; i < currentCapacity; ++i) {
                if(i != currentCapacity - 1){
                    array[i] = array[i+1];
                }
            }
        }
        --currentPosition;
        --currentCapacity;
        return ArrayListResult<T>(result, false);
    }

    template <class T>
    int ArrayList<T>::count() const{
        return currentCapacity;
    }
}
#endif //FIRSTCPP_ARRAYLIST_H