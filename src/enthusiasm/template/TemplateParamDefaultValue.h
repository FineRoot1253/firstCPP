#ifndef FIRSTCPP_TEMPLATEPARAMDEFAULTVALUE _H
#define FIRSTCPP_TEMPLATEPARAMDEFAULTVALUE _H
#include <iostream>

template <class T = int, int length = 7>
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
#endif // FIRSTCPP_TEMPLATEPARAMDEFAULTVALUE _H

