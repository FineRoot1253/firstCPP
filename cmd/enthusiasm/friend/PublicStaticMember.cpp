#include "enthusiasm/friend/PublicStaticMember.h"

int main(){
    std::cout<<SoSimple::simpleObjectCount<<"번째 SoSimple 객체"<<std::endl;
    SoSimple sim1;
    SoSimple sim2;

    std::cout<<SoSimple::simpleObjectCount<<"번째 SoSimple 객체"<<std::endl;
    std::cout<<sim1.simpleObjectCount<<"번째 SoSimple 객체"<<std::endl;
    std::cout<<sim2.simpleObjectCount<<"번째 SoSimple 객체"<<std::endl;
    return 0;
}