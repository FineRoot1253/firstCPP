#include "enthusiasm/casting/PolymorphismDynamicCasting.h"

int main(){
    SoSimple * simple = new SoComplex;
    SoComplex * complex = dynamic_cast<SoComplex*>(simple);
    complex->showSimpleInfo();
    return 0;
}