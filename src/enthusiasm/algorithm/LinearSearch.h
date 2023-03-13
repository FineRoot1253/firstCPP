#ifndef FIRSTCPP_LINEARSEARCH _H
#define FIRSTCPP_LINEARSEARCH _H

#include <iostream>

int lSearch(const int array[], int length, int target){
    for (int index = 0; index < length; ++index) {
        if(array[index] == target){
            return index;
        }
    }
    return -1;
}
#endif // FIRSTCPP_LINEARSEARCH _H

