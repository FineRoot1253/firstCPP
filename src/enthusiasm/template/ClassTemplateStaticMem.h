#ifndef FIRSTCPP_CLASSTEMPLATESTATICMEM_H
#define FIRSTCPP_CLASSTEMPLATESTATICMEM_H
#include <iostream>

template <class T>
class SimpleStaticMem{
private:
    static T mem;
public:
    void addMem(T num){
        mem += num;
    }

    void showMem() const {
        std::cout<<mem<<std::endl;
    }
};

template <class T>
T SimpleStaticMem<T>::mem = 0;
#endif // FIRSTCPP_CLASSTEMPLATESTATICMEM_H

