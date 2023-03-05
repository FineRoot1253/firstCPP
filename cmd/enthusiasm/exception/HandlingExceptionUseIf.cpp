#include <iostream>

int main(){
    int num1;
    int num2;
    std::cout<<"두 개의 숫자 입력: ";
    std::cin>>num1>>num2;
    if (num2 <=0){
        std::cout<<"제수는 0이 될 수 없습니다."<<std::endl;
        std::cout<<"프로그램을 다시 실행하세요."<<std::endl;
    }else{
        std::cout<<"나눗셈의 몫: "<<num1/num2<<std::endl;
        std::cout<<"나눗셈의 나머지: "<<num1%num2<<std::endl;
    }
    return 0;
}


