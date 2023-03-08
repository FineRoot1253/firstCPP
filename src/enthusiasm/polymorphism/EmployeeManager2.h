#ifndef FIRSTCPP_EMPLOYEEMANAGER2 _H
#define FIRSTCPP_EMPLOYEEMANAGER2 _H
#include <cstring>
#include <iostream>

class Employee{
private:
    char name[100];
public:
    Employee(char *name){
        std::strcpy(this->name, name);
    }

    void showYourName() const {
        std::cout<<"name: "<< name <<std::endl;
    }
};

class PermanentWorker :public Employee{
private:
    int salary;
public:
    PermanentWorker(char *name, int salary)
            : Employee(name), salary(salary) {
    }

    int getPay() const {
        return salary;
    }

    void showSalaryInfo() const {
        showYourName();
        std::cout << "salary: " << salary << std::endl<<std::endl;
    }
};

class EmployeeHandler {
private:
    Employee *employeeList[100];
    int employeeCount;
public:
    EmployeeHandler()
            : employeeCount(0) {};

    ~EmployeeHandler() {
        for (int i = 0; i < employeeCount; ++i) {
            delete employeeList[i];
        }
    }

    void addEmployee(Employee *employee) {
        employeeList[employeeCount] = employee;
        ++employeeCount;
    };

    void showAllSalaryInfo() const {
//        for (int i = 0; i < employeeCount; ++i) {
//            employeeList[i]->showSalaryInfo();
//        }
    };

    void showTotalSalaryInfo() const {
        int sum = 0;
//        for (int i = 0; i < employeeCount; ++i) {
//            sum += employeeList[i]->getPay();
//        }
        std::cout << "salary sum: " << sum << std::endl;
    };
};
#endif // FIRSTCPP_EMPLOYEEMANAGER2 _H

