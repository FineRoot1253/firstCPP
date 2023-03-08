#include "enthusiasm/operator/PostOpndOverloading.h"

int main(){
    Point pos(3,5);
    Point copy;
    copy = pos--;
    copy.showPosition();
    pos.showPosition();

    copy = pos++;
    copy.showPosition();
    pos.showPosition();
    return 0;
}
