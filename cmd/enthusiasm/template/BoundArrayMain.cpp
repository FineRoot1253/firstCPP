//
// Created by 홍준근 on 2023/02/23.
//

#include "enthusiasm/template/ArrayTemplate.h"
#include "enthusiasm/template/Point.h"
#include "enthusiasm/template/Point.cpp"

int main(){
    /***
     *  int형 정수 저장
     */
     BoundCheckArray<int> intArray(5);
    for (int i = 0; i < 5; ++i) {
        intArray[i] = (i+1)*11;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout<<intArray[i]<<std::endl;
    }
    /***
     *  Point 객체 저장
     */
    BoundCheckArray<Point<int>> objectArray(3);
    objectArray[0] = Point<int>(3, 4);
    objectArray[1] = Point<int>(5, 6);
    objectArray[2] = Point<int>(7, 8);
    for (int i = 0; i < objectArray.getLength(); ++i) {
        objectArray[i].showPosition();
    }
    /***
     *  Point 객체 주소 값 저장
     */
    BoundCheckArray<Point<int>*> objectPointArray(3);
    objectPointArray[0] = new Point<int>(3, 4);
    objectPointArray[1] = new Point<int>(5, 6);
    objectPointArray[2] = new Point<int>(7, 8);
    for (int i = 0; i < objectPointArray.getLength(); ++i) {
        objectPointArray[i]->showPosition();
    }
    for (int i = 0; i < objectPointArray.getLength(); ++i) {
        delete objectPointArray[i];
    }

    return 0;
}