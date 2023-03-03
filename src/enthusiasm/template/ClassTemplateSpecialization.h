#ifndef FIRSTCPP_CLASSTEMPLATESPECIALIZATION _H
#define FIRSTCPP_CLASSTEMPLATESPECIALIZATION _H

#include <iostream>

template <class T>
class Point{
private:
    T xpos;
    T ypos;
public:
    Point(T x= 0, T y= 0);

    void showPosition() const;
};

template <class T>
Point<T>::Point(T x, T y) :xpos(x), ypos(y) {}

template <class T>
void Point<T>::showPosition()const{
    std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
}

template <class T>
class SimpleDataWrapper{
private:
    T data;
public:
    SimpleDataWrapper(T data):data(data){}

    void showDataInfo() const{
        std::cout<<"Data: "<<data<<std::endl;
    }
};

template <>
class SimpleDataWrapper<char *>{
private:
    char * data;
public:
    SimpleDataWrapper(char * data) {
        this->data = new char[std::strlen(data)+1];
        std::strcpy(this->data, data);
    }

    void showDataInfo() const{
        std::cout<<"String: "<<data<<std::endl;
        std::cout<<"Length: "<<std::strlen(data)<<std::endl;
    }

    ~SimpleDataWrapper(){
        delete[] data;
    }
};

template <>
class SimpleDataWrapper<Point<int>>{
private:
    Point<int> data;
public:
    SimpleDataWrapper(int x, int y) : data(x, y) {
    }

    void showDataInfo() const{
        data.showPosition();
    }
};

#endif // FIRSTCPP_CLASSTEMPLATESPECIALIZATION _H

