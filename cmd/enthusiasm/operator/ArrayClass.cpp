#include "enthusiasm/operator/ArrayClass.h"

int main(){
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; ++i) {
        arr[i] = (i+1)*11;
    }
    for (int i = 0; i < 6; ++i) {
        std::cout<<arr[i]<<std::endl;
    }
    return 0;
}


