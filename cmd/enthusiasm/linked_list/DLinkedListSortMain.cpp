//
// Created by 홍준근 on 2023/03/19.
//

#include "enthusiasm/linked_list/DLinkedList.h"
#include <iostream>

using namespace Collection;

int main(){
    DLinkedList<int> list = DLinkedList<int>();

    list.setSortRule(whichIsPrecede);

    list.insert(11);
    list.insert(11);
    list.insert(22);
    list.insert(22);
    list.insert(33);

    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        for(list.first();!list.isDone();list.next()){
            std::cout<<list.current().getData()<<" ";
        }
    }

    std::cout<<std::endl<<std::endl;
    if(!list.first().isError()){
        for(list.first();!list.isDone();list.next()){
            if(list.current().getData() == 22){
                list.remove();
            }
        }
    }
    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        for(list.first();!list.isDone();list.next()){
            std::cout<<list.current().getData()<<" ";
        }
    }
    return 0;
}