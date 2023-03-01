#ifndef FIRSTCPP_NEWDELETEOVERLOADING _H
#define FIRSTCPP_NEWDELETEOVERLOADING _H
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
    void* operator new(size_t size){
        std::cout<<"operator new: "<<size<<std::endl;
        void * addr = new char[size];
        return addr;
    }

    void operator delete(void * addr){
        std::cout<<"operator delete()"<<std::endl;
        delete []((char*)addr);
    }

    friend std::ostream& operator<<(std::ostream&, const Point&);
};
std::ostream& operator<<(std::ostream& output, const Point& ref){
    output<<"["<<ref.xpos<<", "<<ref.ypos<<"]"<<std::endl;
    return output;
}
#endif // FIRSTCPP_NEWDELETEOVERLOADING _H

