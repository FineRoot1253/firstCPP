#ifndef FIRSTCPP_ATMSIM2 _H
#define FIRSTCPP_ATMSIM2 _H
#include <iostream>
#include <string>
#include <utility>

class IAccountException{
public:
    virtual void showExceptionMessage() = 0;
};

class DepositException : public IAccountException {
private:
    int requireDepositAmount;
public:
    DepositException(int requireDepositAmount) : requireDepositAmount(requireDepositAmount){}

    void showExceptionMessage() override {
        std::cout<<"[예외 메시지: "<<requireDepositAmount<<"는 입금 불가]"<<std::endl;
    }
};

class WithdrawException : public IAccountException {
private:
    int requireWithdrawAmount;
public:
    WithdrawException(int requireWithdrawAmount):requireWithdrawAmount(requireWithdrawAmount){}

    void showExceptionMessage() override {
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


#endif // FIRSTCPP_ATMSIM2 _H

