#ifndef FIRSTCPP_DERIVCREORDER _H
#define FIRSTCPP_DERIVCREORDER _H

#include <iostream>

class SoBase {
private:
    int baseNum;
public:
    SoBase()
            : baseNum(30) {
        std::cout<<"SoBase()"<<std::endl;
    }

    SoBase(int baseNum)
            : baseNum(baseNum) {
        std::cout<<"SoBase(int baseNum)"<<std::endl;
    }

    void showBaseData() {
        std::cout << baseNum << std::endl;
    }
};

class SoDerived : public SoBase{
private:
    int derivedNum;
public:
    SoDerived()
            : derivedNum(30) {
        std::cout<<"SoDerived()"<<std::endl;
    }

    SoDerived(int derivedNum)
            : derivedNum(derivedNum) {
        std::cout<<"SoDerived(int derivedNum)"<<std::endl;
    }

    SoDerived(int baseNum,int derivedNum)
            : SoBase(baseNum)
            , derivedNum(derivedNum) {
        std::cout<<"SoDerived(int baseNum, int derivedNum)"<<std::endl;
    }

    void showDerivedData(){
        showBaseData();
        std::cout<<derivedNum<<std::endl;
    }
};

#endif // FIRSTCPP_DERIVCREORDER _H

