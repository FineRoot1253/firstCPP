#include "enthusiasm/hash_table/Table.h"

using namespace Enthusiasm::HashTable;

int myHashFunction(const int& key){
    return key % 100;
}

int main(){
    Table<Person> table = Table<Person>(myHashFunction);

    Person *person1 = new Person(20120003, "LEE", "Seoul");
    Person *person2 = new Person(20130012, "KIM", "Jeju");
    Person *person3 = new Person(20170049, "HAN", "Kangwon");

    table.insert(person1->getResidentRegistrationNumber(),person1);
    table.insert(person2->getResidentRegistrationNumber(),person2);
    table.insert(person3->getResidentRegistrationNumber(),person3);

    Person *resultPerson1 = table.search(20120003);
    if(person1 != nullptr){
        std::cout<<*person1<<std::endl;
    }
    Person *resultPerson2 = table.search(20130012);
    if(resultPerson2 != nullptr){
        std::cout<<*resultPerson2<<std::endl;
    }
    Person *resultPerson3 = table.search(20170049);
    if(resultPerson3 != nullptr){
        std::cout<<*resultPerson3<<std::endl;
    }

    delete person1;
    delete person2;
    delete person3;

    return 0;
}


