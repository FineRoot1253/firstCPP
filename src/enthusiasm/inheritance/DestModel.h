#ifndef FIRSTCPP_DESTMODEL _H
#define FIRSTCPP_DESTMODEL _H
#include <cstring>
#include <iostream>

class Person {
private:
    char* name;
public:
    Person(char *name) {
        this->name = new char[std::strlen(name)+1];
        std::strcpy(this->name, name);
    }
    ~Person(){
        delete []name;
    }

    void whatYourName() {
        std::cout << "My name is " << name << std::endl;
    }
};

class UniversityStudent : public Person {
private:
    char *major;
public:
    UniversityStudent(char *name, char *major)
            : Person(name) {
        this->major = new char[std::strlen(major)+1];
        std::strcpy(this->major, major);
    }

    void whoAreYou() {
        whatYourName();
        std::cout << "My major is " << major << std::endl<<std::endl;
    }
};
#endif // FIRSTCPP_DESTMODEL _H

