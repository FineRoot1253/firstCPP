#ifndef FIRSTCPP_ARRAYCLASS _H
#define FIRSTCPP_ARRAYCLASS _H
#include <iostream>

class BoundCheckIntArray{
private:
    int * arr;
    int length;
public:
    BoundCheckIntArray(int length):length(length){
        arr = new int[length];
    }

    ~BoundCheckIntArray(){
        delete []arr;
    }

    int& operator[] (int index){
        if(index < 0 || index >= length){
            std::cout<<"Array index out of bound exception"<<std::endl;
            exit(1);
        }
        return arr[index];
    }
};
#endif // FIRSTCPP_ARRAYCLASS _H

