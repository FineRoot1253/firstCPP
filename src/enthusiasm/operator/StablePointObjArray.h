#ifndef FIRSTCPP_STABLEPOINTOBJARRAY _H
#define FIRSTCPP_STABLEPOINTOBJARRAY _H
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
class BoundCheckIntArray{
private:
    Point * arr;
    int length;
private:
    BoundCheckIntArray(const BoundCheckIntArray& ref){}
    BoundCheckIntArray& operator=(const BoundCheckIntArray& ref){}
public:
    BoundCheckIntArray(int length):length(length){
        arr = new Point[length];
    }

    ~BoundCheckIntArray(){
        delete []arr;
    }

    Point& operator[] (int index){
        if(index < 0 || index >= length){
            std::cout<<"Array index out of bound exception"<<std::endl;
            exit(1);
        }
        return arr[index];
    }

    Point operator[] (int index) const{
        if(index < 0 || index >= length){
            std::cout<<"Array index out of bound exception"<<std::endl;
            exit(1);
        }
        return arr[index];
    }

    int getLength() const {
        return length;
    }
};

void showAllData(const BoundCheckIntArray& ref){
    for (int i = 0; i < ref.getLength(); ++i) {
        std::cout<<ref[i]<<std::endl;
    }
}
#endif // FIRSTCPP_STABLEPOINTOBJARRAY _H

