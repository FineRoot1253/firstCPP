#ifndef FIRSTCPP_ASSIGNSHALLOWCOPYERROR _H
#define FIRSTCPP_ASSIGNSHALLOWCOPYERROR _H
#include <cstring>
#include <iostream>

class Person {
private:
    char* name;
    int age;
public:
    Person(char *name, int age):age(age) {
        this->name = new char[std::strlen(name)+1];
        std::strcpy(this->name, name);
    }
    ~Person(){
        delete []name;
        std::cout<<"called destructor!"<<std::endl;
    }

    void showPersonInfo() {
        std::cout<<"이름: "<<name<<std::endl;
        std::cout<<"나이: "<<age<<std::endl;
    }

    Person& operator=(const Person& ref){
        delete []name;
        name = new char(std::strlen(ref.name)+1);
        std::strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
};
#endif // FIRSTCPP_ASSIGNSHALLOWCOPYERROR _H

