//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_PRIVATECONSTRUCTOR_H
#define FIRSTCPP_PRIVATECONSTRUCTOR_H

#include <iostream>

class PrivateConstructor{
private:
    int num;
    PrivateConstructor(int num):num(num){};
public:
   static PrivateConstructor& createPrivateConstructor(int num) {
       PrivateConstructor * ptr = new PrivateConstructor(num);
       return *ptr;
   }
   void showNum() const {
       std::cout<<num<<std::endl;
   }
};

#endif //FIRSTCPP_PRIVATECONSTRUCTOR_H
