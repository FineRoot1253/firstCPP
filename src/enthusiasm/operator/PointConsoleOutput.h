#ifndef FIRSTCPP_POINTCONSOLEOUTPUT _H
#define FIRSTCPP_POINTCONSOLEOUTPUT _H
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

    friend std::ostream& operator<<(std::ostream&, const Point&);
};
std::ostream& operator<<(std::ostream& output, const Point& ref){
    output<<"["<<ref.xpos<<", "<<ref.ypos<<"]"<<std::endl;
    return output;
}
#endif // FIRSTCPP_POINTCONSOLEOUTPUT _H

