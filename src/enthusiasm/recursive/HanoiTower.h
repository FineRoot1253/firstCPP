#ifndef FIRSTCPP_HANOITOWER _H
#define FIRSTCPP_HANOITOWER _H

#include <iostream>
// from: A
// by: B
// to: C
void hanoiTowerMove(int num, char from, char by, char to){
    if(num == 1){
        std::cout<<"원반1을 "<<from<<"에서 "<<to<<"로 이동"<<std::endl;
    }else{
        hanoiTowerMove(num - 1, from, to, by);
        std::cout<<"원반 "<<num<<"을 "<<from<<"에서 "<<to<<"로 이동"<<std::endl;
        hanoiTowerMove(num -1, by, from, to);
    }
}
#endif // FIRSTCPP_HANOITOWER _H

