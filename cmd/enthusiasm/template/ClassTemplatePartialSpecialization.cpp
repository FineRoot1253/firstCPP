#include "enthusiasm/template/ClassTemplatePartialSpecialization.h"

int main(){
    MySimple<char, double> obj1;
    obj1.whoAreYou();
    MySimple<int, long> obj2;
    obj2.whoAreYou();
    MySimple<int, double> obj3;
    obj3.whoAreYou();
    return 0;
}
