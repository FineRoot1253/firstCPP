#include "enthusiasm/template/FunctionTemplateStaticVar.h"

int main(){
    showStaticValue<int>();
    showStaticValue<int>();
    showStaticValue<int>();
    std::cout<<std::endl;
    showStaticValue<long>();
    showStaticValue<long>();
    showStaticValue<long>();
    std::cout<<std::endl;
    showStaticValue<double>();
    showStaticValue<double>();
    showStaticValue<double>();
    return 0;
}