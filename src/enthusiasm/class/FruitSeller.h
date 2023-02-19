//
// Created by 홍준근 on 2023/01/13.
//

#ifndef FIRSTCPP_FRUITSELLER_H
#define FIRSTCPP_FRUITSELLER_H

#include <iostream>

class FruitSeller {
private:
    const int applePrice;
    int numOfApples;
    int myMoney;
public:
    FruitSeller(int price, int num, int money)
            : applePrice(price)
            , numOfApples(num)
            , myMoney(money) {
    };

    int saleApples(int money);

    void showSalesResult() const;
};


#endif //FIRSTCPP_FRUITSELLER_H
