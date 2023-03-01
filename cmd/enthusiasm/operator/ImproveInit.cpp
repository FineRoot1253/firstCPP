#include "enthusiasm/operator/ImproveInit.h"

int main(){
    Fruit obj1(12);
    std::cout<<"**********************"<<std::endl;
    Apple obj2(obj1);
    std::cout<<"**********************"<<std::endl;
    Banana obj3(obj1);
    return 0;
}