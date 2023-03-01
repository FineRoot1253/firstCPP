#ifndef FIRSTCPP_IMPROVEINIT _H
#define FIRSTCPP_IMPROVEINIT _H
#include <iostream>

class Fruit{
private:
    int num;
public:
    Fruit(int num = 0):num(num){
        std::cout<<"Fruit(int num = 0)"<<std::endl;
    };

    Fruit(const Fruit& ref): num(ref.num){
        std::cout<<"Fruit(const Fruit& ref)"<<std::endl;
    }
    Fruit& operator=(const Fruit& ref){
        num = ref.num;
        std::cout<<"operator=(const Fruit& ref)"<<std::endl;
        return *this;
    }
};

class Apple{
private:
    Fruit mem;
public:
    Apple(const Fruit& ref):mem(ref){}
};

class Banana{
private:
    Fruit mem;
public:
    Banana(const Fruit& ref){
        mem = ref;
    }
};
#endif // FIRSTCPP_IMPROVEINIT _H