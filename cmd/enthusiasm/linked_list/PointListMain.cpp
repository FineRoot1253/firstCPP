//
// Created by 홍준근 on 2023/03/18.
//
#include "enthusiasm/linked_list/ArrayList.h"
#include "enthusiasm/linked_list/Point.h"
#include <iostream>

using namespace Collection;

int main(){
    ArrayList<Point> list = ArrayList<Point>(0);
    Point compPos;

    list.insert(Point(2, 1));
    list.insert(Point(2, 2));
    list.insert(Point(3, 1));
    list.insert(Point(3, 2));

    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        list.first().getData().showPointPosition();
        for (list.first(); !list.isDone(); list.next()) {
            list.current().getData().showPointPosition();
        }
    }
    std::cout<<std::endl;

    compPos = Point(2, 0);

    if(!list.first().isError()){
        if(list.first().getData().compareWith(compPos) == 1){
            list.remove();
        }
        for (list.first(); !list.isDone(); list.next()) {
            if(list.current().getData().compareWith(compPos) == 1){
                list.remove();
            }
        }
    }

    std::cout<<"현재 데이터의 수: "<<list.count()<<std::endl;

    if(!list.first().isError()){
        list.first().getData().showPointPosition();
        for (list.first(); !list.isDone(); list.next()) {
            list.current().getData().showPointPosition();
        }
    }
    std::cout<<std::endl;
    return 0;
}