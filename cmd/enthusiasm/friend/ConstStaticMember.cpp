#include "enthusiasm/friend/ConstStaticMember.h"
#include <iostream>

int main(){
    std::cout<<"러시아 면적: "<<CountryArea::RUSSIA<<"km^2"<<std::endl;
    std::cout<<"캐나다 면적: "<<CountryArea::CANADA<<"km^2"<<std::endl;
    std::cout<<"중국 면적: "<<CountryArea::CHINA<<"km^2"<<std::endl;
    std::cout<<"한국 면적: "<<CountryArea::KOREA<<"km^2"<<std::endl;
    return 0;
}