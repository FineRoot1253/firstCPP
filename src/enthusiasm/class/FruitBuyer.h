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
    FruitBuyer(int money)
            : myMoney(money), numOfApples(0) {
    };

    void buyApples(FruitSeller &seller, int money);

    void showBuyResult();
};


#endif //FIRSTCPP_FRUITBUYER_H
