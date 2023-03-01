#include "enthusiasm/operator/StablePointObjArray.h"

int main(){
    BoundCheckIntArray arr(3);
    arr[0] = Point(3, 4);
    arr[1] = Point(4, 5);
    arr[2] = Point(5, 6);
    for (int i = 0; i < arr.getLength(); ++i) {
        std::cout<<arr[i];
    }
    return 0;
}


