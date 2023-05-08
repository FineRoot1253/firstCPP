#ifndef FIRSTCPP_RECURSIVEBINARYSEARCH _H
#define FIRSTCPP_RECURSIVEBINARYSEARCH _H

int binarySearchRecursive(int array[], int first, int last, int target){
    int middle;
    if(first > last){
        return -1;
    }

    middle = (first + last) / 2;

    if(array[middle] == target){
        return middle;
    }else if(array[middle] > target){
        return binarySearchRecursive(array, first, middle - 1, target);
    }else{
        return binarySearchRecursive(array, middle, last, target);
    }

}

#endif // FIRSTCPP_RECURSIVEBINARYSEARCH _H

