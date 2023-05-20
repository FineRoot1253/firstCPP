#include "enthusiasm/search/InterpolationSearch.h"
#include <iostream>

int main(){
    int array[] = {1, 3, 5, 7, 9};

    int index = Search::interpolationSearch(array, 0, 4, 7);
    if(index == -1) {
        std::cout << "탐색 실패!" << std::endl;
    }else{
        std::cout<<"타겟 저장 인덱스: "<<index<<std::endl;
    }
    return 0;
}


