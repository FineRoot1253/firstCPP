#ifndef FIRSTCPP_POINTMULTIPLEOVERLOADING _H
#define FIRSTCPP_POINTMULTIPLEOVERLOADING _H
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
    Point operator*(int times){
        Point pos(xpos * times, ypos * times);
        return pos;
    }

};
#endif // FIRSTCPP_POINTMULTIPLEOVERLOADING _H

