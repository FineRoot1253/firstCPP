#include "enthusiasm/exception/CatchList.h"

int main(){
    char str1[100];
    char str2[100];

    while(true){
        std::cout<<"두 개의 숫자 입력: ";
        std::cin>>str1>>str2;

        try{
            std::cout<<str1<<" + "<<str2<<" = "<<sToI(str1)+sToI(str2)<<std::endl;
            break;
        }catch (char e){
            std::cout<<"문자 "<<e<<"가 입력되었습니다."<<std::endl;
            std::cout<<"재입력을 진행합니다."<<std::endl;
        }catch (int e){
            if(e == 0){
                std::cout<<"0으로 시작하는 숫자는 입력불가."<<std::endl;
            }else{
                std::cout<<"비정상적입력이 이루어졌습니다."<<std::endl;
            }
            std::cout<<"재입력을 진행합니다."<<std::endl;
        }
    }
    std::cout<<"프로그램을 종료합니다."<<std::endl;
    return 0;
}


