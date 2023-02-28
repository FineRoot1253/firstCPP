#ifndef FIRSTCPP_REALOBJUNDER2 _H
#define FIRSTCPP_REALOBJUNDER2 _H
#include <iostream>

typedef struct Data{
    int data;
    void (*showData)(Data*);
    void (*add)(Data*, int);
} Data;

void showData(Data* data){
    std::cout<<"Data: "<<data->data<<std::endl;
}

void add(Data* data, int num){
    data->data += num;
}

#endif // FIRSTCPP_REALOBJUNDER2 _H

