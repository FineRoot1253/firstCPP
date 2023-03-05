#include "enthusiasm/casting/DynamicBadCastRef.h"

int main(){
    SoSimple simple;
    SoSimple& ref = simple;

    try{
        SoComplex& complexRef= dynamic_cast<SoComplex&>(ref);
        complexRef.showSimpleInfo();
    }catch (std::bad_cast ex){
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}


