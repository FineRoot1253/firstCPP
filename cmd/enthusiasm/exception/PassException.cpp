#include "enthusiasm/exception/PassException.h"

int main(){
    int num1;
    int num2;
    std::cout<<"두 개의 숫자 입력: ";
    std::cin>>num1>>num2;

    try{
        divide(num1, num2);
        std::cout<<"나눗셈을 마쳤습니다."<<std::endl;
    }catch(int e){
        std::cout<<"제수는 "<<e<<"이 될 수 없습니다."<<std::endl;
        std::cout<<"프로그램을 다시 실행하세요."<<std::endl;
    }
    return 0;
}


