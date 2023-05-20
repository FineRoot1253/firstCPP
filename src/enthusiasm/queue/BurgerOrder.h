//
// Created by 홍준근 on 2023/04/02.
//

#ifndef FIRSTCPP_BURGERORDER_H
#define FIRSTCPP_BURGERORDER_H

#include "constants.h"

using namespace Constants::BurgerShop;

class BurgerOrder{
private:
    BurgerType type;
public:
    BurgerOrder():type(BurgerType::CHEESE){};
    BurgerOrder(const BurgerType& type):type(type){};
    BurgerOrder(const BurgerOrder& ref):type(ref.type){
    };
    BurgerOrder(const BurgerOrder&& ref){
        type = ref.type;
    };
    BurgerOrder& operator=(const BurgerOrder& ref){
        type = ref.type;
        return *this;
    };
    ~BurgerOrder(){
    };
public:
    BurgerType getType() const{
        return type;
    }
};
#endif //FIRSTCPP_BURGERORDER_H
