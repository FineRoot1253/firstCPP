#include "enthusiasm/operator/ArrayNewDeleteOverloading.h"

int main(){
    Point * point = new Point(3, 4);
    Point* array = new Point[3];
    delete point;
    delete[] array;
    return 0;
}