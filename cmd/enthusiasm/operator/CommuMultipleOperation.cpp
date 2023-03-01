#include "enthusiasm/operator/CommuMultipleOperation.h"

int main(){
    Point pos(1,2);
    Point copy;
    copy = pos * 3;
    copy.showPosition();

    copy = 2 * pos * 3;
    copy.showPosition();
    return 0;
}