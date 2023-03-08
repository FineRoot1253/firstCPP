#include "enthusiasm/polymorphism/EmployeeManager3.h"

int main(){
    EmployeeHandler handler;

    handler.addEmployee(new PermanentWorker("KIM", 1000));
    handler.addEmployee(new PermanentWorker("LEE", 1500));

    TemporaryWorker* partTimeWorker = new TemporaryWorker("Jung", 700);
    partTimeWorker->addWorkTime(5);
    handler.addEmployee(partTimeWorker);


    SalesWorker* salesWorker = new SalesWorker("Hong", 1000, 0.1);
    salesWorker->addSaleResult(7000);
    handler.addEmployee(salesWorker);

    handler.showAllSalaryInfo();

    handler.showTotalSalaryInfo();
    return 0;
}