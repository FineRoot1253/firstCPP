#include "enthusiasm/template/TwoTypeAddFunction.h"

int main(){
    std::cout<<add(5, 7)<<std::endl;
    std::cout<<add(3.7, 7.5)<<std::endl;
    std::cout<<add<int>(5, 7)<<std::endl;
    std::cout<<add<double>(3.7, 7.5)<<std::endl;
    return 0;
}