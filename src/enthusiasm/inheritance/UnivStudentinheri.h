#ifndef FIRSTCPP_UNIVSTUDENTINHERI _H
#define FIRSTCPP_UNIVSTUDENTINHERI _H

#include <cstring>
#include <iostream>

class Person {
private:
    int age;
    char name[50];
public:
    Person(char *name, int age)
            : age(age) {
        std::strcpy(this->name, name);
    }

    void whatYourName() {
        std::cout << "My name is " << name << std::endl;
    }

    void howOldAreYou() {
        std::cout << "I'm " << age << " years old." << std::endl;
    }
};

class UniversityStudent : public Person {
private:
    char major[50];
public:
    UniversityStudent(char *name, int age, char *major)
            : Person(name, age) {
        std::strcpy(this->major, major);
    }

    void whoAreYou() {
        whatYourName();
        howOldAreYou();
        std::cout << "My major is " << major << std::endl<<std::endl;
    }
};

#endif // FIRSTCPP_UNIVSTUDENTINHERI _H

