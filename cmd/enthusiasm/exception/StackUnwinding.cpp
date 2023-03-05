#include "enthusiasm/exception/StackUnwinding.h"

int main(){
    try{
        simpleFuncOne();
    }catch (int e){
        std::cout<<"에외코드: "<<e<<std::endl;
    }
    return 0;
}