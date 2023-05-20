#ifndef FIRSTCPP_INTERPOLATIONSEARCH _H
#define FIRSTCPP_INTERPOLATIONSEARCH _H

namespace Search{
    int interpolationSearch(int array[], int first, int last, int target){
        int middle;

        if(first > last){
            return -1;
        }

        middle = ((double)(target - array[first]) / (array[last] - array[first]) * (last - first) + first);

        if(array[middle] == target){
            return middle;
        }else if(array[middle] > target){
            return interpolationSearch(array, first, middle - 1, target);
        }else{
            return interpolationSearch(array, middle, last, target);
        }
    }
}

#endif // FIRSTCPP_INTERPOLATIONSEARCH _H

