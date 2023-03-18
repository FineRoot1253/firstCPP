#include "enthusiasm/recursive/RecursiveBinarySearch.h"

int main(){
    int array[] = {1, 3, 5, 7, 9};
    int result = bSearchRecursive(array,0, sizeof(array) / sizeof(int) -1, 7);

    if(result == -1){
        std::cout<<"탐색 실패!"<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }

    result = bSearchRecursive(array, 0, sizeof(array) / sizeof(int)-1, 4);

    if(result == -1){
        std::cout<<"탐색 실패!"<<std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<result<<std::endl;
    }
    return 0;
}


