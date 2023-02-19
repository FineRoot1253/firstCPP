//
// Created by 홍준근 on 2023/01/22.
//

#ifndef FIRSTCPP_HGROWABLELIST_H
#define FIRSTCPP_HGROWABLELIST_H

#include "enthusiasm/banking/common/constants.h"
#include "enthusiasm/banking/common/Exception.h"
#include "Iterator.h"
#include <iostream>

template<class T>
class HGrowableList {
private:
    T **array;
    int memLength;
    int currentCapacity;

    bool ensureCapacity(const int &reqSize);

    void increaseCapacity(const int &reqSize);

public:
    friend class Iterator<T, HGrowableList<T>>;

    HGrowableList();

    HGrowableList(const HGrowableList<T> &hList);

    HGrowableList(const T **array, const int &size);

    HGrowableList<T> &operator=(const HGrowableList<T>& ref);

    ~HGrowableList();

    void addArray(const T **array, const int &size);

    void add(const T element);

    void replace(const int &index, const T &element);

    void remove(const int& index);

    void clear();

    bool isExist(const T &element) const;

    T &getForSave(const int &index);

    const T &get(const int &index) const;

    const T **getAll() const;

    const int &where(const T &element) const;

    const int &getSize() const;

    Iterator<T,HGrowableList<T>>* createIterator() const;
};

template<class T>
HGrowableList<T>::HGrowableList()
        : memLength(constants::HDATA_GROUP_INIT_SIZE), array(new T *[constants::HDATA_GROUP_INIT_SIZE]),
          currentCapacity(0) {
}

template<class T>
HGrowableList<T>::HGrowableList(const HGrowableList<T> &hList)
        : memLength(hList.memLength), array(nullptr), currentCapacity(hList.currentCapacity) {
    this->array = new T *[hList.memLength];
    for (int i = 0; i < hList.currentCapacity; ++i) {
        this->array[i] = new T(*hList.array[i]);
    }
}

template<class T>
HGrowableList<T>::HGrowableList(const T **array, const int &size) {
    currentCapacity = size;
    memLength = size + 1;
    this->array = new T *[memLength];
    for (int i = 0; i < size; ++i) {
        this->array[i] = new T(*array[i]);
    }
}

template<class T>
HGrowableList<T>::~HGrowableList() {
    if (array != nullptr) {
        for (int i = 0; i < this->currentCapacity; i++) {
            delete array[i];
        }
        delete[] array;
    }
}

template<class T>
bool HGrowableList<T>::ensureCapacity(const int &reqSize) {
    return currentCapacity + reqSize < memLength;
}

template<class T>
void HGrowableList<T>::increaseCapacity(const int &reqSize) {
    T **tempArray = array;
    memLength = currentCapacity + reqSize + 1;
    array = new T *[memLength];
    for (int i = 0; i < currentCapacity; ++i) {
        array[i] = tempArray[i];
    }
    delete[] *tempArray;
}

template<class T>
void HGrowableList<T>::addArray(const T **array, const int &size) {
    if (!ensureCapacity(size)) {
        increaseCapacity(size);
    }
    T **temp = this->array;
    this->array = new T *[memLength];
    for (int i = 0; i < size; ++i) {
        this->array[i] = new T(*array[currentCapacity++]);
    }
    delete[]temp;
}

template<class T>
void HGrowableList<T>::add(const T element) {
    if (!ensureCapacity(1)) {
        increaseCapacity(1);
    }
    *(array + currentCapacity++) = new T(element);
}

template<class T>
T &HGrowableList<T>::getForSave(const int &index) {
    if (currentCapacity <= 0) {
        throw SystemCallException(constants::ex_kr::EX_MSG_SYS_OOB);
    }
    return *array[index];
}

template<class T>
void HGrowableList<T>::replace(const int &index, const T &element) {
    if (currentCapacity <= 0 || index >= currentCapacity) {
        throw SystemCallException(constants::ex_kr::EX_MSG_SYS_OOB);
    }
    T *temp = array[index];
    array[index] = new T(element);
    delete temp;
}

template<class T>
void HGrowableList<T>::remove(const int &index) {
    if (currentCapacity <= 0 || index >= currentCapacity) {
        throw SystemCallException(constants::ex_kr::EX_MSG_SYS_OOB);
    }
    // push elements to forward
    // empty last memory space is nvm on me. I ? don`t ? know.
    if(index != currentCapacity -1){
        for (int i = index; i < currentCapacity; ++i) {
            delete array[i];
            if(i != currentCapacity - 1){
                array[i] = array[i+1];
            }
        }
    }else{
        delete array[index];
    }
}

template<class T>
void HGrowableList<T>::clear() {
    T **temp = array;
    currentCapacity = 0;
    memLength = constants::HDATA_GROUP_INIT_SIZE;
    array = new T *[memLength];
    delete[] temp;
}

template<class T>
bool HGrowableList<T>::isExist(const T &element) const {
    for (int i = 0; i < currentCapacity; ++i) {
        if (array[i]->isEqual(element)) {
            return true;
        }
    }
    return false;
}


template<class T>
const T &HGrowableList<T>::get(const int &index) const {
    if (index < 0 ||  index >= currentCapacity) {
        throw SystemCallException(constants::ex_kr::EX_MSG_SYS_OOB);
    }
    return *array[index];
}


template<class T>
const T **HGrowableList<T>::getAll() const {
    return const_cast<const T **>(array);
}

template<class T>
const int &HGrowableList<T>::where(const T &element) const {
    for (int i = 0; i < currentCapacity; ++i) {
        if (array[i]->isEqual(element)) {
            return i;
        }
    }
    return -1;
}

template<class T>
const int &HGrowableList<T>::getSize() const {
    return currentCapacity;
}

template<class T>
HGrowableList<T> &HGrowableList<T>::operator=(const HGrowableList<T>& ref) {
    memLength = ref.memLength;
    currentCapacity = ref.currentCapacity;
    array = new T * [memLength];
    for (int i = 0; i < currentCapacity; ++i) {
        array[i] = new T(*ref.array[i]);
    }
    return *this;
}

template<class T>
Iterator<T, HGrowableList<T>>* HGrowableList<T>::createIterator() const {
    return new Iterator<T, HGrowableList<T>>(this);
}


#endif //FIRSTCPP_HGROWABLELIST_H
