#include "enthusiasm/polymorphism/EmployeeManager2.h"

int main(){
    EmployeeHandler handler;

    handler.addEmployee(new PermanentWorker("KIM", 1000));
    handler.addEmployee(new PermanentWorker("LEE", 1500));
    handler.addEmployee(new PermanentWorker("JUN", 2000));

    handler.showAllSalaryInfo();

    handler.showTotalSalaryInfo();
    return 0;
}


