#include "enthusiasm/hash_table/UnderstandTable.h"

using namespace Collection::Table;

int main(){
    EmployeeInfo employeeInfoArray[1000];
    EmployeeInfo input;

    int employeeNumber;

    std::cout<<"사번과 나이 입력: ";
    std::cin>>input;
    employeeInfoArray[input.getEmployeeNumber()] = input;

    std::cout<<"확인하려는 직원의 사번 입력: ";
    std::cin>>employeeNumber;

    std::cout<<employeeInfoArray[employeeNumber]<<std::endl;
    return 0;
}


