#include "enthusiasm/operator/InheritAssignOperation.h"

int main(){
    Second second(111, 222, 333, 444);
    Second secondCopy(0,0,0,0);
    secondCopy = second;
    secondCopy.showData();
    return 0;
}


