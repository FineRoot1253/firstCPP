#include "enthusiasm/operator/PointerOperatorOverloading.h"

int main(){
    Number num(20);
    num.showData();

    (*num) = 30;
    num->showData();
    (*num).showData();
    return 0;
}