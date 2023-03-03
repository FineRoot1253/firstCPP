#include "enthusiasm/template/ClassTemplateStaticMem.h"

int main(){
    SimpleStaticMem<int> obj1;
    SimpleStaticMem<int> obj2;
    obj1.addMem(2);
    obj2.addMem(3);
    obj1.showMem();

    SimpleStaticMem<long> obj3;
    SimpleStaticMem<long> obj4;
    obj3.addMem(100);
    obj4.showMem();
    return 0;
}


