//
// Created by 홍준근 on 2023/03/20.
//

#include "enthusiasm/linked_list/CLinkedList.h"
#include <iostream>

using namespace Collection;

int main(){
    CLinkedList<int> list = CLinkedList<int>();

    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insertFront(2);
    list.insertFront(1);

    // 연속 3회 출력
    if(!list.first().isError()){
        std::cout<<list.current().getData()<<" ";
        for(int i = 0;i<list.count() * 3 - 1;i++){
            list.next();
            std::cout<<list.current().getData()<<" ";
        }
    }
    std::cout<<std::endl;
    
    // 2의 배수 모두 삭제
    if(list.count() != 0){
        if(list.first().getData() % 2 == 0) {
            list.remove();
        }
        for (int i = 0; i < list.count() - 1; ++i) {
            if(list.next().getData() %2 == 0){
                list.remove();
            }
        }
    }

    // 전체 데이터 1회 출력
    if(!list.first().isError()){
        std::cout<<list.current().getData()<<" ";
        for(int i = 0;i<list.count() - 1;i++){
            list.next();
            std::cout<<list.current().getData()<<" ";
        }
    }


    return 0;
}