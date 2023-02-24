#include "enthusiasm/polymorphism/ObjectPointer.h"

int main(){
    Person* person = new Student();
    Person* person1 = new PartTimeStudent();
    Student* person2 = new PartTimeStudent();
    person->sleep();
    person1->sleep();
    person2->study();
    delete person;
    delete person1;
    delete person2;
    return 0;
}


