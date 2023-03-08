#include "enthusiasm/casting/PolymorphicStableCasting.h"

int main(){
    SoSimple * simple = new SoSimple;
    SoComplex * complex = dynamic_cast<SoComplex*>(simple);
    if(complex != nullptr){
        complex->showSimpleInfo();
    }else{
        std::cout<<"형 변환 실패!"<<std::endl;
    }

    return 0;
}


