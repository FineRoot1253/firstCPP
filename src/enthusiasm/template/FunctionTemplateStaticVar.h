#ifndef FIRSTCPP_FUNCTIONTEMPLATESTATICVAR _H
#define FIRSTCPP_FUNCTIONTEMPLATESTATICVAR _H
#include <iostream>

template <class T>
void showStaticValue(){
    static T num = 0;
    num += 1;
    std::cout<<num<<" ";
}
#endif // FIRSTCPP_FUNCTIONTEMPLATESTATICVAR _H