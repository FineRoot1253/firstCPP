#ifndef FIRSTCPP_EMPLOYEEMANAGER4 _H
#define FIRSTCPP_EMPLOYEEMANAGER4 _H
#include <cstring>
#include <iostream>

class Employee{
private:
    char name[100];
public:
    Employee(char *name){
        std::strcpy(this->name, name);
    }

    virtual void showYourName() const {
        std::cout<<"name: "<< name <<std::endl;
    }

    virtual int getPay() const {
        return 0;
    };

    virtual void showSalaryInfo() const {
    }
};

class PermanentWorker :public Employee{
private:
    int salary;
public:
    PermanentWorker(char *name, int salary)
            : Employee(name), salary(salary) {
    }

    int getPay() const override {
        return salary;
    }

    void showSalaryInfo() const override {
        showYourName();
        std::cout << "salary: " << salary << std::endl<<std::endl;
    }
};

class TemporaryWorker :public Employee{
private:
    int payPerHour;
    int workTime;
public:
    TemporaryWorker(char *name, int payPerHour)
            : Employee(name), payPerHour(payPerHour), workTime(0) {
    }

    void addWorkTime(int value){
        workTime += value;
    }

    int getPay() const override {
        return payPerHour * workTime;
    }

    void showSalaryInfo() const override {
        showYourName();
        std::cout << "salary: " << getPay() << std::endl<<std::endl;
    }
};

class SalesWorker :public PermanentWorker{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(char *name, int salary, double bonusRatio)
            : PermanentWorker(name, salary), salesResult(0), bonusRatio(bonusRatio) {
    }

    void addSaleResult(int value){
        salesResult+=value;
    }

    int getPay() const override {
        return PermanentWorker::getPay() + (int)(salesResult * bonusRatio);
    }

    void showSalaryInfo() const override {
        showYourName();
        std::cout << "salary: " << getPay() << std::endl<<std::endl;
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
#endif // FIRSTCPP_EMPLOYEEMANAGER4 _H

