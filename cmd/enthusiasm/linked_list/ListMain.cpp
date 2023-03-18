//
// Created by 홍준근 on 2023/03/15.
//

#include "enthusiasm/linked_list/ArrayList.h"
#include <iostream>

using namespace Collection;

int main(){
    // ArrayList 생성 및 초기화
    ArrayList<int> list = ArrayList<int>(0);
    int data;

    list.insert(11);
    list.insert(11);
    list.insert(22);
    list.insert(22);
    list.insert(33);
    
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;
    
    if(!list.first().isError()){
        std::cout<<list.first().getData()<<" ";
        for (list.first(); !list.isDone(); list.next()) {
            std::cout<<list.current().getData()<<" ";
        }
    }
    std::cout<<std::endl<<std::endl;

    if(!list.first().isError()){
        if(list.first().getData() == 22){
            list.remove();
        }
        for (list.first(); !list.isDone(); list.next()) {
            if(list.current().getData() == 22){
                list.remove();
            }
        }
    }

    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        std::cout<<list.first().getData()<<" ";
        for (list.first(); !list.isDone(); list.next()) {
            std::cout<<list.current().getData()<<" ";
        }
    }
    return 0;
}