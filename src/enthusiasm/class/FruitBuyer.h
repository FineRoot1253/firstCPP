//
// Created by 홍준근 on 2023/01/13.
//

#ifndef FIRSTCPP_FRUITBUYER_H
#define FIRSTCPP_FRUITBUYER_H

#include <iostream>
#include "FruitSeller.h"

class FruitBuyer {
private:
    int myMoney;
    int numOfApples;
public:
    void init(int money);
    void buyApples(FruitSeller &seller, int money);
    void showBuyResult();
};


#endif //FIRSTCPP_FRUITBUYER_H
