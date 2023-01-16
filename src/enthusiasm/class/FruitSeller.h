//
// Created by 홍준근 on 2023/01/13.
//

#ifndef FIRSTCPP_FRUITSELLER_H
#define FIRSTCPP_FRUITSELLER_H

#include <iostream>

class FruitSeller {
private:
    int applePrice;
    int numOfApples;
    int myMoney;
public:
    void init(int price, int num, int money);
    int saleApples(int money);
    void showSalesResult();
};


#endif //FIRSTCPP_FRUITSELLER_H
