#include "enthusiasm/exception/ReThrow.h"

int main(){
    try{
        divide(9, 2);
        divide(4, 0);
    }catch(int ex){
        std::cout<<"second catch"<<std::endl;
    }
    return 0;
}


