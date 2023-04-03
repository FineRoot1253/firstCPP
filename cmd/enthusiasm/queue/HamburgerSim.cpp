//
// Created by 홍준근 on 2023/04/02.
//

#include <iostream>
#include <cmath>
#include <ctime>

#include "enthusiasm/queue/BurgerOrder.h"
#include "enthusiasm/queue/CircularQueue.h"
#include "enthusiasm/linked_list/DLinkedList.h"

#define CUSTOMER_ORDER_TERM 15

using namespace Collection::Queue;
using namespace Constants::BurgerShop;

int main(){
    int makeProcessStatus = 0;
    int cheeseOrder = 0;
    int bulgogiOrder = 0;
    int doubleOrder = 0;

    CircularQueue<int> queue = CircularQueue<int>();
    Collection::DLinkedList<BurgerOrder> orderList = Collection::DLinkedList<BurgerOrder>();

    srand(time(nullptr));

    for (int i = 0; i < 3600; ++i) {
        if(i % CUSTOMER_ORDER_TERM == 0){
            BurgerType type = getBurgerTypeFromNumber(rand()%3);
            queue.enqueue(getMakeTime(type));
            orderList.insert(BurgerOrder(type));
        }
        if(makeProcessStatus <= 0 && !queue.isEmpty()){
            makeProcessStatus = queue.dequeue();
        }
        --makeProcessStatus;
    }

    for (orderList.first(); !orderList.isDone(); orderList.next()) {
        switch(orderList.current().getData().getType()){
            case BurgerType::CHEESE:
                ++cheeseOrder;
                break;
            case BurgerType::BULGOGI:
                ++bulgogiOrder;
                break;
            case BurgerType::DOUBLE:
                ++doubleOrder;
                break;
            default:
                break;
        }
    }

    std::cout<<"Simulation Report!"<<std::endl;
    std::cout<<" - Cheese burger: "<<cheeseOrder<<std::endl;
    std::cout<<" - Bulgogi burger: "<<bulgogiOrder<<std::endl;
    std::cout<<" - Double burger: "<<doubleOrder<<std::endl;
    std::cout<<" - Waiting room size: "<<CIRCULAR_QUEUE_LENGTH<<std::endl;

    return 0;
}