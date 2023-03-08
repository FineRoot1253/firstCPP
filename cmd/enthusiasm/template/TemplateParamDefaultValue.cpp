#include "enthusiasm/template/TemplateParamDefaultValue.h"

int main(){
    SimpleArray<> array;
    for (int i = 0; i < 7; ++i) {
        array[i] = i+1;
    }
    for (int i = 0; i <7; ++i) {
        std::cout<<array[i]<<", ";
    }
    std::cout<<std::endl;
    return 0;
}


