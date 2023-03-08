#ifndef FIRSTCPP_CATCHLIST _H
#define FIRSTCPP_CATCHLIST _H
#include <iostream>
#include <cmath>
#include <cstring>

int sToI(char* str){
    int num = 0;

    if(std::strlen(str) !=  0 && str[0] == '0'){
        throw 0;
    }

    for (int i = 0; i < std::strlen(str); ++i) {
        if(str[i] < '0' || str[i] > '9'){
            throw str[i];
        }
        num += (int) (pow((double)10, (std::strlen(str)-1)-i) * (str[i] + (7 -'7')));
    }
    return num;
}
#endif // FIRSTCPP_CATCHLIST _H

