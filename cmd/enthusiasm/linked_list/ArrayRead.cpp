//
// Created by 홍준근 on 2023/03/18.
//

#include <iostream>

int main(){
    int arr[10];
    int readCount = 0;
    int readData;
    int i;

    while(true){
        std::cout<<"자연수 입력: ";
        std::cin>>readData;
        if(readData < 1){
            break;
        }

        arr[readCount++] = readData;
    }

    for (int j = 0; j < readCount; ++j) {
        std::cout<<arr[j]<<" ";
    }

    return 0;
}