#ifndef FIRSTCPP_MYFRIENDCLASS _H
#define FIRSTCPP_MYFRIENDCLASS _H
#include <cstring>
#include <iostream>

class Girl;

class Boy{
private:
    int height;
    friend class Girl;
public:
    Boy(int len):height(len){}
    void showYourFriendInfo(Girl& frn);
};

class Girl{
private:
    char phNum[20];
public:
    Girl(char* num){
        std::strcpy(phNum, num);
    }
    void showYourFriendInfo(Boy& frn);
    friend class Boy;
};

void Boy::showYourFriendInfo(Girl &frn) {
    std::cout<<"Her phone number: "<<frn.phNum<<std::endl;
}

void Girl::showYourFriendInfo(Boy &frn) {
    std::cout<<"His height: "<<frn.height<<std::endl;
}
#endif // FIRSTCPP_MYFRIENDCLASS _H

