#include "enthusiasm/operator/StableConstArrayProb.h"

int main(){
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; ++i) {
        arr[i]=(i+1)*11;
    }
    showAllData(arr);
    return 0;
}


