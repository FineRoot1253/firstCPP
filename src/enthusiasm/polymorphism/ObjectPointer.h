#ifndef FIRSTCPP_OBJECTPOINTER _H
#define FIRSTCPP_OBJECTPOINTER _H
#include <cstring>
#include <iostream>

class Person {
public:
    void sleep() {
        std::cout << "sleep" << std::endl;
    }
};

class Student : public Person {
public:
    void study() {
        std::cout << "study" << std::endl;
    }
};

class PartTimeStudent : public Student {
public:
    void work() {
        std::cout << "work" << std::endl;
    }
};
#endif // FIRSTCPP_OBJECTPOINTER _H

