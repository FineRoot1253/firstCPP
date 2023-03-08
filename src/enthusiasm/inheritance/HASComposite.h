#ifndef FIRSTCPP_HASCOMPOSITE _H
#define FIRSTCPP_HASCOMPOSITE _H
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

class PoliceOffice{
private:
    int handcuff;
    Gun* pistol;
public:
    PoliceOffice(int bulletCount, int handcuff)
            : handcuff(handcuff) {
        if(bulletCount >0){
            pistol = new Gun(bulletCount);
        }else{
            pistol = nullptr;
        }
    }

    ~PoliceOffice(){
        if(pistol != nullptr){
            delete pistol;
        }
    }

    void putHandCuff() {
        std::cout << "SNAP!"<< std::endl;
        --handcuff;
    }

    void shot(){
        if(pistol == nullptr){
            std::cout<<"Tik!!"<<std::endl;
        }else{
            pistol->shot();
        }
    }
};
#endif // FIRSTCPP_HASCOMPOSITE _H

