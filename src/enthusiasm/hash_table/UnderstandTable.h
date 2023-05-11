#ifndef FIRSTCPP_UNDERSTANDTABLE _H
#define FIRSTCPP_UNDERSTANDTABLE _H

#include <iostream>

namespace Collection {
    namespace Table {
        class EmployeeInfo {
        private:
            long employeeNumber;
            std::string name;
            int age;
        public:
            EmployeeInfo();

            EmployeeInfo(const long &employeeNumber, const std::string name, const int &age);

            EmployeeInfo(const EmployeeInfo &ref);

            EmployeeInfo(EmployeeInfo &&ref) noexcept;

            EmployeeInfo &operator=(const EmployeeInfo &ref);

            EmployeeInfo &operator=(EmployeeInfo &&ref) noexcept;

            ~EmployeeInfo() = default;

            friend std::ostream &operator<<(std::ostream &os, const EmployeeInfo &info);

            friend std::istream &operator>>(std::istream &os, EmployeeInfo &info);

        public:
            int getEmployeeNumber() const;
        };

        EmployeeInfo::EmployeeInfo()
                : employeeNumber(0)
                  , age(0) {
        }

        EmployeeInfo::EmployeeInfo(
                const long &employeeNumber,
                const std::string name,
                const int &age)
                : employeeNumber(employeeNumber)
                  , name(name)
                  , age(age) {
        }

        EmployeeInfo::EmployeeInfo(
                const Collection::Table::EmployeeInfo &ref)
                : employeeNumber(ref.employeeNumber)
                  , name(ref.name)
                  , age(ref.age) {
        }

        EmployeeInfo::EmployeeInfo(Collection::Table::EmployeeInfo &&ref)
        noexcept {
            employeeNumber = ref.employeeNumber;
            name = ref.name;
            age = ref.age;
        }

        EmployeeInfo &EmployeeInfo::operator=(const Collection::Table::EmployeeInfo &ref) {
            employeeNumber = ref.employeeNumber;
            name = ref.name;
            age = ref.age;
            return *this;
        }

        EmployeeInfo &EmployeeInfo::operator=(Collection::Table::EmployeeInfo &&ref) noexcept {
            employeeNumber = ref.employeeNumber;
            name = ref.name;
            age = ref.age;
            return *this;
        }


        std::ostream &operator<<(std::ostream &os, const EmployeeInfo &info) {
            os << "사번: " << info.employeeNumber << ", 이름: " << info.name << ", 나이: " << info.age;
            return os;
        }

        std::istream &operator>>(std::istream &is, EmployeeInfo &info) {
            is >> info.employeeNumber;
            is >> info.age;
            is >> info.name;
            return is;
        }

        int EmployeeInfo::getEmployeeNumber() const {
            return employeeNumber;
        }
    }
}
#endif // FIRSTCPP_UNDERSTANDTABLE _H

