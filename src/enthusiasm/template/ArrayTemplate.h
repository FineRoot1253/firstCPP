#ifndef FIRSTCPP_ARRAYTEMPLATE _H
#define FIRSTCPP_ARRAYTEMPLATE _H
#include <iostream>
#include <cstdlib>

template <class T>
class BoundCheckArray{
private:
    T * arr;
    int length;

    BoundCheckArray(const BoundCheckArray& ref){}
    BoundCheckArray& operator=(const BoundCheckArray& ref){}

public:
    BoundCheckArray(int length);
    ~BoundCheckArray();
    T& operator[] (int index);
    T operator[] (int index) const;
    int getLength() const;
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int length) :length(length){
    arr = new T[length];
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
    delete []arr;
}
template <class T>
T &BoundCheckArray<T>::operator[](int index) {
    if(index < 0 || index >= this->length){
        std::cout<<"Array index out of bound exception"<<std::endl;
        exit(1);
    }
    return arr[index];
}

template <class T>
T BoundCheckArray<T>::operator[](int index) const {
    if(index < 0 || index >= this->length){
        std::cout<<"Array index out of bound exception"<<std::endl;
        exit(1);
    }
    return arr[index];
}


template <class T>
int BoundCheckArray<T>::getLength() const {
    return length;
}

#endif // FIRSTCPP_ARRAYTEMPLATE _H

