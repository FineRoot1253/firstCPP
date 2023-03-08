#ifndef FIRSTCPP_PUBLICSTATICMEMBER _H
#define FIRSTCPP_PUBLICSTATICMEMBER _H
#include <iostream>

class SoSimple{
public:
    static int simpleObjectCount;
public:
    SoSimple(){
        ++simpleObjectCount;
    }
};
int SoSimple::simpleObjectCount = 0;
#endif // FIRSTCPP_PUBLICSTATICMEMBER _H

