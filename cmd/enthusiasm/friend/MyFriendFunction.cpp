#include "enthusiasm/friend/MyFriendFunction.h"

int main(){
    Point pos1(1,2);
    Point pos2(2,4);
    PointOperation op;

    showPointPos(op.addPoint(pos1, pos2));
    showPointPos(op.subPoint(pos1, pos2));
    return 0;
}


