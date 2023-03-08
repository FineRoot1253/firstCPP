#ifndef FIRSTCPP_FIRSTOPERATIONOVERLOADING _H
#define FIRSTCPP_FIRSTOPERATIONOVERLOADING _H
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

    Point operator+(const Point &ref){
        Point pos(xpos+ref.xpos, ypos+ref.ypos);
        return pos;
    }
};
#endif // FIRSTCPP_FIRSTOPERATIONOVERLOADING _H