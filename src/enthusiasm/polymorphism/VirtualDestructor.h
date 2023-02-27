#ifndef FIRSTCPP_VIRTUALDESTRUCTOR _H
#define FIRSTCPP_VIRTUALDESTRUCTOR _H
#include <cstring>
#include <iostream>

class First {
private:
    char *str1;
public:
    First(char *str1){
        this->str1 = new char[std::strlen(str1)+1];
        std::strcpy(this->str1, str1);
    }
    ~First(){
        std::cout<<"~First()"<<std::endl;
        delete []str1;
    }
};

class Second : public First {
private:
    char *str2;
public:
    Second(char *str1, char *str2): First(str1){
        this->str2 = new char[std::strlen(str2)+1];
        std::strcpy(this->str2, str2);
    }
    ~Second(){
        std::cout<<"~Second()"<<std::endl;
        delete []str2;
    }
};
#endif // FIRSTCPP_VIRTUALDESTRUCTOR _H

