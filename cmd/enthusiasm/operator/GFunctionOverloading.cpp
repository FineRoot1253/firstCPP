#include "enthusiasm/operator/GFunctionOverloading.h"

int main(){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1+pos2;
    pos1.showPosition();
    pos2.showPosition();
    pos3.showPosition();
    return 0;
}


