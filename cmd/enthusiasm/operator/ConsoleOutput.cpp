#include "enthusiasm/operator/ConsoleOutput.h"

int main(){
    MySTD::cout<<"Simple String";
    MySTD::cout<<MySTD::endl;
    MySTD::cout<<3.14;
    MySTD::cout<<MySTD::endl;
    MySTD::cout<<123;
    MySTD::endl(MySTD::cout);
    std::endl(std::cout);
    return 0;
}