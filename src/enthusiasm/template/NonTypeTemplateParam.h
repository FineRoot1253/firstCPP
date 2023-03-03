#ifndef FIRSTCPP_NONTYPETEMPLATEPARAM _H
#define FIRSTCPP_NONTYPETEMPLATEPARAM _H
#include <iostream>

template <class T, int length>
class SimpleArray{
private:
    T arr[length];
public:
    SimpleArray<T, length>& operator=(const SimpleArray<T, length>& ref){
        for (int i = 0; i < length; ++i) {
            arr[i] = ref.arr[i];
        }
        return *this;
    }

    T& operator[] (int index) {
        return arr[index];
    }
};
#endif // FIRSTCPP_NONTYPETEMPLATEPARAM _H

