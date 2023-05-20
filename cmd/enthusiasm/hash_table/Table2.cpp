#include "enthusiasm/hash_table/Table2.h"
#include "enthusiasm/hash_table/Person.h"

using namespace Enthusiasm::HashTable;

int myHashFunction(const int& key){
    return key % 100;
}

int main(){
    Table2<Person> table = Table2<Person>(myHashFunction);

    Person *person1 = new Person(900254, "LEE", "Seoul");
    Person *person2 = new Person(900139, "KIM", "Jeju");
    Person *person3 = new Person(900827, "HAN", "Kangwon");

    table.insert(person1->getResidentRegistrationNumber(),person1);
    table.insert(person2->getResidentRegistrationNumber(),person2);
    table.insert(person3->getResidentRegistrationNumber(),person3);

    Person *resultPerson1 = table.search(900254);
    if(resultPerson1 != nullptr){
        std::cout<<*resultPerson1<<std::endl;
    }
    Person *resultPerson2 = table.search(900139);
    if(resultPerson2 != nullptr){
        std::cout<<*resultPerson2<<std::endl;
    }
    Person *resultPerson3 = table.search(900827);
    if(resultPerson3 != nullptr){
        std::cout<<*resultPerson3<<std::endl;
    }

    delete person1;
    delete person2;
    delete person3;
    return 0;
}


