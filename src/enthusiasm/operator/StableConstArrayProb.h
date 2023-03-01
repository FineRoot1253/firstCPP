#ifndef FIRSTCPP_STABLECONSTARRAYPROB _H
#define FIRSTCPP_STABLECONSTARRAYPROB _H
#include <iostream>

class BoundCheckIntArray{
private:
    int * arr;
    int length;
private:
    BoundCheckIntArray(const BoundCheckIntArray& ref){}
    BoundCheckIntArray& operator=(const BoundCheckIntArray& ref){}
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

    int operator[] (int index) const{
        if(index < 0 || index >= length){
            std::cout<<"Array index out of bound exception"<<std::endl;
            exit(1);
        }
        return arr[index];
    }

    int getLength() const {
        return length;
    }
};

void showAllData(const BoundCheckIntArray& ref){
    for (int i = 0; i < ref.getLength(); ++i) {
        std::cout<<ref[i]<<std::endl;
    }
}
#endif // FIRSTCPP_STABLECONSTARRAYPROB _H

