//
// Created by 홍준근 on 2022/12/25.
//

#ifndef FIRSTCPP_MEETPOINT_H
#define FIRSTCPP_MEETPOINT_H

#include "Line.h"
#include "Constants.h"

template <class T>
class DynamicArray{
private:
    T **array;
    int memLength;
    int currentCapacity;

    bool ensureCapacity(int reqSize);
    bool isExist(T* point);

    void increaseCapacity(int reqSize);

public:
    DynamicArray();
    DynamicArray(const T** array, int size);
    ~DynamicArray();

    void addArray(T** array, int size);
    void add(T* element);
    void clear();

    T* get(int index);
    int getSize();
};

template <class T>
DynamicArray<T>::DynamicArray() {
    currentCapacity=0;
    memLength=static_cast<int>(eConstants::meet_points_initial_array_size);
    this->array = new T*[memLength];
}

template <class T>
DynamicArray<T>::DynamicArray(const T** array, int size) {
    currentCapacity = size;
    memLength = size+1;
    T** tempArray = this->array;
    this->array = new T*[memLength];
    std::copy(array , array + size, this->array);
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    for(int i = 0 ; i < this->currentCapacity ; i ++){
        delete array[i];
    }
    delete[] array;
}

template <class T>
bool DynamicArray<T>::ensureCapacity(int reqSize) {
    return currentCapacity + reqSize < memLength;
}

//template <class T>
//bool DynamicArray<T>::isExist(T* point) {
//    for (int i = 0; i < currentCapacity; ++i) {
//        if(point->isEqual(array[i])){
//            return true;
//        }
//    }
//    return false;
//}

template <class T>
void DynamicArray<T>::increaseCapacity(int reqSize) {
    T** tempArray = array;
    memLength = currentCapacity+reqSize + 1;
    array = new T*[memLength];
    std::copy(tempArray, tempArray + memLength, array);
    delete[] *tempArray;
    currentCapacity += reqSize;
}

template <class T>
void DynamicArray<T>::addArray(T **array, int size) {
    if(!ensureCapacity(size)){
        increaseCapacity(size);
    }
    std::copy(array, array + size, this->array + currentCapacity);
}

template <class T>
void DynamicArray<T>::add(T* element) {
    if(!ensureCapacity(1)){
        increaseCapacity(1);
    }
    *(array + currentCapacity++) = element;
}

template <class T>
void DynamicArray<T>::clear() {
    T** temp = array;
    currentCapacity=0;
    memLength=static_cast<int>(eConstants::meet_points_initial_array_size);
    array = new T*[memLength];
    delete[] temp;
}


template <class T>
T* DynamicArray<T>::get(int index){
    return array[index];
}


template <class T>
int DynamicArray<T>::getSize() {
    return currentCapacity;
}
#endif //FIRSTCPP_MEETPOINT_H
