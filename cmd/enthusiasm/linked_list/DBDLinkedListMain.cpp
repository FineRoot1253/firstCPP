//
// Created by 홍준근 on 2023/03/20.
//
#include "enthusiasm/linked_list/DBDLinkedList.h"
#include <iostream>

using namespace Collection;

int main(){
    DBDLinkedList<int> list = DBDLinkedList<int>();

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        for (int i = 0; i < list.count(); ++i) {
            std::cout<<list.current().getData()<<" ";
            Result<int> result = list.next();
            if(result.isError()){
                break;
            }
        }
    }
    std::cout<<std::endl;

    // 3 삭제
    if(!list.first().isError()){
        for (int i = 0; i <= list.count(); ++i) {
            if(list.current().getData()==3){
                list.remove();
            }
            Result<int> result = list.next();
            if(result.isError()){
                break;
            }
        }
    }
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;
    if(!list.first().isError()){
        for (int i = 0; i <= list.count(); ++i) {
            std::cout<<list.current().getData()<<" ";
            Result<int> result = list.next();
            if(result.isError()){
                break;
            }
        }
    }
    std::cout<<std::endl;
    // 양 끝단 삭제
    if(!list.first().isError()){
        for (int i = 0; i <= list.count(); ++i) {
            if(list.current().getData()==1 ||list.current().getData()==5){
                list.remove();
            }
            Result<int> result = list.next();
            if(result.isError()){
                break;
            }
        }
    }
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;
    if(!list.first().isError()){
        for (int i = 0; i <= list.count(); ++i) {
            std::cout<<list.current().getData()<<" ";
            Result<int> result = list.next();
            if(result.isError()){
                break;
            }
        }
    }
    return 0;
}