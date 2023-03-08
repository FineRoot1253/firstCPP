#ifndef FIRSTCPP_SPECIALFUNCTIONTEMPLATE _H
#define FIRSTCPP_SPECIALFUNCTIONTEMPLATE _H

#include <iostream>

template <class T>
T max(T a, T b){
    return a > b ? a : b;
}

template <>
char* max(char* a, char* b){
    std::cout<<"char* max<char*>(char* a, char* b)"<<std::endl;
    return std::strlen(a) > std::strlen(b) ? a : b;
}

template <>
const char* max(const char* a, const char* b){
    std::cout<<"const char* max<const char*>(const char* a, const char* b)"<<std::endl;
    return std::strcmp(a, b) ? a : b;
}
#endif // FIRSTCPP_SPECIALFUNCTIONTEMPLATE _H