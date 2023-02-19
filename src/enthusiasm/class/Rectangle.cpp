//
// Created by 홍준근 on 2023/01/15.
//

#include "Rectangle.h"

Rectangle::Rectangle(const int &xpos1, const int &ypos1, const int &xpos2, const int &ypos2)
: highLeft(xpos1, ypos1), lowRight(xpos2, ypos2){

}


void Rectangle::showRecInfo() {
    std::cout<<"좌 상단: "<<"["<<highLeft.GetX()<<", ";
    std::cout<<highLeft.GetY()<<"]"<<std::endl;
    std::cout<<"우 하단: "<<"["<<lowRight.GetX()<<", ";
    std::cout<<lowRight.GetY()<<"]"<<std::endl<<std::endl;
}


