#include "enthusiasm/operator/NewDeleteOverloading.h"

int main(){
    Point * point = new Point(3, 4);
    std::cout<<*point;
    delete point;
    return 0;
}