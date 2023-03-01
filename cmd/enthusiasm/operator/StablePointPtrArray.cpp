#include "enthusiasm/operator/StablePointPtrArray.h"

int main(){
    BoundCheckIntArray array(3);
    array[0] = new Point(3, 4);
    array[1] = new Point(5, 6);
    array[2] = new Point(7, 8);
    for (int i = 0; i < array.getLength(); ++i) {
        std::cout<<*array[i];
    }
    delete array[0];
    delete array[1];
    delete array[2];
    return 0;
}