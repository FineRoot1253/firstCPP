#ifndef FIRSTCPP_RECURSIVEBINARYSEARCH _H
#define FIRSTCPP_RECURSIVEBINARYSEARCH _H
#include <iostream>

int bSearchRecursive(int arr[], int firstIndex, int lastIndex, int target){
    int mid;
    if(firstIndex > lastIndex){
        return -1;
    }

    mid = (firstIndex + lastIndex)/ 2;

    if(arr[mid] == target){
        return mid;
    }else if (target < arr[mid]){
        return bSearchRecursive(arr, firstIndex, lastIndex -1, target);
    }else{
        return bSearchRecursive(arr, firstIndex+1, lastIndex, target);
    }
}
#endif // FIRSTCPP_RECURSIVEBINARYSEARCH _H

