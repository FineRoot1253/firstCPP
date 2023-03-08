#ifndef FIRSTCPP_FUNCTOR _H
#define FIRSTCPP_FUNCTOR _H
#include <iostream>

class Point{
private:
    int xpos;
    int ypos;
public:
    Point(int x= 0, int y= 0):xpos(x), ypos(y){
    }


    Point operator+(const Point& ref)const{
        return Point(xpos + ref.xpos, ypos + ref.ypos);
    }

    friend std::ostream& operator<<(std::ostream&, const Point&);
};
std::ostream& operator<<(std::ostream& output, const Point& ref){
    output<<"["<<ref.xpos<<", "<<ref.ypos<<"]"<<std::endl;
    return output;
}

class Adder{
public:
    int operator()(const int& num1, const int& num2){
        return num1 + num2;
    }

    double operator()(const double& e1, const double& e2){
        return e1 + e2;
    }

    Point operator()(const Point& point1, const Point& point2){
        return point1 + point2;
    }
};
#endif // FIRSTCPP_FUNCTOR _H

