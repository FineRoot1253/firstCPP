//
// Created by 홍준근 on 2023/01/13.
//

#include "FruitBuyer.h"

FruitBuyer::FruitBuyer(int money) {
    myMoney = money;
    numOfApples = 0;
}

void FruitBuyer::buyApples(FruitSeller &seller, int money) {
    numOfApples += seller.saleApples(money);
    myMoney -= money;
}

void FruitBuyer::showBuyResult() {
    std::cout << "현재 잔액: " << myMoney << std::endl;
    std::cout << "사과 개수: " << numOfApples << std::endl << std::endl;
}
