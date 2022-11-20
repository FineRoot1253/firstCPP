//
// Created by 홍준근 on 2022/11/20.
//
#include <iostream>

void newAndDelete(){
    int* p = new int;
    *p = 10;

    std::cout << *p << std::endl;

    delete p;
}

// 참고로 arrSize에 & 연산자가 필요없는 이유는 알아서 레퍼런스로 참조 받기 때문이다.
void arrayWithNewAndDelete(){
    int arrSize;
    std::cout << "array size" << std::endl;
    std::cin >> arrSize;

    int* list = new int[arrSize];

    for(int i = 0; i<arrSize ; i++){
        std::cin >> list[i];
    }

    for(int i = 0; i<arrSize ; i++){
        std::cout<< i << "th element of list: " << list[i] << std::endl;
    }
    delete[] list;
}


int main(){
    newAndDelete();
    arrayWithNewAndDelete();
    return 0;
}

