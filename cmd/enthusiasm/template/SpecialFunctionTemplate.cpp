#include "enthusiasm/template/SpecialFunctionTemplate.h"

int main(){
    std::cout<<max(11, 15)<<std::endl;
    std::cout<<max('T', 'Q')<<std::endl;
    std::cout<<max(3.5, 7.5)<<std::endl;
    std::cout<<max("Simple", "Best")<<std::endl;

    char str1[] = "Simple";
    char str2[] = "Best";
    std::cout<<max(str1, str2);
    return 0;
}