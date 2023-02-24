#ifndef FIRSTCPP_EMPLOYEEMANAGER1 _H
#define FIRSTCPP_EMPLOYEEMANAGER1 _H

#include <cstring>
#include <iostream>

class PermanentWorker {
private:
    char name[100];
    int salary;
public:
    PermanentWorker(char *name, int salary)
            : salary(salary) {
        std::strcpy(this->name, name);
    }

    int getPay() const {
        return salary;
    }

    void showSalaryInfo() const {
        std::cout << "name: " << name << std::endl;
        std::cout << "salary: " << salary << std::endl<<std::endl;
    }
};

class EmployeeHandler {
private:
    PermanentWorker *employeeList[100];
    int employeeCount;
public:
    EmployeeHandler()
            : employeeCount(0) {};

    ~EmployeeHandler() {
        for (int i = 0; i < employeeCount; ++i) {
            delete employeeList[i];
        }
    }

    void addEmployee(PermanentWorker *employee) {
        employeeList[employeeCount] = employee;
        ++employeeCount;
    };

    void showAllSalaryInfo() const {
        for (int i = 0; i < employeeCount; ++i) {
            employeeList[i]->showSalaryInfo();
        }
    };

    void showTotalSalaryInfo() const {
        int sum = 0;
        for (int i = 0; i < employeeCount; ++i) {
            sum += employeeList[i]->getPay();
        }
        std::cout << "salary sum: " << sum << std::endl;
    };

};

#endif // FIRSTCPP_EMPLOYEEMANAGER1 _H

