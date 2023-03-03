#ifndef FIRSTCPP_CLASSTEMPLATEPARTIALSPECIALIZATION _H
#define FIRSTCPP_CLASSTEMPLATEPARTIALSPECIALIZATION _H
#include <iostream>

template <class T1, class T2>
class MySimple{
public:
    void whoAreYou(){
        std::cout<<"size of T1: "<<sizeof(T1)<<std::endl;
        std::cout<<"size of T2: "<<sizeof(T2)<<std::endl;
        std::cout<<"<class T1, class T2>"<<std::endl;
    }
};

template <>
class MySimple<int, double>{
public:
    void whoAreYou(){
        std::cout<<"size of int: "<<sizeof(int)<<std::endl;
        std::cout<<"size of double: "<<sizeof(double)<<std::endl;
        std::cout<<"<class int, class double>"<<std::endl;
    }
};

//부분 특수화
//template <class T1>
//class MySimple<T1, double>{
//public:
//    void whoAreYou(){
//        std::cout<<"size of int: "<<sizeof(int)<<std::endl;
//        std::cout<<"size of double: "<<sizeof(double)<<std::endl;
//        std::cout<<"<class int, class double>"<<std::endl;
//    }
//};

#endif // FIRSTCPP_CLASSTEMPLATEPARTIALSPECIALIZATION _H

