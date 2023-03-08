#include "enthusiasm/polymorphism/ReferenceAttribute.h"

int main(){
    Third obj;
    obj.firstFunc();
    obj.secondFunc();
    obj.thirdFunc();
    obj.simpleFunc();

    Second& sRef = obj;
    sRef.firstFunc();
    sRef.secondFunc();
    sRef.simpleFunc();

    First& fRef = obj;
    fRef.firstFunc();
    fRef.simpleFunc();
    return 0;
}