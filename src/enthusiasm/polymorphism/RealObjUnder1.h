#ifndef FIRSTCPP_REALOBJUNDER1 _H
#define FIRSTCPP_REALOBJUNDER1 _H
#include <iostream>

class Data{
private:
    int data;
public:
    Data(int num):data(num){
    }
    void showData(){
        std::cout<<"Data: "<<data<<std::endl;
    }
    void add(int num){
        data += num;
    }
};
#endif // FIRSTCPP_REALOBJUNDER1 _H