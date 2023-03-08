#include "enthusiasm/operator/FirstOperationOverloading1.h"

int main(){
    First first(111, 222);
    First firstCopy ;
    Second second(333, 444);
    Second secondCopy;
    firstCopy = first;
    second = secondCopy;
    firstCopy.showData();
    secondCopy.showData();

    First first1;
    First first2;
    Second second1;
    Second second2;
    first1 = first2 = first;
    second1 = second2 = second;
    first1.showData();
    first2.showData();
    second1.showData();
    second2.showData();
    return 0;
}


