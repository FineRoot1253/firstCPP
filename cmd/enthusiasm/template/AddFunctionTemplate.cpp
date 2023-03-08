#include "enthusiasm/template/AddFunctionTemplate.h"

int main(){
    std::cout<<add<int>(15, 20)<<std::endl;
    std::cout<<add<double>(2.9, 3.7)<<std::endl;
    std::cout<<add<int>(3.2, 3.2)<<std::endl;
    std::cout<<add<int>(3.14, 2.75)<<std::endl;
    return 0;
}