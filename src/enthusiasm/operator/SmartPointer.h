#ifndef FIRSTCPP_SMARTPOINTER _H
#define FIRSTCPP_SMARTPOINTER _H
#include <iostream>

class Point{
private:
    int xpos;
    int ypos;
public:
    Point(int x= 0, int y= 0):xpos(x), ypos(y){
        std::cout<<"Point 객체 생성"<<std::endl;
    }

    ~Point(){
        std::cout<<"Point 객체 소멸"<<std::endl;
    }

    void setPosition(int x, int y){
        xpos = x;
        ypos = y;
    }

    friend std::ostream& operator<<(std::ostream&, const Point&);
};
std::ostream& operator<<(std::ostream& output, const Point& ref){
    output<<"["<<ref.xpos<<", "<<ref.ypos<<"]"<<std::endl;
    return output;
}

class SmartPtr{
private:
    Point* point;
public:
    SmartPtr(Point* point):point(point){};
    ~SmartPtr(){
        delete point;
    }
    Point& operator*()const{
        return *point;
    }

    Point* operator->()const{
        return point;
    }
};
#endif // FIRSTCPP_SMARTPOINTER _H

