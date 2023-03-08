#include "enthusiasm/operator/SmartPointer.h"

int main(){
    SmartPtr smartPtr1(new Point(1, 2));
    SmartPtr smartPtr2(new Point(2, 3));
    SmartPtr smartPtr3(new Point(3, 4));

    std::cout<<*smartPtr1;
    std::cout<<*smartPtr2;
    std::cout<<*smartPtr3;

    smartPtr1->setPosition(10,20);
    smartPtr2->setPosition(30,40);
    smartPtr3->setPosition(50,60);

    std::cout<<*smartPtr1;
    std::cout<<*smartPtr2;
    std::cout<<*smartPtr3;
    return 0;
}