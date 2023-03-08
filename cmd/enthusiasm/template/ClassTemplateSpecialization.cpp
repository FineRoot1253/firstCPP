#include "enthusiasm/template/ClassTemplateSpecialization.h"

int main(){
    SimpleDataWrapper<int> integerWrap(170);
    integerWrap.showDataInfo();
    SimpleDataWrapper<char *> charPointerWrap("Class Template Specialization");
    charPointerWrap.showDataInfo();
    SimpleDataWrapper<Point<int>> integerPointObjectWrap(3, 7);
    integerPointObjectWrap.showDataInfo();
    return 0;
}