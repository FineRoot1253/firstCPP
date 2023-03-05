#ifndef FIRSTCPP_ATMSIM _H
#define FIRSTCPP_ATMSIM _H
#include <iostream>
#include <string>
#include <utility>

class DepositException{
private:
    int requireDepositAmount;
public:
    DepositException(int requireDepositAmount) : requireDepositAmount(requireDepositAmount){}

    void showExceptionMessage(){
        std::cout<<"[예외 메시지: "<<requireDepositAmount<<"는 입금 불가]"<<std::endl;
    }
};

class WithdrawException{
private:
    int requireWithdrawAmount;
public:
    WithdrawException(int requireWithdrawAmount):requireWithdrawAmount(requireWithdrawAmount){}

    void showExceptionMessage(){
        std::cout<<"[예외 메시지: "<<requireWithdrawAmount<<"는 출금 불가]"<<std::endl;
    }
};

class Account{
private:
    std::string accountNumber;
    int balance;
public:
    Account(std::string  accountNumber, int balance):accountNumber(std::move(accountNumber)), balance(balance){}

    void deposit(int money) throw(DepositException){
        if(money<=0){
            throw DepositException(money);
        }
        balance += money;
    }

    void withdraw(int money) throw(WithdrawException){
        if(money > balance){
            throw WithdrawException(balance);
        }
        balance-= money;
    }

    void showMoney(){
        std::cout<<"잔고: "<<balance<<std::endl;
    }
};


#endif // FIRSTCPP_ATMSIM _H

