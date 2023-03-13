#ifndef FIRSTCPP_BINARYSEARCH _H
#define FIRSTCPP_BINARYSEARCH _H
#include <iostream>

int bSearch(const int arr[], int length, int target) {
    int first = 0;
    int last = length - 1;
    int mid;

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
    }
    return -1;
}
#endif // FIRSTCPP_BINARYSEARCH _H

