#include "enthusiasm/algorithm/BSWorstOpCount.h"

int main(){
    int arr1[500] = {0,};
    int arr2[5000] = {0,};
    int arr3[50000] = {0,};
    int result;

    result = bSearch(arr1,sizeof(arr1)/sizeof(int), 1);

    if(result == -1){
        std::cout<<"탐색 실패"<<std::endl<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    result = bSearch(arr2,sizeof(arr2)/sizeof(int), 2);

    if(result == -1){
        std::cout<<"탐색 실패"<<std::endl<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    result = bSearch(arr3,sizeof(arr3)/sizeof(int), 3);

    if(result == -1){
        std::cout<<"탐색 실패"<<std::endl<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    return 0;
}


