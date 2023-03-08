//
// Created by 홍준근 on 2023/02/21.
//
#include "enthusiasm/class/IKnowTempObject.h"

int main(){
    Temporary(100);
    std::cout<<"********** after make!"<<std::endl<<std::endl;

    Temporary(200).showTempInfo();
    std::cout<<"********** after make!"<<std::endl<<std::endl;

    const Temporary &ref = Temporary(300);
    std::cout<<"********** end of main!"<<std::endl<<std::endl;
    return 0;
}