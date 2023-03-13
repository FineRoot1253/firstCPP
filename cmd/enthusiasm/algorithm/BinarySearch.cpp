#include "enthusiasm/algorithm/BinarySearch.h"

int main(){
    int array[] = {1, 3, 5, 7, 9};
    int result = bSearch(array, sizeof(array) / sizeof(int), 7);

    if(result == -1){
        std::cout<<"탐색 실패!"<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    result = bSearch(array, sizeof(array) / sizeof(int), 4);

    if(result == -1){
        std::cout<<"탐색 실패!"<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }
    return 0;
}


