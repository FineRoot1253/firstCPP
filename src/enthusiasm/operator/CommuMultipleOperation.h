#ifndef FIRSTCPP_COMMUMULTIPLEOPERATION _H
#define FIRSTCPP_COMMUMULTIPLEOPERATION _H
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

    friend Point operator*(int times, Point &ref);
};
Point operator*(int times, Point &ref){
    return ref * times;
}
#endif // FIRSTCPP_COMMUMULTIPLEOPERATION _H