//
// Created by 홍준근 on 2023/01/15.
//

#include "Rectangle.h"
bool Rectangle::init(const Point &highLeft, const Point &lowRight) {
    if(highLeft.GetX()>lowRight.GetX() ||highLeft.GetY()>lowRight.GetY()){
        std::cout<<"잘못된 위치정보 전달"<<std::endl;
        return false;
    }
    this->highLeft = highLeft;
    this->lowRight = lowRight;
    return true;
}

void Rectangle::showRecInfo() {
    std::cout<<"좌 상단: "<<"["<<highLeft.GetX()<<", ";
    std::cout<<highLeft.GetY()<<"]"<<std::endl;
    std::cout<<"우 하단: "<<"["<<lowRight.GetX()<<", ";
    std::cout<<lowRight.GetY()<<"]"<<std::endl<<std::endl;
}


