//
// Created by 홍준근 on 2022/11/19.
//
#include "header1.h"
#include "header2.h"

namespace header1{
    int func(){
        foo();
        header2::foo();
    }
}