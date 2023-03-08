#include "enthusiasm/polymorphism/RealObjUnder2.h"

int main(){
    Data obj1 = {15, showData, add};
    Data obj2 = {7, showData, add};
    obj1.add(&obj1,17);
    obj2.add(&obj2, 9);

    obj1.showData(&obj1);
    obj2.showData(&obj2);
    return 0;
}