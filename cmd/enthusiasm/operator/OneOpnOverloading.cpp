#include "enthusiasm/operator/OneOpnOverloading.h"

int main(){
    Point pos(1,2);
    ++pos;
    pos.showPosition();
    --pos;
    pos.showPosition();

    ++(++pos);
    pos.showPosition();
    --(--pos);
    pos.showPosition();
    return 0;
}


