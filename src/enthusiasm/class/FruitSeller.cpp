//
// Created by 홍준근 on 2023/01/13.
//

#include "FruitSeller.h"

void FruitSeller::init(int price, int num, int money) {
    applePrice = price;
    numOfApples = num;
    myMoney = money;
}

int FruitSeller::saleApples(int money) {
    int num = money/applePrice;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller::showSalesResult() {
    std::cout<<"남은 사과: "<< numOfApples <<std::endl;
    std::cout<<"판매 수익: "<< myMoney <<std::endl<<std::endl;
}