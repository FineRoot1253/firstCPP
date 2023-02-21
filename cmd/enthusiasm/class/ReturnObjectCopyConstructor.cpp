//
// Created by 홍준근 on 2023/02/21.
//

#include "enthusiasm/class/ReturnObjectCopyConstructor.h"

int main(){
    SoSimple obj(10);
    simpleFuncObject(obj).addNum(30).showData();
    obj.showData();
    return 0;
}