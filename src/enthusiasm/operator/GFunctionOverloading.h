#ifndef FIRSTCPP_GFUNCTIONOVERLOADING _H
#define FIRSTCPP_GFUNCTIONOVERLOADING _H
#include <iostream>

class Point{
private:
    int xpos;
    int ypos;
public:
    Point(int x= 0, int y= 0):xpos(x), ypos(y){}

    void showPosition() const {
        std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
    }


    friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

#endif // FIRSTCPP_GFUNCTIONOVERLOADING _H

