#ifndef FIRSTCPP_DERIVDESTORDER _H
#define FIRSTCPP_DERIVDESTORDER _H
#include <iostream>

class SoBase {
private:
    int baseNum;
public:
    SoBase(int baseNum)
            : baseNum(baseNum) {
        std::cout<<"SoBase(): "<<this->baseNum<<std::endl;
    }
    ~SoBase(){
        std::cout<<"~SoBase(): "<<baseNum<<std::endl;
    }
};

class SoDerived : public SoBase{
private:
    int derivedNum;
public:
    SoDerived(int num)
            : SoBase(num)
              , derivedNum(num) {
        std::cout<<"SoDerived(): "<<derivedNum<<std::endl;
    }

    ~SoDerived(){
        std::cout<<"~SoDerived(): "<<derivedNum<<std::endl;
    }
};
#endif // FIRSTCPP_DERIVDESTORDER _H

