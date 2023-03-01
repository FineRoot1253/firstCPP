#ifndef FIRSTCPP_ONEOPNOVERLOADING _H
#define FIRSTCPP_ONEOPNOVERLOADING _H
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
    Point& operator++(){
        ++xpos;
        ++ypos;
        return *this;
    }

    friend Point &operator--(Point &ref);
};

Point& operator--(Point &ref){
    --ref.xpos;
    --ref.ypos;
    return ref;
}
#endif // FIRSTCPP_ONEOPNOVERLOADING _H

