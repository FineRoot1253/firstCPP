//
// Created by 홍준근 on 2023/01/15.
//
#include "enthusiasm/class/Rectangle.h"

int main(){
    Point pos1;
    if(!pos1.init(-2, 4)){
        std::cout<<"초기화 실패"<<std::endl;
    }
    if(!pos1.init(2, 4)){
        std::cout<<"초기화 실패"<<std::endl;
    }

    Point pos2;
    if(!pos2.init(5, 9)){
        std::cout<<"초기화 실패"<<std::endl;
    }
    Rectangle rec;
    if(!rec.init(pos2, pos1)){
        std::cout<<"직사각형 초기화 실패"<<std::endl;
    }
    if(!rec.init(pos1, pos2)){
        std::cout<<"직사각형 초기화 실패"<<std::endl;
    }

    rec.showRecInfo();
    return 0;
}