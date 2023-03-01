#ifndef FIRSTCPP_POSTOPNDOVERLOADING _H
#define FIRSTCPP_POSTOPNDOVERLOADING _H
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

    const Point operator++(int){ // 후위
        const Point retobj(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return retobj;
    }

    friend Point &operator--(Point &ref);
    friend const Point operator--(Point &ref, int); // 후위
};

Point& operator--(Point &ref){
    --ref.xpos;
    --ref.ypos;
    return ref;
}

const Point operator--(Point &ref, int){
    const Point retobj(ref);
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
}
#endif // FIRSTCPP_POSTOPNDOVERLOADING _H

