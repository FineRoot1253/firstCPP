#include "enthusiasm/exception/ATMSim.h"

int main(){
    Account myAccount("123456-123456", 5000);

    try{
        myAccount.deposit(2000);
        myAccount.deposit(-300);
    }catch (DepositException &ex){
        ex.showExceptionMessage();
    }
    myAccount.showMoney();

    try{
        myAccount.withdraw(3500);
        myAccount.withdraw(4500);
    }catch (WithdrawException &ex){
        ex.showExceptionMessage();
    }
    myAccount.showMoney();
    return 0;
}


