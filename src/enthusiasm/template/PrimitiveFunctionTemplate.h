#ifndef FIRSTCPP_PRIMITIVEFUNCTIONTEMPLATE _H
#define FIRSTCPP_PRIMITIVEFUNCTIONTEMPLATE _H
#include <iostream>

template<class T1, class T2>
void showData(double num){
    std::cout<<(T1)num<<", "<<(T2)num<<std::endl;
}
#endif // FIRSTCPP_PRIMITIVEFUNCTIONTEMPLATE _H

