#include "enthusiasm/algorithm/LinearSearch.h"

int main(){
    int array[] = {3, 5, 2, 4, 9};

    int result = lSearch(array, sizeof(array) / sizeof(int), 4);

    if(result == -1){
        std::cout<<"탐색 실패!"<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    result = lSearch(array, sizeof(array) / sizeof(int), 7);

    if(result == -1){
        std::cout<<"탐색 실패!"<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    return 0;
}


