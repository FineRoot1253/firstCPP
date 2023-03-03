#include "enthusiasm/template/PointTemplateFriendFunction.h"

int main(){
    Point<int> pos1(2, 4);
    Point<int> pos2(4, 8);
    Point<int> pos3 = pos1 + pos2;
    std::cout<<pos1<<pos2<<pos3;
    return 0;
}


