#ifndef FIRSTCPP_HASINHERITANCE _H
#define FIRSTCPP_HASINHERITANCE _H
#include <cstring>
#include <iostream>

class Gun {
private:
    int bulletCount;
public:
    Gun(int bulletCount):bulletCount(bulletCount) {
    }

    void shot() {
        std::cout<<"BBANG!"<<std::endl;
        --bulletCount;
    }
};

class PoliceOffice : public Gun {
private:
    int handcuff;
public:
    PoliceOffice(int bulletCount, int handcuff)
            : Gun(bulletCount), handcuff(handcuff) {
    }

    void putHandCuff() {
        std::cout << "SNAP!"<< std::endl<<std::endl;
        --handcuff;
    }
};
#endif // FIRSTCPP_HASINHERITANCE _H

