//
// Created by 홍준근 on 2023/05/08.
//
#include "enthusiasm/hash_table/UnderstandTable.h"

using namespace Collection::Table;

int getHashValue(int empNum){
    return empNum % 100;
}

int main(){
    EmployeeInfo employeeInfoArray[100];
    EmployeeInfo employeeInfo1 = {20120003,"홍준근", 27};
    EmployeeInfo employeeInfo2 = {20130012,"홍길동", 33};
    EmployeeInfo employeeInfo3 = {20170049,"홍진호", 42};

    EmployeeInfo result1;
    EmployeeInfo result2;
    EmployeeInfo result3;

    employeeInfoArray[getHashValue(employeeInfo1.getEmployeeNumber())] = employeeInfo1;
    employeeInfoArray[getHashValue(employeeInfo2.getEmployeeNumber())] = employeeInfo2;
    employeeInfoArray[getHashValue(employeeInfo3.getEmployeeNumber())] = employeeInfo3;

    result1 = employeeInfoArray[getHashValue(20120003)];
    result2 = employeeInfoArray[getHashValue(20130012)];
    result3 = employeeInfoArray[getHashValue(20170049)];

    std::cout<<result1<<std::endl;
    std::cout<<result2<<std::endl;
    std::cout<<result3<<std::endl;

    return 0;
}