//
// Created by 홍준근 on 2023/01/13.
//
#include "enthusiasm/class/FruitBuyer.h"

int main(){
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);

    buyer.buyApples(seller, 2000);

    std::cout<<"과일 판매자의 현황"<<std::endl;
    seller.showSalesResult();
    std::cout<<"과일 구매자의 현황"<<std::endl;
    buyer.showBuyResult();
    return 0;
}