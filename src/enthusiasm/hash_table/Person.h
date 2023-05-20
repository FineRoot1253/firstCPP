가#ifndef FIRSTCPP_PERSON _H
#define FIRSTCPP_PERSON _H

#include <string>
#include <utility>
#include <iostream>

namespace Enthusiasm{
    namespace HashTable{
        class Person{
        private:
            int residentRegistrationNumber;
            std::string name;
            std::string address;
        public:
            Person();
            Person(const int& residentRegistrationNumber, std::string name, std::string address);
            Person(const Person& ref);
            Person(Person&& ref) noexcept;
            Person& operator=(const Person& ref) = default;
            Person& operator=(Person&& ref) noexcept;
            ~Person() = default;

        public:
            int getResidentRegistrationNumber() const;
            friend std::ostream &operator<<(std::ostream& os, const Person& person);
        };

        Person::Person()
        : residentRegistrationNumber(0){
        }

        Person::Person(const int& residentRegistrationNumber, std::string name, std::string address)
        : residentRegistrationNumber(residentRegistrationNumber)
        , name(name)
        , address(address){
        }

        Person::Person(const Enthusiasm::HashTable::Person &ref)
        : residentRegistrationNumber(ref.residentRegistrationNumber)
        , name(ref.name)
        , address(ref.address){
        }

        Person::Person(Enthusiasm::HashTable::Person &&ref) noexcept
        : residentRegistrationNumber(ref.residentRegistrationNumber)
        , name(std::move(ref.name))
        , address(std::move(ref.address)){
        }

        Person &Person::operator=(Enthusiasm::HashTable::Person &&ref) noexcept {
            residentRegistrationNumber = ref.residentRegistrationNumber;
            name = std::move(ref.name);
            address = std::move(ref.address);
            return *this;
        }

        int Person::getResidentRegistrationNumber() const {
            return residentRegistrationNumber;
        }

        std::ostream &operator<<(std::ostream &os, const Person &person) {
            os<<"이름: "<<person.name << std::endl;
            os<<"주민등록번호: "<<person.residentRegistrationNumber << std::endl;
            os<<"주소: "<<person.address << std::endl;
            return os;
        }
    }
}

#endif // FIRSTCPP_PERSON _H

