//
// Created by 홍준근 on 2023/04/02.
//

#ifndef FIRSTCPP_CONSTANTS_H
#define FIRSTCPP_CONSTANTS_H
namespace Constants{
    namespace BurgerShop{
        enum class BurgerType: int{
            CHEESE = 0,
            BULGOGI,
            DOUBLE
        };
        BurgerType getBurgerTypeFromNumber(const int& num){
            switch(num){
                case 0:
                    return BurgerType::CHEESE;
                case 1:
                    return BurgerType::BULGOGI;
                case 2:
                    return BurgerType::DOUBLE;
                default:
                    return BurgerType::CHEESE;
            }
        }
        int getMakeTime(const BurgerType& type) {
            switch(type){
                case BurgerType::CHEESE:
                    return 12;
                case BurgerType::BULGOGI:
                    return 15;
                case BurgerType::DOUBLE:
                    return 24;
                default:
                    return -1;
            }
        }
    }
}
#endif //FIRSTCPP_CONSTANTS_H
