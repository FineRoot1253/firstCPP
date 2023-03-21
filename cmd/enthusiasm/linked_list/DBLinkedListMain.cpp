//
// Created by 홍준근 on 2023/03/20.
//
#include "enthusiasm/linked_list/DBLinkedList.h"
#include <iostream>

using namespace Collection;

int main(){
    DBLinkedList<int> list = DBLinkedList<int>();

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        for (int i = 0; i < list.count(); ++i) {
            std::cout<<list.current().getData()<<" ";
            list.next();
        }
    }
    std::cout<<std::endl;

    // 3 삭제
    if(!list.first().isError()){
        for (int i = 0; i < list.count(); ++i) {
            if(list.current().getData()==3){
                list.remove();
            }
            list.next();
        }
    }
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;
    if(!list.first().isError()){
        for (int i = 0; i < list.count(); ++i) {
            std::cout<<list.current().getData()<<" ";
            list.next();
        }
    }
    std::cout<<std::endl;
    // 양 끝단 삭제
    if(!list.first().isError()){
        for (int i = 0; i < list.count(); ++i) {
            if(list.current().getData()==1 ||list.current().getData()==5){
                list.remove();
            }
            list.next();
        }
    }
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;
    if(!list.first().isError()){
        for (int i = 0; i < list.count(); ++i) {
            std::cout<<list.current().getData()<<" ";
            list.next();
        }
    }
    return 0;
}