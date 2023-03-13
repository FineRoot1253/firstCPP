#ifndef FIRSTCPP_BSWORSTOPCOUNT _H
#define FIRSTCPP_BSWORSTOPCOUNT _H
#include <iostream>

int bSearch(const int arr[], int length, int target) {
    int first = 0;
    int last = length - 1;
    int mid;
    int opCount = 0;

    while(first <= last){
        mid = (first + last) / 2;

        if(target == arr[mid]){
            return mid;
        }else{
            if(target < arr[mid]){
                last = mid - 1;
            }else{
                first = mid + 1;
            }
        }
        ++opCount;
    }
    std::cout<<"비교연산횟수: "<<opCount<<std::endl;
    return -1;
}
#endif // FIRSTCPP_BSWORSTOPCOUNT _H

