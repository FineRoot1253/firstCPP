#include "enthusiasm/operator/PointMultipleOverloading.h"

int main(){
    Point pos(1,2);
    Point copy;
    copy = pos * 3;
    copy.showPosition();

    copy = pos * 3 * 2;
    copy.showPosition();
    return 0;
}