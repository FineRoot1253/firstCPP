//
// Created by 홍준근 on 2023/01/16.
//

#include "SelfRef.h"

SelfRef::SelfRef(int n):num(n){
    std::cout<<"객체생성"<<std::endl;
}
SelfRef& SelfRef::adder(int n){
    num+=n;
    return *this;
}
SelfRef& SelfRef::showTwoNumber(){
    std::cout<<num<<std::endl;
    return *this;
}