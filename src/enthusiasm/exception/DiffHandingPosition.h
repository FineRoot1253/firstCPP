#ifndef FIRSTCPP_DIFFHANDINGPOSITION _H
#define FIRSTCPP_DIFFHANDINGPOSITION _H
#include <iostream>
#include <cmath>
#include <cstring>

int sToI(char* str){
    int num = 0;

    for (int i = 0; i < std::strlen(str); ++i) {
        if(str[i] < '0' || str[i] > '9'){
            throw str[i];
        }
        num += (int) (pow((double)10, (std::strlen(str)-1)-i) * (str[i] + (7 -'7')));
    }
    return num;
}
#endif // FIRSTCPP_DIFFHANDINGPOSITION _H

